#pragma once
#include "LeakedObjectDetector.h"

struct Screen
{
    Screen();
    ~Screen();

    std::string brand;
    int refreshRate{75};
    int pixelsX{920};
    int pixelsY{560};
    std::string connectors{"HDMI"};

    void displayImages() const;
    void adjustColorSettings() const;
    void adjustRefreshRate() const;

    int setPixels(int, int) const;

    void printScreenDetails() const;

    JUCE_LEAK_DETECTOR(Screen)
};
