#include "Composite.h"

void Composite::addLoadMethod(std::shared_ptr<AbstractPatientDatabaseLoader> method)
{
	_method.push_back(method);
}

void Composite::initialiseConnection()
{
}

void Composite::loadPatients(std::vector<Patient*>& patientIn)
{
	std::vector<Patient*> localLoad{};
	for (auto method : _method) {
	method->loadPatients(patientIn);
	patientIn.insert(patientIn.end(), localLoad.begin(), localLoad.end());

	}
}

void Composite::closeConnection()
{
}
