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
#include "KnobControl.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginEditor  : public AudioProcessorEditor
{
public:
    //==============================================================================
    PluginEditor (Coursework3AudioProcessor& p);
    ~PluginEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Coursework3AudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<KnobControl> delayTimeKnob;
    std::unique_ptr<KnobControl> feedbackKnob;
    std::unique_ptr<KnobControl> mixKnob;
    std::unique_ptr<KnobControl> tapMixKnob;
    std::unique_ptr<KnobControl> tapTimeKnob;
    std::unique_ptr<VUMeterComponent> levelMeter;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    Image cachedImage_BinaryData_aluminum_jpg_1;
    Image cachedImage_BinaryData_aluminum_jpg_2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
