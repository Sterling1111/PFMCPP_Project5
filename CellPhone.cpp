#include "CellPhone.h"

CellPhone::CellPhone() : color{"red"}
{
    std::cout << "CellPhone being constructed" << std::endl;
}

CellPhone::~CellPhone()
{
    std::cout << "CellPhone being destructed" << std::endl;
}

void CellPhone::makeCall() const
{
    std::cout << color << std::endl;
    std::cout << "Making call...\n";

    int callTime{5};

    for(int i = 1; i <= callTime; ++i)
    {
        std::cout << i << " minutes on the call" << std::endl;
    }

    std::cout << "call ended" << std::endl;
}

void CellPhone::browseWeb() const
{
    std::cout << "Browsing web...\n";
}

void CellPhone::playMusic() const
{
    std::cout << "Playing music...\n";
}

void CellPhone::changePhoneCase(const CellPhone::Case& newPhoneCase) const
{
    std::cout << "Changing phone case to " << newPhoneCase.brand << "...\n";
}

void CellPhone::printCellPhoneDetails() const
{
    std::cout << "CellPhone details: \n"
          << "Color: " << this->color << "\n"
          << "Data Provider: " << this->dataProvider << "\n"
          << "Brand: " << this->brand << "\n"
          << "Processor: " << this->processor << "\n"
          << "RAM Amount: " << this->ramAmount << " GB\n";
}

CellPhone::Case::Case() 
{
    std::cout << "Case being constructed" << std::endl;
}

CellPhone::Case::~Case()
{
    std::cout << "Case being destructed" << std::endl;
}

void CellPhone::Case::wrapPhone() const
{
    std::cout << color << std::endl;
    std::cout << "Wrapping phone...\n";
}

void CellPhone::Case::providePadding() const
{
    std::cout << "Providing padding...\n";
}

void CellPhone::Case::preventScratches() const
{
    std::cout << "Preventing scratches...\n";

    for(int i = 0; i < 5; ++i)
    {
        std::cout << i << " scratches prevented" << std::endl;
    }
}

void CellPhone::Case::printCaseDetails() const
{
    std::cout << "Phone Case details: \n"
          << "Color: " << this->color << "\n"
          << "Brand: " << this->brand << "\n"
          << "Cost: " << this->cost << " $\n"
          << "Features: " << this->features << "\n"
          << "Is Padded? " << (this->isPadded ? "Yes" : "No") << "\n";
}
