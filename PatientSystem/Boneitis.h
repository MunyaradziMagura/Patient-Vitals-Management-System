#pragma once
#include "Strategy.h"

class Boneitis :
    public Strategy
{
public:
    ~Boneitis() {}

    void algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p);
};

