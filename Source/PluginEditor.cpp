/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PitchShifterAudioProcessorEditor::PitchShifterAudioProcessorEditor (PitchShifterAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{ 
    // Create labels
    semitonesLabel.setText("Semitone Shift", juce::NotificationType::dontSendNotification);
    semitonesLabel.setColour(juce::Label::textColourId, juce::Colours::black);
    addAndMakeVisible(semitonesLabel);

    // Create sliders
    semitonesSlider.setColour(juce::Slider::trackColourId, juce::Colours::orangered);
    semitonesSlider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 60, 20);
    semitonesSlider.setColour(juce::Slider::textBoxBackgroundColourId, juce::Colours::white);
    semitonesSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
    addAndMakeVisible(semitonesSlider);
    semitonesAttachment.reset(new SliderAttachment(valueTreeState, "SemiTones", semitonesSlider));

    setSize(TitleWidth + 2 * Margin, TitleHeight + SliderWidth + 3 * Margin);
}

PitchShifterAudioProcessorEditor::~PitchShifterAudioProcessorEditor()
{
}

//==============================================================================
void PitchShifterAudioProcessorEditor::paint (juce::Graphics& g)
{
    int x = Margin;
    int y = 0;
    g.fillAll(juce::Colours::burlywood);
    g.setColour(juce::Colours::black);
    g.setFont(24.0f);
    g.drawFittedText("Audio Pitch Shifter", x, y, TitleWidth, TitleHeight, juce::Justification::centred, 1);

}

void PitchShifterAudioProcessorEditor::resized()
{
    int x = Margin;
    int y = TitleHeight + Margin;
    semitonesLabel.setBounds(x, y, LabelWidth, LabelHeight);
    x += LabelWidth;
    semitonesSlider.setBounds(x, y, SliderLength, SliderWidth);
}
