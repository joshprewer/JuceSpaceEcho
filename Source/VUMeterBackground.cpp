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

#include "VUMeterBackground.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VUMeterBackground::VUMeterBackground ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

VUMeterBackground::~VUMeterBackground()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VUMeterBackground::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    {
        float x = 0.0f, y = 0.0f, width = static_cast<float> (proportionOfWidth (1.0f)), height = static_cast<float> (proportionOfHeight (1.0f));
        Colour fillColour = Colour (0xff424242);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 15.5f);
    }

    {
        int x = proportionOfWidth (0.5f) - (200 / 2), y = proportionOfHeight (0.7f) - (30 / 2), width = 200, height = 30;
        String text (TRANS("PC"));
        Colour fillColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("Eurostile", 20.0f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        float x = 0, y = 0;
        Colour fillColour = Colour (0xffa0a52a);
        Colour strokeColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, AffineTransform::translation(x, y));
        g.setColour (strokeColour);
        g.strokePath (internalPath1, PathStrokeType (5.0f), AffineTransform::translation(x, y));
    }

    {
        int x = proportionOfWidth (0.04f), y = proportionOfHeight (0.31f), width = proportionOfWidth (0.14f), height = proportionOfHeight (0.13f);
        Colour fillColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.2f), y = proportionOfHeight (0.31f), width = proportionOfWidth (0.17f), height = proportionOfHeight (0.13f);
        Colour fillColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.39f), y = proportionOfHeight (0.31f), width = proportionOfWidth (0.2f), height = proportionOfHeight (0.13f);
        Colour fillColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.76f), y = proportionOfHeight (0.31f), width = proportionOfWidth (0.2f), height = proportionOfHeight (0.13f);
        Colour strokeColour = Colours::red;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 3);

    }

    {
        int x = proportionOfWidth (0.6108f), y = proportionOfHeight (0.31f), width = proportionOfWidth (0.13f), height = proportionOfHeight (0.13f);
        Colour fillColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 0, y = 0;
        Colour fillColour = Colour (0xffa0a52a);
        Colour strokeColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath2, AffineTransform::translation(x, y));
        g.setColour (strokeColour);
        g.strokePath (internalPath2, PathStrokeType (5.0f), AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        Colour fillColour = Colour (0xffa0a52a);
        Colour strokeColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath3, AffineTransform::translation(x, y));
        g.setColour (strokeColour);
        g.strokePath (internalPath3, PathStrokeType (5.0f), AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        Colour fillColour = Colour (0xffa0a52a);
        Colour strokeColour = Colours::green;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath4, AffineTransform::translation(x, y));
        g.setColour (strokeColour);
        g.strokePath (internalPath4, PathStrokeType (5.0f), AffineTransform::translation(x, y));
    }

    {
        float x = 0, y = 0;
        Colour fillColour = Colour (0xffa0a52a);
        Colour strokeColour = Colours::red;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath5, AffineTransform::translation(x, y));
        g.setColour (strokeColour);
        g.strokePath (internalPath5, PathStrokeType (5.0f), AffineTransform::translation(x, y));
    }

    {
        float x = static_cast<float> (proportionOfWidth (0.5f) - (proportionOfWidth (0.05f) / 2)), y = static_cast<float> (proportionOfHeight (1.0f) - (proportionOfHeight (0.05f) / 2)), width = static_cast<float> (proportionOfWidth (0.05f)), height = static_cast<float> (proportionOfHeight (0.05f));
        Colour fillColour = Colours::silver;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillEllipse (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    setBufferedToImage(true);
    //[/UserPaint]
}

void VUMeterBackground::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    internalPath1.clear();
    internalPath1.startNewSubPath (static_cast<float> (proportionOfWidth (0.18f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath1.lineTo (static_cast<float> (proportionOfWidth (0.04f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath1.closeSubPath();

    internalPath2.clear();
    internalPath2.startNewSubPath (static_cast<float> (proportionOfWidth (0.37f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath2.lineTo (static_cast<float> (proportionOfWidth (0.2f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath2.closeSubPath();

    internalPath3.clear();
    internalPath3.startNewSubPath (static_cast<float> (proportionOfWidth (0.59f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath3.lineTo (static_cast<float> (proportionOfWidth (0.39f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath3.closeSubPath();

    internalPath4.clear();
    internalPath4.startNewSubPath (static_cast<float> (proportionOfWidth (0.74f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath4.lineTo (static_cast<float> (proportionOfWidth (0.61f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath4.closeSubPath();

    internalPath5.clear();
    internalPath5.startNewSubPath (static_cast<float> (proportionOfWidth (0.96f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath5.lineTo (static_cast<float> (proportionOfWidth (0.76f)), static_cast<float> (proportionOfHeight (0.5f)));
    internalPath5.closeSubPath();

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

<JUCER_COMPONENT documentType="Component" className="VUMeterBackground" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="0" initialWidth="300" initialHeight="200">
  <BACKGROUND backgroundColour="323e44">
    <ROUNDRECT pos="0 0 100% 100%" cornerSize="15.5" fill="solid: ff424242"
               hasStroke="0"/>
    <TEXT pos="50%c 70%c 200 30" fill="solid: ff008000" hasStroke="0" text="PC"
          fontname="Eurostile" fontsize="20.0" kerning="0.0" bold="0" italic="0"
          justification="36"/>
    <PATH pos="0 0 100 100" fill="solid: ffa0a52a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff008000" nonZeroWinding="1">s 18% 50% l 4% 50% x</PATH>
    <RECT pos="4% 31% 14% 13%" fill="solid: ff008000" hasStroke="0"/>
    <RECT pos="20% 31% 17% 13%" fill="solid: ff008000" hasStroke="0"/>
    <RECT pos="39% 31% 20% 13%" fill="solid: ff008000" hasStroke="0"/>
    <RECT pos="76% 31% 20% 13%" fill="solid: ffe4c4" hasStroke="1" stroke="3, mitered, butt"
          strokeColour="solid: ffff0000"/>
    <RECT pos="61.081% 31% 13% 13%" fill="solid: ff008000" hasStroke="0"/>
    <PATH pos="0 0 100 100" fill="solid: ffa0a52a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff008000" nonZeroWinding="1">s 37% 50% l 20% 50% x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ffa0a52a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff008000" nonZeroWinding="1">s 59% 50% l 39% 50% x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ffa0a52a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ff008000" nonZeroWinding="1">s 74% 50% l 61% 50% x</PATH>
    <PATH pos="0 0 100 100" fill="solid: ffa0a52a" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: ffff0000" nonZeroWinding="1">s 96% 50% l 76% 50% x</PATH>
    <ELLIPSE pos="50%c 100%c 5% 5%" fill="solid: ffc0c0c0" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
