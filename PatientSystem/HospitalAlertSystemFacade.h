#pragma once

#include "Patient.h"
#include "Observer.h"

class HospitalAlertSystemFacade : public Observer
{
public:
	HospitalAlertSystemFacade();
	virtual ~HospitalAlertSystemFacade();

	void sendAlertForPatient(Patient* p);
	virtual void alertChange(Patient* p) override;

};

