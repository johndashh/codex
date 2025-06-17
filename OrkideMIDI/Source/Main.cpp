#include <JuceHeader.h>
#include "MainComponent.h"

class MainWindow : public juce::DocumentWindow
{
public:
    MainWindow() : DocumentWindow("OrkideMIDI",
                                   juce::Colours::lightgrey,
                                   DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar(true);
        setContentOwned(new MainComponent(), true);
        centreWithSize(getWidth(), getHeight());
        setResizable(true, true);
        setVisible(true);
    }

    void closeButtonPressed() override
    {
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }
};

class OrkideMIDIApplication : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override { return "OrkideMIDI"; }
    const juce::String getApplicationVersion() override { return "1.0"; }
    void initialise(const juce::String&) override
    {
        mainWindow.reset(new MainWindow());
    }
    void shutdown() override { mainWindow = nullptr; }
private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(OrkideMIDIApplication)
