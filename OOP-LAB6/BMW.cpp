#include "BMW.h"

BMW::BMW()
{
    fuelCapacity = 55;
    fuelConsumption = 10;
    speedSunny = 150;
    speedRain = 120;
    speedSnow = 90;
}

double BMW::GetFuelCapacity() { return fuelCapacity; }
double BMW::GetFuelConsumption() { return fuelConsumption; }

double BMW::GetSpeed(Weather w)
{
    if (w == Weather::Sunny) return speedSunny;
    if (w == Weather::Rain) return speedRain;
    return speedSnow;
}

const char* BMW::GetName() { return "BMW"; }