#pragma once

#include "LeakedObjectDetector.h"
#include "Car.h"
#include "CellPhone.h"

struct Person
{
    Person();
    ~Person();

    Car car;
    CellPhone phone;

    void driveCar(std::string, std::string) const;
    void placeCall(const Person&) const;

    JUCE_LEAK_DETECTOR(Person)
};
