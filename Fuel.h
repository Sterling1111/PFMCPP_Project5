#pragma once

#include "LeakedObjectDetector.h"

struct Fuel
{
    Fuel();
    ~Fuel();

    int octaneRating;
    float costPerGallon{4.55f};
    std::string CountryOfOrigin{"Saudi Arabia"};
    std::string distributer{"Shell"};
    std::string color{"clear"};

    void burn() const;
    void smell() const;
    void flow() const;

    float buyGas(float) const;

    void printFuelDetails() const;

    JUCE_LEAK_DETECTOR(Fuel)
};