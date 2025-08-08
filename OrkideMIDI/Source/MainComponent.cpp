#include "MainComponent.h"

MainComponent::MainComponent()
{
    midiOut = juce::MidiOutput::openDevice(juce::MidiOutput::getDefaultDeviceIndex());
    addAndMakeVisible(playButton);
    playButton.onClick = [this]() { playChord(); };
    setSize (300, 200);
}

MainComponent::~MainComponent() = default;

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void MainComponent::resized()
{
    playButton.setBounds (getLocalBounds().reduced (40));
}

void MainComponent::playChord()
{
    if (!midiOut)
        return;

    auto notes = chordEngine.getCMajorChord();
    for (auto note : notes)
        midiOut->sendMessageNow (juce::MidiMessage::noteOn (1, note, (juce::uint8)100));

    juce::Timer::callAfterDelay (200, [this, notes]
    {
        if (!midiOut)
            return;
        for (auto note : notes)
            midiOut->sendMessageNow (juce::MidiMessage::noteOff (1, note));
    });
}
