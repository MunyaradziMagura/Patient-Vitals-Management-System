#include "Boneitis.h"

void Boneitis::algorithmInterface(float bodyTemperature, int bloodPressure, int heartRate, int respitoryRate, string lastname, string firstname, string id, int age, Patient* p)
{
    if (respitoryRate > 20 && respitoryRate < 30) { std::cout << "Patient:"  <<id << " has an alert level: " << "YELLOW" << std::endl; }
    if (respitoryRate > 30 && respitoryRate < 40) { std::cout << "Patient:" << id << " has an alert level: " << "ORANGE" << std::endl; }
    if (respitoryRate > 40) { std::cout << "Patient: " << id << " has an alert level: " << "RED" << std::endl; }
}
