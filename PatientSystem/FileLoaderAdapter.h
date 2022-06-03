#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include "PatientFileLoader.h"
class FileLoaderAdapter :
    public AbstractPatientDatabaseLoader
{
private:
    PatientFileLoader* _PatientFileLoader;
public:
    FileLoaderAdapter(PatientFileLoader* PatientFileLoader) {
        _PatientFileLoader = PatientFileLoader;
    }
	// initialise the database connection
    virtual void initialiseConnection() override;

    virtual void loadPatients(std::vector<Patient*>& patientIn) override;

    virtual void closeConnection() override;
};

