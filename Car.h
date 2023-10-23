#pragma once

#include "LeakedObjectDetector.h"

struct Car
{
    Car();
    ~Car();

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

    std::string carColor;
    int horsePower{200};
    float cost{32'000.f};
    std::string brand{"Honda"};
    int year{1997};

    void playMusic() const;
    void drive() const;
    void putFuelInCar(const Fuel& fule) const;
    float consumeFuel() const; // return the fuel consumed in gallon
    void printCarDetails() const;

    JUCE_LEAK_DETECTOR(Car)
};
