#pragma once
#include "Car.h"

class BMW : public Car
{
public:
    BMW();
    double GetFuelCapacity() override;
    double GetFuelConsumption() override;
    double GetSpeed(Weather w) override;
    const char* GetName() override;
};