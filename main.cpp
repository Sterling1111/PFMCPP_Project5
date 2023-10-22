/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */


#include <iostream>
#include "LeakedObjectDetector.h"
#include "Wrappers.h"

int main()
{
    Car::Fuel fuel;

    fuel.burn();
    fuel.smell();
    fuel.flow();

    float cost = fuel.buyGas(5);

    std::cout << "Cost to buy 5 gallons of gas: " << cost << std::endl;

    std::cout << "Fuel details: \n"
              << "Octane Rating: " << fuel.octaneRating << "\n"
              << "Cost Per Gallon: " << fuel.costPerGallon << " $/gallon\n"
              << "Country of Origin: " << fuel.CountryOfOrigin << "\n"
              << "Distributer: " << fuel.distributer << "\n"
              << "Color: " << fuel.color << "\n";

    fuel.printFuelDetails();


    //Car
    CarWrapper car(new Car());

    car.carPtr->playMusic();
    car.carPtr->drive();
    car.carPtr->putFuelInCar(fuel);
    car.carPtr->consumeFuel();

    std::cout << "Car details: \n"
              << "Color: " << car.carPtr->carColor << "\n"
              << "Horse Power: " << car.carPtr->horsePower << "\n"
              << "Cost: " << car.carPtr->cost << " $\n"
              << "Brand: " << car.carPtr->brand << "\n"
              << "Year: " << car.carPtr->year << "\n";

    car.carPtr->printCarDetails();

    //Case
    CellPhone::Case phoneCase;

    phoneCase.wrapPhone();
    phoneCase.providePadding();
    phoneCase.preventScratches();

    std::cout << "Phone Case details: \n"
              << "Color: " << phoneCase.color << "\n"
              << "Brand: " << phoneCase.brand << "\n"
              << "Cost: " << phoneCase.cost << " $\n"
              << "Features: " << phoneCase.features << "\n"
              << "Is Padded? " << (phoneCase.isPadded ? "Yes" : "No") << "\n";

    phoneCase.printCaseDetails();

    //CellPhone
    CellPhoneWrapper cellPhone(new CellPhone());

    cellPhone.cellPhonePtr->makeCall();
    cellPhone.cellPhonePtr->browseWeb();
    cellPhone.cellPhonePtr->playMusic();
    cellPhone.cellPhonePtr->changePhoneCase(phoneCase);

    std::cout << "CellPhone details: \n"
              << "Color: " << cellPhone.cellPhonePtr->color << "\n"
              << "Data Provider: " << cellPhone.cellPhonePtr->dataProvider << "\n"
              << "Brand: " << cellPhone.cellPhonePtr->brand << "\n"
              << "Processor: " << cellPhone.cellPhonePtr->processor << "\n"
              << "RAM Amount: " << cellPhone.cellPhonePtr->ramAmount << " GB\n";

    cellPhone.cellPhonePtr->printCellPhoneDetails();

    //Screen
    ScreenWrapper screen(new Screen());

    screen.screenPtr->displayImages();
    screen.screenPtr->adjustColorSettings();
    screen.screenPtr->adjustRefreshRate();

    int numPixels = screen.screenPtr->setPixels(1, 2);

    std::cout << numPixels << " changed" << std::endl;

    std::cout << "Screen details: \n"
              << "Brand: " << screen.screenPtr->brand << "\n"
              << "Refresh Rate: " << screen.screenPtr->refreshRate << " Hz\n"
              << "Resolution: " << screen.screenPtr->pixelsX << "x" << screen.screenPtr->pixelsY << "\n"
              << "Connectors: " << screen.screenPtr->connectors << "\n";

    screen.screenPtr->printScreenDetails();

    PersonWrapper person1(new Person());
    PersonWrapper person2(new Person());

    person1.personPtr->driveCar("home", "friends house");
    person1.personPtr->placeCall(*(person2.personPtr));

    MonitorWrapper monitor(new Monitor());

    monitor.monitorPtr->powerOn();
    monitor.monitorPtr->adjustBrightness();

    std::cout << "good to go!" << std::endl;
}
