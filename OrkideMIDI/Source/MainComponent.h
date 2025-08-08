#pragma once

#include <JuceHeader.h>
#include "ChordEngine.h"

class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    void playChord();

    ChordEngine chordEngine;
    std::unique_ptr<juce::MidiOutput> midiOut;
    juce::TextButton playButton {"Play C Major"};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

