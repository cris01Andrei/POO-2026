#pragma once
#include "Car.h"

class Circuit
{
private:
    Car* cars[100];
    double times[100];
    bool finished[100];
    int count;
    int length;
    Weather weather;

public:
    Circuit();
    void SetLength(int l);
    void SetWeather(Weather w);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
};