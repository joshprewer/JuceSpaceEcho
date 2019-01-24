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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "KnobControl.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
KnobControl::KnobControl (RangedAudioParameter& p)
    : parameter(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    background.reset (new KnobBackground());
    addAndMakeVisible (background.get());
    background->setName ("background");

    knob.reset (new Slider ("Knob"));
    addAndMakeVisible (knob.get());
    knob->setRange (0, 1, 0);
    knob->setSliderStyle (Slider::RotaryVerticalDrag);
    knob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    knob->addListener (this);

    label.reset (new Label ("new label",
                            TRANS("label text")));
    addAndMakeVisible (label.get());
    label->setFont (Font ("Eurostile", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredTop);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    valueLabel.reset (new Label ("new label",
                                 TRANS("label text")));
    addAndMakeVisible (valueLabel.get());
    valueLabel->setFont (Font ("Eurostile", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    valueLabel->setJustificationType (Justification::centredTop);
    valueLabel->setEditable (false, false, false);
    valueLabel->setColour (TextEditor::textColourId, Colours::black);
    valueLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    knob->setLookAndFeel(&lookAndFeel);
    knob->setValue(parameter.getDefaultValue());
    label->setText(parameter.label, dontSendNotification);
    background->parameters = knob->getRotaryParameters();
    animator.fadeOut(valueLabel.get(), 0);
    //[/Constructor]
}

KnobControl::~KnobControl()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    background = nullptr;
    knob = nullptr;
    label = nullptr;
    valueLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void KnobControl::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void KnobControl::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    label->setText(getName(), NotificationType::dontSendNotification);
    //[/UserPreResize]

    background->setBounds (0, proportionOfHeight (0.03f), proportionOfWidth (1.0f), proportionOfHeight (0.7997f));
    knob->setBounds (0, proportionOfHeight (0.03f), proportionOfWidth (1.0f), proportionOfHeight (0.7997f));
    label->setBounds (proportionOfWidth (0.5f) - (proportionOfWidth (1.0f) / 2), proportionOfHeight (0.8269f), proportionOfWidth (1.0f), proportionOfHeight (0.1731f));
    valueLabel->setBounds (proportionOfWidth (0.5f) - (proportionOfWidth (1.0f) / 2), proportionOfHeight (0.8269f), proportionOfWidth (1.0f), proportionOfHeight (0.1731f));
    //[UserResized] Add your own custom resize handling here..

    //[/UserResized]
}

void KnobControl::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    if (firstLoad) {

        firstLoad = false;
        return;
    }

    if (!isTimerRunning())
    {
        animator.fadeOut(label.get(), 100);
        animator.fadeIn(valueLabel.get(), 200);
    }
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == knob.get())
    {
        //[UserSliderCode_knob] -- add your slider handling code here..
        parameter.setValueNotifyingHost(knob->getValue());
        valueLabel->setText(formatSliderValue(), NotificationType::dontSendNotification);
        startTimer(1000);
        //[/UserSliderCode_knob]
    }

    //[UsersliderValueChanged_Post]

    //[/UsersliderValueChanged_Post]
}

void KnobControl::lookAndFeelChanged()
{
    //[UserCode_lookAndFeelChanged] -- Add your code here...
    //[/UserCode_lookAndFeelChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void KnobControl::setKnobType(KnobType knobType)
{
    this->knobType = knobType;
}

void KnobControl::timerCallback()
{
    animator.fadeOut(valueLabel.get(), 200);
    label->setText(getName(), NotificationType::dontSendNotification);
    animator.fadeIn(label.get(), 500);

    stopTimer();
}

String KnobControl::formatSliderValue()
{
    switch (knobType)
    {
        case PERCENTAGE:
            return String(round(parameter.getValue() * 100)) + "%";
        case TIME:
            return parameter.getCurrentValueAsText() + " ms";
        case WET_DRY:
            auto value = round(parameter.getValue() * 100);
            if (value == 0){
                return "Dry";
            } else if (value == 100) {
                return "Wet";
            } else {
                return String(value) + "%";
            }
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="KnobControl" componentName=""
                 parentClasses="public Component, private Timer" constructorParams="RangedAudioParameter&amp; p"
                 variableInitialisers="parameter(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.33" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <METHODS>
    <METHOD name="lookAndFeelChanged()"/>
  </METHODS>
  <BACKGROUND backgroundColour="8ace"/>
  <GENERICCOMPONENT name="background" id="5face305cc371ef4" memberName="background"
                    virtualName="" explicitFocusOrder="0" pos="0 3.004% 100% 79.971%"
                    class="KnobBackground" params=""/>
  <SLIDER name="Knob" id="b44e08c098eea9c8" memberName="knob" virtualName=""
          explicitFocusOrder="0" pos="0 3.004% 100% 79.971%" min="0.0"
          max="1.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="1da6bae92892df57" memberName="label" virtualName="Label"
         explicitFocusOrder="0" pos="50%c 82.69% 100% 17.31%" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Eurostile" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="12"/>
  <LABEL name="new label" id="3851a603f5b91e17" memberName="valueLabel"
         virtualName="Label" explicitFocusOrder="0" pos="50%c 82.69% 100% 17.31%"
         edTextCol="ff000000" edBkgCol="0" labelText="label text" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Eurostile"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="12"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
