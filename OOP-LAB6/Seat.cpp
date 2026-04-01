#include "Seat.h"

Seat::Seat()
{
    fuelCapacity = 50;
    fuelConsumption = 7;
    speedSunny = 110;
    speedRain = 90;
    speedSnow = 70;
}

double Seat::GetFuelCapacity() { return fuelCapacity; }
double Seat::GetFuelConsumption() { return fuelConsumption; }

double Seat::GetSpeed(Weather w)
{
    if (w == Weather::Sunny) return speedSunny;
    if (w == Weather::Rain) return speedRain;
    return speedSnow;
}

const char* Seat::GetName() { return "Seat"; }