#include "Car.h"

Car::Car() : carColor{"green"}
{
    std::cout << "Car being constructed" << std::endl;
}

Car::~Car() 
{
    std::cout << "Car being destructed" << std::endl;
}

void Car::playMusic() const
{
    std::cout << "Playing music...\n";
}

void Car::drive() const
{
    std::cout << carColor << std::endl;
    std::cout << "Driving...\n";
}

void Car::putFuelInCar(const Car::Fuel& fuel) const
{
    std::cout << "Putting fuel in car from " << fuel.distributer << "...\n";
}

float Car::consumeFuel() const
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "Consuming " << i << " gallons of fuel" << std::endl;
    }
    std::cout << "Consuming fuel...\n";
    return 5.0f;  // replace with actual implementation
}

void Car::printCarDetails() const
{
    std::cout << "Car details: \n"
          << "Color: " << this->carColor << "\n"
          << "Horse Power: " << this->horsePower << "\n"
          << "Cost: " << this->cost << " $\n"
          << "Brand: " << this->brand << "\n"
          << "Year: " << this->year << "\n";
}

Car::Fuel::Fuel() : octaneRating{98}
{
    std::cout << "Fuel being constructed" << std::endl;
}

Car::Fuel::~Fuel()
{
    std::cout << "Fuel being destructed" << std::endl;
}

void Car::Fuel::burn() const
{
    std::cout << octaneRating << std::endl;
    std::cout << "Burning fuel...\n";
}

void Car::Fuel::smell() const
{
    std::cout << "Smelling fuel...\n";
}

void Car::Fuel::flow() const
{
    std::cout << "Fuel is flowing...\n";
}

float Car::Fuel::buyGas(float gallons) const
{
    for(float i = 1; i <= gallons; i++)
    {
        std::cout << "Total cost after gallon " << i << ": " << i * costPerGallon << std::endl; 
    }
    return costPerGallon * gallons;
}

void Car::Fuel::printFuelDetails() const
{
    std::cout << "Fuel details: \n"
          << "Octane Rating: " << this->octaneRating << "\n"
          << "Cost Per Gallon: " << this->costPerGallon << " $/gallon\n"
          << "Country of Origin: " << this->CountryOfOrigin << "\n"
          << "Distributer: " << this->distributer << "\n"
          << "Color: " << this->color << "\n";
}
