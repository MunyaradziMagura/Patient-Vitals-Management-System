#include "FileLoaderAdapter.h"
#include <iostream>
using namespace std;

void FileLoaderAdapter::initialiseConnection()
{
}

void FileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
	cout << "FILE WORKING" << endl;

	auto textFile = _PatientFileLoader->loadPatientFile("patients.txt");
	
	patientIn.insert(patientIn.end(), textFile.begin(), textFile.end());

}

void FileLoaderAdapter::closeConnection()
{
}
