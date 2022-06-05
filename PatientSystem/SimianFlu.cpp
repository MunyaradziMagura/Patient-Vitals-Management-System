#include "SimianFlu.h"

void SimianFlu::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (bloodPressure > 110 && bloodPressure < 130) {
        p->setAlertLevel(AlertLevel::Yellow);
    
    }else if (bloodPressure > 130 && bloodPressure < 140) {
        p->setAlertLevel(AlertLevel::Orange);
    
    } else if (bloodPressure > 140) {
        p->setAlertLevel(AlertLevel::Red);
    
    }else {
        p->setAlertLevel(AlertLevel::Green);
    }
}
