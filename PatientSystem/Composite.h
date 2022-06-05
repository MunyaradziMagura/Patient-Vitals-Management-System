#pragma once
#include "AbstractPatientDatabaseLoader.h"
#include <vector>
#include <memory>
class Composite :
    public AbstractPatientDatabaseLoader
{
public:
    void addLoadMethod(std::shared_ptr<AbstractPatientDatabaseLoader> method);
    // Inherited via AbstractPatientDatabaseLoader
    virtual void initialiseConnection() override;
    virtual void loadPatients(std::vector<Patient*>& patientIn) override;
    virtual void closeConnection() override;
protected:
    std::vector<std::shared_ptr<AbstractPatientDatabaseLoader>> _method;


};

