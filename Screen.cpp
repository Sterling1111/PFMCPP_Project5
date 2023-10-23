#include "Screen.h"

Screen::Screen() : brand{"Dell"}
{
    std::cout << "Screen being constructed" << std::endl;
}

Screen::~Screen()
{
    std::cout << "Screen being destructed" << std::endl;
}

void Screen::displayImages() const
{
    std::cout << brand << std::endl;
    std::cout << "Displaying images...\n";
}

void Screen::adjustColorSettings() const
{
    std::cout << "Adjusting color settings...\n";
}

void Screen::adjustRefreshRate() const
{
    std::cout << "Adjusting refresh rate...\n";
}

int Screen::setPixels(int numPixels, int alpha) const
{
    for(int i = 1; i <= numPixels; ++i)
    {
        std::cout << i << " pixels set to alpha level " << alpha << std::endl;
    }
    return numPixels;
}

void Screen::printScreenDetails() const
{
    std::cout << "Screen details: \n"
          << "Brand: " << this->brand << "\n"
          << "Refresh Rate: " << this->refreshRate << " Hz\n"
          << "Resolution: " << this->pixelsX << "x" << this->pixelsY << "\n"
          << "Connectors: " << this->connectors << "\n";
}
