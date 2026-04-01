#pragma once
#include "Car.h"

class Seat : public Car
{
public:
    Seat();
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    double GetSpeed(Weather w) override;
    const char* GetName() override;
};