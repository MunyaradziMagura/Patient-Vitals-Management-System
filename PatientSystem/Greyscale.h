#pragma once
#include "Strategy.h"
class Greyscale :
    public Strategy
{
public:
    ~Greyscale() {}

    void algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p);
};

