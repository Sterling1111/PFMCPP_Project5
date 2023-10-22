#include "Monitor.h"

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
