#include "Volvo.h"

Volvo::Volvo()
{
    fuelCapacity = 60;
    fuelConsumption = 8;
    speedSunny = 120;
    speedRain = 100;
    speedSnow = 80;
}

double Volvo::GetFuelCapacity() { return fuelCapacity; }
double Volvo::GetFuelConsumption() { return fuelConsumption; }

double Volvo::GetSpeed(Weather w)
{
    if (w == Weather::Sunny) return speedSunny;
    if (w == Weather::Rain) return speedRain;
    return speedSnow;
}

const char* Volvo::GetName() { return "Volvo"; }