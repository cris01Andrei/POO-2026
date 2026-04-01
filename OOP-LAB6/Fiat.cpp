#include "Fiat.h"

Fiat::Fiat()
{
    fuelCapacity = 45;
    fuelConsumption = 6;
    speedSunny = 100;
    speedRain = 80;
    speedSnow = 60;
}

double Fiat::GetFuelCapacity() { return fuelCapacity; }
double Fiat::GetFuelConsumption() { return fuelConsumption; }

double Fiat::GetSpeed(Weather w)
{
    if (w == Weather::Sunny) return speedSunny;
    if (w == Weather::Rain) return speedRain;
    return speedSnow;
}

const char* Fiat::GetName() { return "Fiat"; }