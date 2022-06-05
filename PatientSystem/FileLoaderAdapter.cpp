#include "FileLoaderAdapter.h"

void FileLoaderAdapter::initialiseConnection()
{
}

void FileLoaderAdapter::loadPatients(std::vector<Patient*>& patientIn)
{
	auto loadTextFile = _PatientFileLoader->loadPatientFile("patients.txt");
	patientIn.insert(patientIn.end(), loadTextFile.begin(), loadTextFile.end());
}

void FileLoaderAdapter::closeConnection()
{
}
