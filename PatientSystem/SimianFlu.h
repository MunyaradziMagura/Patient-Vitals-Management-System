#pragma once
#include "Strategy.h"
class SimianFlu :
    public Strategy
{
public:
    ~SimianFlu() {}
    void algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p);
    
};

