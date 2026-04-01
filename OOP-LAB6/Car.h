#pragma once
#include "Weather.h"

class Car
{
protected:
    double fuelCapacity;
    double fuelConsumption; // liters / 100 km
    double speedSunny;
    double speedRain;
    double speedSnow;

public:
    virtual ~Car() {}

    virtual double GetFuelCapacity() = 0;
    virtual double GetFuelConsumption() = 0;
    virtual double GetSpeed(Weather w) = 0;
    virtual const char* GetName() = 0;
};