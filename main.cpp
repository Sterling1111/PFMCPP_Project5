/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/


#include <iostream>

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

        void burn();
        void smell();
        void flow();

        float buyGas(float);
    };

    std::string carColor;
    int horsePower{200};
    float cost{32'000.f};
    std::string brand{"Honda"};
    int year{1997};

    void playMusic();
    void drive();
    void putFuelInCar(Fuel fule);
    float consumeFuel(); // return the fuel consumed in gallon

};

Car::Car() : carColor{"green"}
{
    std::cout << "Car being constructed" << std::endl;
}

Car::~Car() 
{
    std::cout << "Car being destructed" << std::endl;
}

void Car::playMusic()
{
    std::cout << "Playing music...\n";
}

void Car::drive()
{
    std::cout << carColor << std::endl;
    std::cout << "Driving...\n";
}

void Car::putFuelInCar(Car::Fuel fuel)
{
    std::cout << "Putting fuel in car from " << fuel.distributer << "...\n";
}

float Car::consumeFuel()
{
    for(int i = 0; i < 5; ++i)
    {
        std::cout << "Consuming " << i << " gallons of fuel" << std::endl;
    }
    std::cout << "Consuming fuel...\n";
    return 5.0f;  // replace with actual implementation
}

Car::Fuel::Fuel() : octaneRating{98}
{
    std::cout << "Fuel being constructed" << std::endl;
}

Car::Fuel::~Fuel()
{
    std::cout << "Fuel being destructed" << std::endl;
}

void Car::Fuel::burn()
{
    std::cout << octaneRating << std::endl;
    std::cout << "Burning fuel...\n";
}

void Car::Fuel::smell()
{
    std::cout << "Smelling fuel...\n";
}

void Car::Fuel::flow()
{
    std::cout << "Fuel is flowing...\n";
}

float Car::Fuel::buyGas(float gallons)
{
    for(float i = 1; i <= gallons; i++)
    {
        std::cout << "Total cost after gallon " << i << ": " << i * costPerGallon << std::endl; 
    }
    return costPerGallon * gallons;
}

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

        void wrapPhone();
        void providePadding();
        void preventScratches();
    };

    std::string color;
    std::string dataProvider{"AT&T"};
    std::string brand{"Samsung"};
    std::string processor{"Qualcomm 865"};
    int ramAmount{12};

    void makeCall();
    void browseWeb();
    void playMusic();

    void changePhoneCase(Case phoneCase);
};

CellPhone::CellPhone() : color{"red"}
{
    std::cout << "CellPhone being constructed" << std::endl;
}

CellPhone::~CellPhone()
{
    std::cout << "CellPhone being destructed" << std::endl;
}

void CellPhone::makeCall()
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

void CellPhone::browseWeb()
{
    std::cout << "Browsing web...\n";
}

void CellPhone::playMusic()
{
    std::cout << "Playing music...\n";
}

void CellPhone::changePhoneCase(CellPhone::Case newPhoneCase)
{
    std::cout << "Changing phone case to " << newPhoneCase.brand << "...\n";
}

CellPhone::Case::Case()
{
    std::cout << "Case being constructed" << std::endl;
}

CellPhone::Case::~Case()
{
    std::cout << "Case being destructed" << std::endl;
}

void CellPhone::Case::wrapPhone()
{
    std::cout << color << std::endl;
    std::cout << "Wrapping phone...\n";
}

void CellPhone::Case::providePadding()
{
    std::cout << "Providing padding...\n";
}

void CellPhone::Case::preventScratches()
{
    std::cout << "Preventing scratches...\n";

    for(int i = 0; i < 5; ++i)
    {
        std::cout << i << " scratches prevented" << std::endl;
    }
}

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

    void displayImages();
    void adjustColorSettings();
    void adjustRefreshRate();

    int setPixels(int, int);
};

Screen::Screen() : brand{"Dell"}
{
    std::cout << "Screen being constructed" << std::endl;
}

Screen::~Screen()
{
    std::cout << "Screen being destructed" << std::endl;
}

void Screen::displayImages()
{
    std::cout << brand << std::endl;
    std::cout << "Displaying images...\n";
}

void Screen::adjustColorSettings()
{
    std::cout << "Adjusting color settings...\n";
}

void Screen::adjustRefreshRate()
{
    std::cout << "Adjusting refresh rate...\n";
}

int Screen::setPixels(int numPixels, int alpha)
{
    for(int i = 1; i <= numPixels; ++i)
    {
        std::cout << i << " pixels set to alpha level " << alpha << std::endl;
    }
    return numPixels;
}

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

    void driveCar(std::string, std::string);
    void placeCall(Person);
};

Person::Person() 
{
    std::cout << "Person being constructed" << std::endl;
}

Person::~Person()
{
    std::cout << "Person being destructed" << std::endl;
}

void Person::driveCar(std::string start, std::string destination)
{
    std::cout << "Driving from " << start << " to " << destination << std::endl;
}

void Person::placeCall(Person friend2)
{
    std::cout << "Placing call with " << friend2.car.brand << std::endl;
}

/*
 new UDT 5:
 with 2 member functions
 */

struct Monitor
{
    Monitor();
    ~Monitor();

    Screen screen;

    void powerOn();
    void adjustBrightness();
};

Monitor::Monitor()
{
    std::cout << "Monitor being constructed" << std::endl;
}

Monitor::~Monitor()
{
    std::cout << "Monitor being destructed" << std::endl;
}

void Monitor::powerOn()
{
    std::cout << "Turning on the monitor" << std::endl;
}

void Monitor::adjustBrightness()
{
    std::cout << "Adjusting brightness" << std::endl;
}

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
    //Fuel
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


    //Car
    Car car;

    car.playMusic();
    car.drive();
    car.putFuelInCar(fuel);
    car.consumeFuel();

    std::cout << "Car details: \n"
              << "Color: " << car.carColor << "\n"
              << "Horse Power: " << car.horsePower << "\n"
              << "Cost: " << car.cost << " $\n"
              << "Brand: " << car.brand << "\n"
              << "Year: " << car.year << "\n";

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

    //CellPhone
    CellPhone cellPhone;

    cellPhone.makeCall();
    cellPhone.browseWeb();
    cellPhone.playMusic();
    cellPhone.changePhoneCase(phoneCase);

    std::cout << "CellPhone details: \n"
              << "Color: " << cellPhone.color << "\n"
              << "Data Provider: " << cellPhone.dataProvider << "\n"
              << "Brand: " << cellPhone.brand << "\n"
              << "Processor: " << cellPhone.processor << "\n"
              << "RAM Amount: " << cellPhone.ramAmount << " GB\n";

    //Screen
    Screen screen;

    screen.displayImages();
    screen.adjustColorSettings();
    screen.adjustRefreshRate();

    int numPixels = screen.setPixels(1, 2);

    std::cout << numPixels << " changed" << std::endl;

    std::cout << "Screen details: \n"
              << "Brand: " << screen.brand << "\n"
              << "Refresh Rate: " << screen.refreshRate << " Hz\n"
              << "Resolution: " << screen.pixelsX << "x" << screen.pixelsY << "\n"
              << "Connectors: " << screen.connectors << "\n";


    Person person1;
    Person person2;

    person1.driveCar("home", "friends house");
    person1.placeCall(person2);

    Monitor monitor;

    monitor.powerOn();
    monitor.adjustBrightness();

    std::cout << "good to go!" << std::endl;
}
