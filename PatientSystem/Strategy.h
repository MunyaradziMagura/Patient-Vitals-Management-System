#pragma once
#include <string>
#include <iostream>
#include "Patient.h"
using namespace std;
class Strategy
{
public:
    virtual ~Strategy() {
        /* ... */
    }
    virtual void algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p) = 0;

};

