#include "Greyscale.h"

void Greyscale::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (age < 12 && heartRate > 120 ) { 
        std::cout << "Patient:" << id << " has an alert level: " << "RED" << std::endl;
        p->setAlertLevel(AlertLevel::Red);
    }
    if (age >= 12 && heartRate > 100) { 
        std::cout << "Patient:" << id << " has an alert level: " << "RED" << std::endl;
        p->setAlertLevel(AlertLevel::Red);
    }
}
