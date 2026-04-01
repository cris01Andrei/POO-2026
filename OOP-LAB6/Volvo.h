#pragma once
#include "Car.h"

class Volvo : public Car
{
public:
    Volvo();
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    double GetSpeed(Weather w) override;
    const char* GetName() override;
};