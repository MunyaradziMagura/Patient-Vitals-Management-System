#include "Boneitis.h"

void Boneitis::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{

    if (respitoryRate > 20 && respitoryRate < 30) { 
        p->setAlertLevel(AlertLevel::Yellow);

    } else if (respitoryRate > 30 && respitoryRate < 40) {
        p->setAlertLevel(AlertLevel::Orange);

    } else if (respitoryRate > 40) {
        p->setAlertLevel(AlertLevel::Red);

    } else {
        p->setAlertLevel(AlertLevel::Green);

    }
}
