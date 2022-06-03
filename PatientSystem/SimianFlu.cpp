#include "SimianFlu.h"

void SimianFlu::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (bloodPressure > 140) { 
        std::cout << "Patient:" << id << " has an alert level: " << "RED" << std::endl; 
        p->setAlertLevel(AlertLevel::Red);
    }
    if (bloodPressure > 130) { 
        std::cout << "Patient:" << id << " has an alert level: " << "ORANGE" << std::endl; 
        p->setAlertLevel(AlertLevel::Orange);
    }
    if (bloodPressure > 110) { 
        std::cout << "Patient:" << id << " has an alert level: " << "YELLOW" << std::endl;
        p->setAlertLevel(AlertLevel::Yellow);
    }
}
