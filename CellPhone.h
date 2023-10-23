#pragma once

#include "LeakedObjectDetector.h"

struct CellPhone
{
    CellPhone();
    ~CellPhone();

    struct Case
    {
        Case();
        ~Case();

        std::string color;
        std::string brand{"Spigen"};
        float cost{12.99f};
        std::string features{"kickstand"};
        bool isPadded{true};

        void wrapPhone() const;
        void providePadding() const;
        void preventScratches() const;
        void printCaseDetails() const;

        JUCE_LEAK_DETECTOR(Case)
    };

    std::string color;
    std::string dataProvider{"AT&T"};
    std::string brand{"Samsung"};
    std::string processor{"Qualcomm 865"};
    int ramAmount{12};

    void makeCall() const;
    void browseWeb() const;
    void playMusic() const;

    void changePhoneCase(const Case& phoneCase) const;

    void printCellPhoneDetails() const;

    JUCE_LEAK_DETECTOR(CellPhone)
};
