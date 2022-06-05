#include "Greyscale.h"

void Greyscale::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (age < 12 && heartRate > 120 ) { 
        p->setAlertLevel(AlertLevel::Red);
    
    } else if (age >= 12 && heartRate > 100) {
        p->setAlertLevel(AlertLevel::Red);
    }else{
        p->setAlertLevel(AlertLevel::Green);
    }
   
}
