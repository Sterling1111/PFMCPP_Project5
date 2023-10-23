#include "Person.h"

Person::Person() 
{
    std::cout << "Person being constructed" << std::endl;
}

Person::~Person()
{
    std::cout << "Person being destructed" << std::endl;
}

void Person::driveCar(std::string start, std::string destination) const
{
    std::cout << "Driving from " << start << " to " << destination << std::endl;
}

void Person::placeCall(const Person& friend2) const
{
    std::cout << "Placing call with " << friend2.car.brand << std::endl;
}
