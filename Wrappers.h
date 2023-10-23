#pragma once

#include "LeakedObjectDetector.h"

struct Car;
struct CellPhone;
struct Screen;
struct Person;
struct Monitor;

struct CarWrapper
{
    Car* carPtr{nullptr};

    CarWrapper(Car* ptr);
    ~CarWrapper();
    JUCE_LEAK_DETECTOR(CarWrapper)
};

struct CellPhoneWrapper
{
    CellPhone* cellPhonePtr{nullptr};

    CellPhoneWrapper(CellPhone* ptr);
    ~CellPhoneWrapper();
    JUCE_LEAK_DETECTOR(CellPhoneWrapper)
};

struct ScreenWrapper
{
    Screen* screenPtr{nullptr};

    ScreenWrapper(Screen* ptr);
    ~ScreenWrapper();
    JUCE_LEAK_DETECTOR(ScreenWrapper)
};

struct PersonWrapper
{
    Person* personPtr{nullptr};

    PersonWrapper(Person* ptr);
    ~PersonWrapper();
    JUCE_LEAK_DETECTOR(PersonWrapper)
};

struct MonitorWrapper
{
    Monitor* monitorPtr{nullptr};

    MonitorWrapper(Monitor* ptr);
    ~MonitorWrapper();
    JUCE_LEAK_DETECTOR(MonitorWrapper)
};
