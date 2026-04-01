#pragma once
#include "Car.h"

class RangeRover : public Car
{
public:
    RangeRover();
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    double GetSpeed(Weather w) override;
    const char* GetName() override;
};