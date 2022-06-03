#include "SimianFlu.h"

void SimianFlu::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (bloodPressure > 140) { 
        p->setAlertLevel(AlertLevel::Red);
    }
    if (bloodPressure > 130) { 
        p->setAlertLevel(AlertLevel::Orange);
    }
    if (bloodPressure > 110) { 
        p->setAlertLevel(AlertLevel::Yellow);
    }
}
