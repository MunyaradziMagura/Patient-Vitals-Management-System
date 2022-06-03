#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"

class FileLoaderAdapter : public AbstractPatientDatabaseLoader
{

public:

	virtual void initialiseConnection() override;

	virtual void loadPatients(std::vector<Patient*>& patientIn) override;

	virtual void closeConnection() override;

private:

	PatientFileLoader* _PatientFileLoader;

};

