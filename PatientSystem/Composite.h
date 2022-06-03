#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include <vector>
class Composite :
    public AbstractPatientDatabaseLoader
{
public:
    void addLoadMethod(AbstractPatientDatabaseLoader* method);

protected:
    std::vector<AbstractPatientDatabaseLoader*> _method;

    // Inherited via AbstractPatientDatabaseLoader
    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientIn) override;
    virtual void closeConnection() override;
};

