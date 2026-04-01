#include "RangeRover.h"

RangeRover::RangeRover()
{
    fuelCapacity = 80;
    fuelConsumption = 15;
    speedSunny = 130;
    speedRain = 110;
    speedSnow = 100;
}

double RangeRover::GetFuelCapacity() { return fuelCapacity; }
double RangeRover::GetFuelConsumption() { return fuelConsumption; }

double RangeRover::GetSpeed(Weather w)
{
    if (w == Weather::Sunny) return speedSunny;
    if (w == Weather::Rain) return speedRain;
    return speedSnow;
}

const char* RangeRover::GetName() { return "RangeRover"; }