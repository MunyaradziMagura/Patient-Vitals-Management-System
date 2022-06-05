#pragma once

#include <string>
#include <vector>


// forward declare the patient class
class Patient;

class PatientFileLoader
{
private:


public:
    vector<Patient*> patients{};
    Patient* person = nullptr;
    string id;
    string lastname;
    string firstname;
    string DOB;
    string disease;
    string bodytemp;
    string bloodpre;
    string heartRate;
    string respRate;
    float bt{};
    int bp{};
    int hr{};
    int rs{};
    tm dateOfBirth;
    string fileLine;
	// loads a list of patients from a file and returns a vector of those patients
	std::vector<Patient*> loadPatientFile(const std::string& file);

};

