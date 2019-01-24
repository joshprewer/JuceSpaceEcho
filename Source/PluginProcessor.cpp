/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Coursework3AudioProcessor::Coursework3AudioProcessor()
: AudioProcessor (BusesProperties()
                  .withInput  ("Input",  AudioChannelSet::mono(), true)

                  .withOutput ("Output", AudioChannelSet::mono(), true)
                  ),
treeState (*this, nullptr, "parameters", createParameterLayout())
{
}

Coursework3AudioProcessor::~Coursework3AudioProcessor()
{
}

AudioProcessorValueTreeState::ParameterLayout Coursework3AudioProcessor::createParameterLayout()
{
    return {
        std::make_unique<AudioParameterInt> (DelayEffect::delayTimeID,
                                             "Total Delay Time",
                                             1,
                                             1000,
                                             100),
        std::make_unique<AudioParameterFloat> (DelayEffect::tapDelayTimeID,
                                               "Tap Delay",
                                               NormalisableRange<float>(0.0f, 1.0f),
                                               0.5f),
        std::make_unique<AudioParameterFloat> (DelayEffect::tapMixID,
                                               "Tap Mix",
                                               NormalisableRange<float>(0.0f, 1.0f),
                                               0.5f),
        std::make_unique<AudioParameterFloat> (DelayEffect::feedbackID,
                                               "Feedback",
                                               NormalisableRange<float>(0.0f, 1.0f),
                                               0.5f),
        std::make_unique<AudioParameterFloat> (DelayEffect::mixID,
                                               "Mix",
                                               NormalisableRange<float>(0.0f, 1.0f),
                                               0.5f)
    };
}

//==============================================================================
const String Coursework3AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Coursework3AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Coursework3AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Coursework3AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Coursework3AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Coursework3AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Coursework3AudioProcessor::getCurrentProgram()
{
    return 0;
}

void Coursework3AudioProcessor::setCurrentProgram (int index)
{
}

const String Coursework3AudioProcessor::getProgramName (int index)
{
    return {};
}

void Coursework3AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Coursework3AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    effect = new DelayEffect(treeState, sampleRate);
}

void Coursework3AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool Coursework3AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const 
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::mono())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}

void Coursework3AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        effect->applyEffect(buffer);
        meterSource.measureBuffer(buffer);
    }
}

//==============================================================================
bool Coursework3AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Coursework3AudioProcessor::createEditor()
{
    return new PluginEditor (*this);
}

//==============================================================================
void Coursework3AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Coursework3AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Coursework3AudioProcessor();
}
