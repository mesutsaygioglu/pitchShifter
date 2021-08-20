/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"


typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

//==============================================================================
/**
*/
class PitchShifterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    enum
    {
        TitleWidth = 400,
        TitleHeight = 50,
        LabelWidth = 100,
        LabelHeight = 50,
        SliderWidth = 50,
        SliderLength = 300,
        Margin = 50
    };
    PitchShifterAudioProcessorEditor (PitchShifterAudioProcessor&, juce::AudioProcessorValueTreeState&);
    ~PitchShifterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
    PitchShifterAudioProcessor& processor;

    juce::AudioProcessorValueTreeState& valueTreeState;

    juce::Label semitonesLabel;
    juce::Slider semitonesSlider;
    std::unique_ptr<SliderAttachment> semitonesAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchShifterAudioProcessorEditor)
};
