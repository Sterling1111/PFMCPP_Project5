#include "Wrappers.h"
#include "Person.h"
#include "Car.h"
#include "CellPhone.h"
#include "Screen.h"
#include "Monitor.h"

CarWrapper::CarWrapper(Car* ptr) : carPtr{ptr} {}
CarWrapper::~CarWrapper()
{
    delete carPtr;
}

CellPhoneWrapper::CellPhoneWrapper(CellPhone* ptr) : cellPhonePtr{ptr} {}
CellPhoneWrapper::~CellPhoneWrapper()
{
    delete cellPhonePtr;
}

ScreenWrapper::ScreenWrapper(Screen* ptr) : screenPtr{ptr} {}
ScreenWrapper::~ScreenWrapper()
{
    delete screenPtr;
}

PersonWrapper::PersonWrapper(Person* ptr) : personPtr{ptr} {}
PersonWrapper::~PersonWrapper()
{
    delete personPtr;
}

MonitorWrapper::MonitorWrapper(Monitor* ptr) : monitorPtr{ptr} {}
MonitorWrapper::~MonitorWrapper()
{
    delete monitorPtr;
}
