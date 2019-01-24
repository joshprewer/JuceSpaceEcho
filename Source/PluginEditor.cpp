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
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (Coursework3AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    delayTimeKnob.reset (new KnobControl (*processor.treeState.getParameter(DelayEffect::delayTimeID)));
    addAndMakeVisible (delayTimeKnob.get());
    delayTimeKnob->setName ("Total Delay Time");

    feedbackKnob.reset (new KnobControl (*processor.treeState.getParameter(DelayEffect::feedbackID)));
    addAndMakeVisible (feedbackKnob.get());
    feedbackKnob->setName ("Feedback");

    mixKnob.reset (new KnobControl (*processor.treeState.getParameter(DelayEffect::mixID)));
    addAndMakeVisible (mixKnob.get());
    mixKnob->setName ("Mix");

    tapMixKnob.reset (new KnobControl (*processor.treeState.getParameter(DelayEffect::tapMixID)));
    addAndMakeVisible (tapMixKnob.get());
    tapMixKnob->setName ("Tap Mix");

    tapTimeKnob.reset (new KnobControl (*processor.treeState.getParameter(DelayEffect::tapDelayTimeID)));
    addAndMakeVisible (tapTimeKnob.get());
    tapTimeKnob->setName ("Tap Time");

    levelMeter.reset (new VUMeterComponent (processor.meterSource));
    addAndMakeVisible (levelMeter.get());
    levelMeter->setName ("new component");

    label.reset (new Label ("new label",
                            TRANS("SPACE  ECHO\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font ("Eurostile", 23.3f, Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (0.103f));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::black);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2.reset (new Label ("new label",
                             TRANS("JP\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font ("Eurostile", 23.3f, Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (-0.249f));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::black);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3.reset (new Label ("new label",
                             TRANS("CW3")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font ("Eurostile", 10.0f, Font::plain).withTypefaceStyle ("Bold").withExtraKerningFactor (-0.009f));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::black);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    cachedImage_BinaryData_aluminum_jpg_1 = ImageCache::getFromMemory (BinaryData::aluminum_jpg, BinaryData::aluminum_jpgSize);
    cachedImage_BinaryData_aluminum_jpg_2 = ImageCache::getFromMemory (BinaryData::aluminum_jpg, BinaryData::aluminum_jpgSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 356);


    //[Constructor] You can add your own custom stuff here..
    delayTimeKnob->setKnobType(KnobControl::TIME);
    tapTimeKnob->setKnobType(KnobControl::PERCENTAGE);
    feedbackKnob->setKnobType(KnobControl::PERCENTAGE);
    mixKnob->setKnobType(KnobControl::WET_DRY);
    tapMixKnob->setKnobType(KnobControl::PERCENTAGE);
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    delayTimeKnob = nullptr;
    feedbackKnob = nullptr;
    mixKnob = nullptr;
    tapMixKnob = nullptr;
    tapTimeKnob = nullptr;
    levelMeter = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 0, y = 0, width = proportionOfWidth (1.0f), height = proportionOfHeight (0.15f);
            //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setTiledImageFill (cachedImage_BinaryData_aluminum_jpg_1,
                         0 - 0 + x,
                         0 - 0 + y,
                         1.0f);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = proportionOfHeight (0.5f) - (proportionOfHeight (0.6996f) / 2), width = proportionOfWidth (1.0f), height = proportionOfHeight (0.6996f);
        Colour fillColour = Colour (0xff181818);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = proportionOfHeight (0.85f), width = proportionOfWidth (1.0f), height = proportionOfHeight (0.15f);
            //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setTiledImageFill (cachedImage_BinaryData_aluminum_jpg_2,
                         0 - 0 + x,
                         0 - proportionOfHeight (0.85f) + y,
                         1.0f);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 0, y = proportionOfHeight (0.1145f), width = proportionOfWidth (1.0f), height = proportionOfHeight (0.02f);
        Colour fillColour = Colour (0xff000f11);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = static_cast<float> (proportionOfWidth (0.25f)), y = static_cast<float> (proportionOfHeight (0.5f) - (proportionOfHeight (0.66f) / 2)), width = static_cast<float> (proportionOfWidth (0.3f)), height = static_cast<float> (proportionOfHeight (0.66f));
        Colour fillColour = Colour (0xff3e4b32);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.0f);
    }

    {
        float x = static_cast<float> (proportionOfWidth (0.57f)), y = static_cast<float> (proportionOfHeight (0.5f) - (proportionOfHeight (0.66f) / 2)), width = static_cast<float> (proportionOfWidth (0.42f)), height = static_cast<float> (proportionOfHeight (0.66f));
        Colour fillColour = Colour (0xff3e4b32);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.0f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    delayTimeKnob->setBounds (proportionOfWidth (0.25f), proportionOfHeight (0.5207f) - (proportionOfHeight (0.598f) / 2), proportionOfWidth (0.2986f), proportionOfHeight (0.598f));
    feedbackKnob->setBounds (proportionOfWidth (0.5689f), proportionOfHeight (0.3348f) - (proportionOfHeight (0.3319f) / 2), proportionOfWidth (0.2095f), proportionOfHeight (0.3319f));
    mixKnob->setBounds (proportionOfWidth (0.7811f), proportionOfHeight (0.3348f) - (proportionOfHeight (0.3319f) / 2), proportionOfWidth (0.2095f), proportionOfHeight (0.3319f));
    tapMixKnob->setBounds (proportionOfWidth (0.5689f), proportionOfHeight (0.6652f) - (proportionOfHeight (0.3319f) / 2), proportionOfWidth (0.2095f), proportionOfHeight (0.3319f));
    tapTimeKnob->setBounds (proportionOfWidth (0.7811f), proportionOfHeight (0.6652f) - (proportionOfHeight (0.3319f) / 2), proportionOfWidth (0.2095f), proportionOfHeight (0.3319f));
    levelMeter->setBounds (proportionOfWidth (0.1257f) - (proportionOfWidth (0.2297f) / 2), proportionOfHeight (0.4986f) - (proportionOfHeight (0.402f) / 2), proportionOfWidth (0.2297f), proportionOfHeight (0.402f));
    label->setBounds (proportionOfWidth (0.0108f), proportionOfHeight (0.0443f), 250, 24);
    label2->setBounds (proportionOfWidth (0.8797f), proportionOfHeight (0.0143f), 50, 25);
    label3->setBounds (proportionOfWidth (0.877f), proportionOfHeight (0.0615f), 60, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="Coursework3AudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="0" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="800" initialHeight="356">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="0 0 100% 15%" fill="image: BinaryData##aluminum_jpg, 1, 0 0"
          hasStroke="0"/>
    <RECT pos="0 50%c 100% 69.957%" fill="solid: ff181818" hasStroke="0"/>
    <RECT pos="0 85% 100% 15%" fill="image: BinaryData##aluminum_jpg, 1, 0 0"
          hasStroke="0"/>
    <RECT pos="0 11.445% 100% 2%" fill="solid: ff000f11" hasStroke="0"/>
    <ROUNDRECT pos="25% 50%c 30% 66%" cornerSize="10.0" fill="solid: ff3e4b32"
               hasStroke="0"/>
    <ROUNDRECT pos="57% 50%c 42% 66%" cornerSize="10.0" fill="solid: ff3e4b32"
               hasStroke="0"/>
  </BACKGROUND>
  <GENERICCOMPONENT name="Total Delay Time" id="4b0378ed6cd02db" memberName="delayTimeKnob"
                    virtualName="" explicitFocusOrder="0" pos="25% 52.074%c 29.865% 59.8%"
                    class="KnobControl" params="*processor.treeState.getParameter(DelayEffect::delayTimeID)"/>
  <GENERICCOMPONENT name="Feedback" id="6f8e2d61483de3d2" memberName="feedbackKnob"
                    virtualName="" explicitFocusOrder="0" pos="56.892% 33.476%c 20.946% 33.19%"
                    class="KnobControl" params="*processor.treeState.getParameter(DelayEffect::feedbackID)"/>
  <GENERICCOMPONENT name="Mix" id="166a4c28b2e2d736" memberName="mixKnob" virtualName=""
                    explicitFocusOrder="0" pos="78.108% 33.476%c 20.946% 33.19%"
                    class="KnobControl" params="*processor.treeState.getParameter(DelayEffect::mixID)"/>
  <GENERICCOMPONENT name="Tap Mix" id="1520e18fdd42ea2c" memberName="tapMixKnob"
                    virtualName="" explicitFocusOrder="0" pos="56.892% 66.524%c 20.946% 33.19%"
                    class="KnobControl" params="*processor.treeState.getParameter(DelayEffect::tapMixID)"/>
  <GENERICCOMPONENT name="Tap Time" id="314af28ba774f550" memberName="tapTimeKnob"
                    virtualName="" explicitFocusOrder="0" pos="78.108% 66.524%c 20.946% 33.19%"
                    class="KnobControl" params="*processor.treeState.getParameter(DelayEffect::tapDelayTimeID)"/>
  <GENERICCOMPONENT name="new component" id="5037fbdc9b4b2e76" memberName="levelMeter"
                    virtualName="" explicitFocusOrder="0" pos="12.568%c 49.857%c 22.973% 40.2%"
                    class="VUMeterComponent" params="processor.meterSource"/>
  <LABEL name="new label" id="e363308752c7c6aa" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="1.081% 4.435% 250 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="SPACE  ECHO&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Eurostile" fontsize="23.30000000000000071054" kerning="0.10299999999999999434"
         bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="ab975f1bfe28c58f" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="87.973% 1.431% 50 25" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="JP&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Eurostile"
         fontsize="23.30000000000000071054" kerning="-0.24899999999999999911"
         bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <LABEL name="new label" id="5553f65ba8724df6" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="87.703% 6.152% 60 24" textCol="ff000000"
         edTextCol="ff000000" edBkgCol="0" labelText="CW3" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Eurostile"
         fontsize="10.0" kerning="-0.00899999999999999932" bold="1" italic="0"
         justification="36" typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
