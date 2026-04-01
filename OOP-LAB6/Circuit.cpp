#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
    count = 0;
}

void Circuit::SetLength(int l)
{
    length = l;
}

void Circuit::SetWeather(Weather w)
{
    weather = w;
}

void Circuit::AddCar(Car* car)
{
    cars[count++] = car;
}

void Circuit::Race()
{
    for (int i = 0; i < count; i++)
    {
        double maxDistance = (cars[i]->GetFuelCapacity() / cars[i]->GetFuelConsumption()) * 100;

        if (maxDistance < length)
        {
            finished[i] = false;
            times[i] = 0;
        }
        else
        {
            finished[i] = true;
            times[i] = length / cars[i]->GetSpeed(weather);
        }
    }

    // sort by time
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (finished[i] && finished[j] && times[i] > times[j])
            {
                swap(times[i], times[j]);
                swap(cars[i], cars[j]);
                swap(finished[i], finished[j]);
            }
}

void Circuit::ShowFinalRanks()
{
    cout << "Final ranks:\n";
    for (int i = 0; i < count; i++)
        if (finished[i])
            cout << cars[i]->GetName() << " - " << times[i] << " hours\n";
}

void Circuit::ShowWhoDidNotFinish()
{
    cout << "Did not finish:\n";
    for (int i = 0; i < count; i++)
        if (!finished[i])
            cout << cars[i]->GetName() << "\n";
}