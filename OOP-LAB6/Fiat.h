#pragma once
#include "Car.h"

class Fiat : public Car
{
public:
    Fiat();
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    double GetSpeed(Weather w) override;
    const char* GetName() override;
};