#include "PatientFileLoader.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include "Patient.h"
#include "Vitals.h"

using namespace std;


std::vector<Patient*> PatientFileLoader::loadPatientFile(const std::string& file)
{

    std::ifstream inFile(file);
    if (inFile.is_open()) {

        Patient* line{};
        Patient* p;

        std::tm t{ };
        std::istringstream ss(DOB);
        ss >> std::get_time(&t, "%d-%m-%Y");


        while (getline(inFile, fileLine)) {
            std::stringstream currentLine(fileLine);
            getline(currentLine, id, '|');
            getline(currentLine, lastname, ',');
            getline(currentLine, firstname, '|');

            getline(currentLine, DOB, '|');

            stringstream Date(DOB);

            Date >> get_time(&dateOfBirth, "%d-%m-%Y");

            getline(currentLine, disease, '|');

            p = new Patient(lastname, firstname, dateOfBirth);

            p->addDiagnosis(disease);

            while (!(currentLine.peek() == EOF)) {

                if (getline(currentLine, bodytemp, ',').good()) {
                    bt = std::stof(bodytemp);
                }
                if (getline(currentLine, bloodpre, ',').good()) {
                    bp = std::stoi(bloodpre);
                }
                if (getline(currentLine, heartRate, ',').good()) {
                    hr = std::stoi(heartRate);
                }
                if (getline(currentLine, respRate, ';').good()) {
                    rs = std::stoi(respRate);
                }
                else {
                    Date.clear();
                    Date.ignore();

                }

                Vitals* v = new Vitals(bt, bp, hr, rs);

                p->addVitals(v);
            }

            patients.push_back(p);
        }

        inFile.close();
    }


    return patients;
}
