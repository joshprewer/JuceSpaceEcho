#include "DelayEffect.h"

DelayEffect::DelayEffect(AudioProcessorValueTreeState& p, int sr) : parameters(p),
filterOne(FILTER_CUTOFF, sr, FIRLowpass::HAMMING), filterTwo(FILTER_CUTOFF, sr, FIRLowpass::HAMMING)
{
    sampleRate = sr;
    bufferSize = sampleRate * MAX_DELAY_S + 1;
    delayBuffer = new float[bufferSize]();

    float smoothingTime = 0.1;
    smoothedDelayOne.reset(sampleRate, smoothingTime);
    smoothedDelayTwo.reset(sampleRate, smoothingTime);
    smoothedFeedback.reset(sampleRate, smoothingTime);
    smoothedMix.reset(sampleRate, smoothingTime);
    smoothedTapMix.reset(sampleRate, smoothingTime);

    parameters.addParameterListener(delayTimeID, this);
    parameters.addParameterListener(tapDelayTimeID, this);
    parameters.addParameterListener(feedbackID, this);
    parameters.addParameterListener(tapMixID, this);
    parameters.addParameterListener(mixID, this);

    // Initial update of parameters
    parameterChanged("", 0);
}

DelayEffect::~DelayEffect()
{
}

void DelayEffect::applyEffect(AudioSampleBuffer& buffer)
{
    auto bufferReadPointer = buffer.getReadPointer(0);
    auto bufferWritePointer = buffer.getWritePointer(0);

    for (int i = 0; i < buffer.getNumSamples(); i++) {
        float readPointOne = fmodf(writePoint - smoothedDelayOne.getNextValue() + bufferSize, bufferSize);
        float readPointTwo = fmodf(writePoint - smoothedDelayTwo.getNextValue() + bufferSize, bufferSize);

        delayBuffer[writePoint] = bufferReadPointer[i] + prevSample * smoothedFeedback.getNextValue();

        float tapMix = smoothedTapMix.getNextValue();
        float tapOne = tapMix * filterOne.singleSample(interpolateDelayBufferAt(readPointOne));
        float tapTwo = (1 - tapMix) * filterTwo.singleSample(interpolateDelayBufferAt(readPointTwo));

        prevSample = tapOne + tapTwo;

        float effectMix = smoothedMix.getNextValue();
        bufferWritePointer[i] = effectMix * prevSample + (1 - effectMix) * bufferReadPointer[i];

        writePoint = (writePoint + 1) % bufferSize;
    }
}

void DelayEffect::parameterChanged(const String &parameterID, float newValue)
{
    float totalDelayTime = *parameters.getRawParameterValue(delayTimeID) * sampleRate / 1000.0f;

    smoothedDelayOne.setValue(totalDelayTime * *parameters.getRawParameterValue(tapDelayTimeID));
    smoothedDelayTwo.setValue(totalDelayTime);
    smoothedFeedback.setValue(*parameters.getRawParameterValue(feedbackID));
    smoothedTapMix.setValue(*parameters.getRawParameterValue(tapMixID));
    smoothedMix.setValue(*parameters.getRawParameterValue(mixID));
}

float DelayEffect::interpolateDelayBufferAt(float readPoint)
{
    int readPos = floor(readPoint);
    float frac = readPoint - readPos;
    float nextSample = delayBuffer[(readPos + 1) % bufferSize];

    return delayBuffer[readPos] + frac * (nextSample - delayBuffer[readPos]);
}

const String DelayEffect::delayTimeID = "delayTime";
const String DelayEffect::tapDelayTimeID = "tapDelayTime";
const String DelayEffect::tapMixID = "tapMix";
const String DelayEffect::feedbackID = "feedback";
const String DelayEffect::mixID = "mix";
