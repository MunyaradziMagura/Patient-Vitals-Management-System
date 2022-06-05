#include "Greyscale.h"

void Greyscale::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (age < 12 && heartRate > 120 ) { 
        p->setAlertLevel(AlertLevel::Red);
    }
    if (age >= 12 && heartRate > 100) { 
        p->setAlertLevel(AlertLevel::Red);
    }
    p->setAlertLevel(AlertLevel::Green);
}
