#pragma once

#include "LeakedObjectDetector.h"
#include "Screen.h"

struct Monitor
{
    Monitor();
    ~Monitor();

    Screen screen;

    void powerOn() const;
    void adjustBrightness() const;

    JUCE_LEAK_DETECTOR(Monitor)
};
