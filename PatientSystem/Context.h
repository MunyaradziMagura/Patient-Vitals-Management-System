#pragma once
#include "Strategy.h"
#include "Patient.h"
class Context
{
public:
    Context(Strategy* const s, float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p) : strategy(s) {
        _bodyTemperature = bodyTemperature;
            _bloodPressure = bloodPressure;
            _heartRate = heartRate;
            _respitoryRate = respitoryRate;
            _lastname = lastname;
            _firstname = firstname;
            _id = id;
            _age = age;
            _p = p;
    }

    ~Context()
    {
        delete strategy;
    }

    void contextInterface()
    {
        strategy->algorithmInterface(_bodyTemperature, _bloodPressure, _heartRate, _respitoryRate, _lastname, _firstname, _id,  _age, _p);
    }

private:
    Strategy* strategy;
    Patient* _p;
    float _bodyTemperature;
    int _bloodPressure;
    int _heartRate;
    int _respitoryRate;
    string _lastname;
    string _firstname;
    string _id;
    int _age;
    
};

