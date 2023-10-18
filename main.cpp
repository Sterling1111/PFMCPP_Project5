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

/*
 copied UDT 1:
 */

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

struct CarWrapper
{
    Car* carPtr{nullptr};

    CarWrapper(Car* ptr) : carPtr{ptr} {}
    ~CarWrapper()
    {
        delete carPtr;
    }
    JUCE_LEAK_DETECTOR(CarWrapper)
};

/*
 copied UDT 2:
 */

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

struct CellPhoneWrapper
{
    CellPhone* cellPhonePtr{nullptr};

    CellPhoneWrapper(CellPhone* ptr) : cellPhonePtr{ptr} {}
    ~CellPhoneWrapper()
    {
        delete cellPhonePtr;
    }
    JUCE_LEAK_DETECTOR(CellPhoneWrapper)
};

/*
 copied UDT 3:
 */

struct Screen
{
    Screen();
    ~Screen();

    std::string brand;
    int refreshRate{75};
    int pixelsX{920};
    int pixelsY{560};
    std::string connectors{"HDMI"};

    void displayImages() const;
    void adjustColorSettings() const;
    void adjustRefreshRate() const;

    int setPixels(int, int) const;

    void printScreenDetails() const;

    JUCE_LEAK_DETECTOR(Screen)
};

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

struct ScreenWrapper
{
    Screen* screenPtr{nullptr};

    ScreenWrapper(Screen* ptr) : screenPtr{ptr} {}
    ~ScreenWrapper()
    {
        delete screenPtr;
    }
    JUCE_LEAK_DETECTOR(ScreenWrapper)
};

/*
 new UDT 4:
 with 2 member functions
 */

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

struct PersonWrapper
{
    Person* personPtr{nullptr};

    PersonWrapper(Person* ptr) : personPtr{ptr} {}
    ~PersonWrapper()
    {
        delete personPtr;
    }

    JUCE_LEAK_DETECTOR(PersonWrapper)
};

/*
 new UDT 5:
 with 2 member functions
 */

struct Monitor
{
    Monitor();
    ~Monitor();

    Screen screen;

    void powerOn() const;
    void adjustBrightness() const;

    JUCE_LEAK_DETECTOR(Monitor)
};

Monitor::Monitor()
{
    std::cout << "Monitor being constructed" << std::endl;
}

Monitor::~Monitor()
{
    std::cout << "Monitor being destructed" << std::endl;
}

void Monitor::powerOn() const
{
    std::cout << "Turning on the monitor" << std::endl;
}

void Monitor::adjustBrightness() const
{
    std::cout << "Adjusting brightness" << std::endl;
}

struct MonitorWrapper
{
    Monitor* monitorPtr{nullptr};

    MonitorWrapper(Monitor* ptr) : monitorPtr{ptr} {}
    ~MonitorWrapper()
    {
        delete monitorPtr;
    }

    JUCE_LEAK_DETECTOR(MonitorWrapper)
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

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
