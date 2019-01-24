#include "../JuceLibraryCode/JuceHeader.h"

/**
    KnobBackground is a JUCE Component class and draws the static background of a knob.
*/

class KnobBackground : public Component
{
public:
    KnobBackground()
    {
    }

    ~KnobBackground()
    {
    }

    void paint (Graphics& g) override
    {
        float diameter = jmin(getWidth(), getHeight());
        float radius = diameter / 2;
        float centreX = getWidth() / 2;
        float centreY = getHeight() / 2;

        int numberTicks = 11;
        float tickLength = radius * 0.1;

        {
            float rotaryStartAngle = parameters.startAngleRadians;
            float rotaryEndAngle = parameters.endAngleRadians;

            float angleDifference = ((rotaryEndAngle - rotaryStartAngle) / (numberTicks - 1));
            Path outerTick;

            for (int i = 0; i < numberTicks; i++) {
                float cosAngle = cos(rotaryStartAngle + angleDifference*i + (MathConstants<float>::halfPi));
                float sinAngle = sin(rotaryStartAngle + angleDifference*i + (MathConstants<float>::halfPi));

                float x1 = centreX + (radius * cosAngle);
                float y1 = centreY - (radius * sinAngle);
                float x2 = centreX + (radius - tickLength) * cosAngle;
                float y2 = centreY - (radius - tickLength) * sinAngle;

                outerTick.addLineSegment(Line<float> (x1, y1, x2, y2), radius * 0.04);
            }

            g.setColour(Colours::silver);
            g.fillPath(outerTick);
        }
        setBufferedToImage(true);
    }

    Slider::RotaryParameters parameters;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KnobBackground)
};

/**
    KnobLookAndFeel is a JUCE LookAndFeel class and draws the movable knob graphics.
*/

class KnobLookAndFeel: public LookAndFeel_V4
{
public:
    void drawRotarySlider(Graphics & g, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = width / 2;
        float centreY = height / 2;

        float tickLength = radius * 0.1;

        {
            float outerDialRadius = radius - tickLength - 5;
            float innerRadius = outerDialRadius * 0.75;
            float rX = centreX - outerDialRadius;
            float rY = centreY - outerDialRadius;
            float innerRx = centreX - innerRadius;
            float innerRy = centreY - innerRadius;
            float angle = rotaryStartAngle + (sliderPosProportional * (rotaryEndAngle - rotaryStartAngle));

            Rectangle<float> dialArea (rX, rY, outerDialRadius * 2, outerDialRadius * 2);
            Rectangle<float> innerDial (innerRx, innerRy, innerRadius * 2, innerRadius * 2);

            g.setColour(Colours::silver);
            g.fillEllipse(dialArea);
            g.fillEllipse(innerDial);
            g.setColour(Colours::darkgrey);

            float lineThickness = 5;

            Path innerDialTick;
            float dialThickness = outerDialRadius * 0.1;
            innerDialTick.addRoundedRectangle(-(dialThickness / 2), -innerRadius, dialThickness, innerRadius * 0.33, 3);

            Path outerDialTick;
            float outerTickY = innerRadius + ((outerDialRadius - innerRadius + (lineThickness / 2)) / 2) + (dialThickness / 2);
            outerDialTick.addRoundedRectangle(-dialThickness / 2, -outerTickY, dialThickness, dialThickness, 3);

            g.fillPath(innerDialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
            g.fillPath(outerDialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
            g.drawEllipse(innerRx, innerRy, innerRadius * 2, innerRadius * 2, lineThickness);
        }
    };
};
