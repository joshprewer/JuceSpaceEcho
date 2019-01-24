#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
    FIRLowpass is a class used for filtering audio based on a cutoff frequency, the sampling rate and a window

    Filtering can be done block by block or sample by sample.
    Different windows a give different filter characteristics
*/

class FIRLowpass
{
public:
    // Different types of windows available
    enum Window {
        RECTANGULAR,
        HANN,
        HAMMING,
        BLACKMAN,
        BARTLETT
    };
    
    FIRLowpass(double cutoff, int sr, enum Window window);
    ~FIRLowpass();

    // filterSamples(float *audioBuffer, int count) will apply a filter to the samples in audioBuffer. The integer count should be the number of samples in audioBuffer to process
    void filterSamples(float *audioBuffer, int count);
    double singleSample(float sample);

private:
    double cutoff;
    int sampleRate;
    enum Window window;
    double *coeffs;

    float* delayBuffer;
    int writePoint = 0;

    const int DELAY_BUFFER_SIZE = 127;

    // getOutput(float *delayBuffer, double *coeffs, int index) returns a single sample ouput of the FIR filter
    float getOutput(float *delayBuffer, double *coeffs, int index);
    // *sincCoeffs(double cutoff, int fs, enum Window window) returns an array filled with sinc values centered about the middle of the array
    void fillSincCoeffs(double* array);
    // windowValue(enum Window window, int i) returns a value between 0 and 1 based on a window function and index in window
    double windowValue(enum Window window, int i);
};
