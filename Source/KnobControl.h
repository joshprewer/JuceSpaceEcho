/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "KnobStyling.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]

    KnobControl is a JUCE GUI component that provides a knob and a label GUI element.

    The class controls a given parameter and updates the label value based on the parameters value and name.

                                                                    //[/Comments]
*/
class KnobControl  : public Component,
                     private Timer,
                     public Slider::Listener
{
public:
    //==============================================================================
    KnobControl (RangedAudioParameter& p);
    ~KnobControl();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    enum KnobType { TIME, PERCENTAGE, WET_DRY };
    void setKnobType(KnobType knobType);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void lookAndFeelChanged() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    RangedAudioParameter& parameter;
    KnobLookAndFeel lookAndFeel;
    ComponentAnimator animator;
	KnobType knobType = TIME;

    bool firstLoad = true;

	String formatSliderValue();
    void timerCallback() override;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<KnobBackground> background;
    std::unique_ptr<Slider> knob;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> valueLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KnobControl)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
