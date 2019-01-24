#include "../JuceLibraryCode/JuceHeader.h"
#include "FIRLowpass.h"

/**
    DelayEffect: A JUCE class to that applies a delay effect to an audio buffer.

    Total delay time, variable delay time, feedback level, delay tap mix, wet/dry mix are controlled
    by associated parameters in a supplied AudioProcessorValueTreeState.

    The parameterIDs to use in a AudioProcessorValueTreeState are given in this class.
*/

class DelayEffect : private AudioProcessorValueTreeState::Listener
{
public:
    // Constructer: Class requires a AudioProcessorValueState tree and sample rate
    DelayEffect(AudioProcessorValueTreeState& p, int sr);
    ~DelayEffect();

    // applyEffect will apply the delay effect to the given buffer
    void applyEffect(AudioSampleBuffer& buffer);

    // ParameterIDs: These IDs must be implemented in the AudioProcessorValueTreeState p to control the effect
    const static String delayTimeID;
    const static String tapDelayTimeID;
    const static String feedbackID;
    const static String tapMixID;
    const static String mixID;;

private:
    AudioProcessorValueTreeState& parameters;

    int sampleRate;
    int bufferSize;

    int writePoint = 0;
    float prevSample = 0;

    // The filter cutoff frequency in Hz
    const int FILTER_CUTOFF = 2000;
    // The maximum delay time of the buffer in seconds
    const int MAX_DELAY_S = 1;

    // The smoothed parameter values are used to alleviate audio artifacts
    LinearSmoothedValue<float> smoothedDelayOne;
    LinearSmoothedValue<float> smoothedDelayTwo;
    LinearSmoothedValue<float> smoothedFeedback;
    LinearSmoothedValue<float> smoothedMix;
    LinearSmoothedValue<float> smoothedTapMix;

    float* delayBuffer;

    FIRLowpass filterOne;
    FIRLowpass filterTwo;

    // interpolateDelayBufferAt(float readPoint) interpolates the values in buffer about the float readPoint
    float interpolateDelayBufferAt(float readPoint);

    // parameterChanged is a method inherited from the AudioProcessorValueTreeState::Listener class
    // This is called when a parameter with the String IDs is changed
    // Calling the method will update the target value for all of the class parameters
    void parameterChanged(const String &parameterID, float newValue) override;
};
