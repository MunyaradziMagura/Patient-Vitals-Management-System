#include "Composite.h"

void Composite::addLoadMethod(AbstractPatientDatabaseLoader* method)
{
	_method.push_back(method);
}

void Composite::initialiseConnection()
{
}

void Composite::loadPatients(std::vector<Patient*>& patientIn)
{
	for (auto method : _method) {
		method->loadPatients(patientIn);
	}
}

void Composite::closeConnection()
{
}
