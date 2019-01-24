#include "FIRLowpass.h"

FIRLowpass::FIRLowpass(double cutoff, int sr, enum Window window)
{
    this->cutoff = cutoff;
    this->sampleRate = sr;
    this->window = window;
    this->coeffs = new double[DELAY_BUFFER_SIZE + 1]();
    this->delayBuffer = new float[DELAY_BUFFER_SIZE]();

    fillSincCoeffs(coeffs);
}

FIRLowpass::~FIRLowpass()
{
}

void FIRLowpass::filterSamples(float *audioBuffer, int count)
{
    for (int i = 0; i < count; i++) {
        audioBuffer[i] = singleSample(audioBuffer[i]);
    }
}

double FIRLowpass::singleSample(float sample)
{
    delayBuffer[writePoint % DELAY_BUFFER_SIZE] = sample;
    sample = getOutput(delayBuffer, coeffs, writePoint);
    writePoint++;

    return sample;
}

float FIRLowpass::getOutput(float *delayBuffer, double *coeffs, int index)
{
    float output = 0;

    for (int i = 0; i < DELAY_BUFFER_SIZE; i++) {
        output += coeffs[i] * delayBuffer[(index - i + DELAY_BUFFER_SIZE) % DELAY_BUFFER_SIZE];
    }
    
    return output;
}

void FIRLowpass::fillSincCoeffs(double* array)
{
    double omega = 2 * M_PI * cutoff / sampleRate;
    int centeredI = 0 - ((DELAY_BUFFER_SIZE - 1) / 2.0);

    double coeffSum = 0;
    for (int i = 0; i < DELAY_BUFFER_SIZE; i++) {
        if (centeredI == 0 ) {
            coeffs[i] = omega / M_PI;
        } else {
            coeffs[i] = (sin(omega * centeredI) * windowValue(window, i)) / (centeredI * M_PI) ;
        }

        coeffSum += coeffs[i];
        centeredI++;
    }

    for (int i = 0; i < DELAY_BUFFER_SIZE; i++) {
        coeffs[i] /= coeffSum;
    }
}

double FIRLowpass::windowValue(enum Window window, int i)
{
    switch (window) {
        case RECTANGULAR:
            return 1;
        case BARTLETT:
            return (1 - 2*abs(i - (DELAY_BUFFER_SIZE - 1)/2)/(DELAY_BUFFER_SIZE - 1));
        case HANN:
            return (0.5 - 0.5*cos(2*M_PI*i/DELAY_BUFFER_SIZE));
        case HAMMING:
            return (0.54 - 0.46*cos(2*M_PI*i/DELAY_BUFFER_SIZE));
        case BLACKMAN:
            return (0.42 - 0.5*cos(2*M_PI*i/DELAY_BUFFER_SIZE) + 0.08*cos(4*M_PI*i/DELAY_BUFFER_SIZE));
    }
}
