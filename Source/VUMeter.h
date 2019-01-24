#include "../JuceLibraryCode/JuceHeader.h"
#include "VUMeterBackground.h"
#include "VUMeterNeedle.h"

/**
    VUMeter is a JUCE class that provides the logic for a VUMeter.
*/

class VUMeter
{
public:
    VUMeter();
    ~VUMeter();

    void measureBuffer(AudioSampleBuffer& buffer);
    float getValue();

private:
    LinearSmoothedValue<float> gradientTime;
    static const int REFRESH_RATE = 60;
    static constexpr float RAMP_TIME_S = 0.15;

    // This controls how many buffers of audio the meter should consider
    static const int RMS_HISTORY_LENGTH = 8;

    AudioSampleBuffer test;

    double rmsHistory[RMS_HISTORY_LENGTH] = { 0.0 };
    double rmsSum = 0.0;
    int rmsWrite = 0;

    int sr;
    int writePoint = 0;
};

/**
    VUMeterComponent is a JUCE component that utilises a VUMeter class and updates the subcomponents.
*/

class VUMeterComponent : public Component, private Timer
{
public:
    VUMeterComponent(VUMeter& s) : source(s) {
        startTimerHz(60);
        addAndMakeVisible(background);
        addAndMakeVisible(needle);
    }

    ~VUMeterComponent()
    {
    }

    void resized() override
    {
        background.setBounds(0, 0, getWidth(), getHeight());
        needle.setBounds(0, 0, getWidth(), getHeight());
    };


    void setSource(VUMeter s) {
        source = s;
    };

private:
    VUMeter& source;
    VUMeterBackground background;
    VUMeterNeedle needle;

    void timerCallback() override
    {
        needle.needlePos = source.getValue();
        needle.repaint();
    }
};
