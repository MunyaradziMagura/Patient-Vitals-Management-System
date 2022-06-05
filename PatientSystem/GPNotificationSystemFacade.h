#pragma once

#include "Patient.h"
#include "Observer.h"

class GPNotificationSystemFacade: public Observer {
public:
	GPNotificationSystemFacade();
	virtual ~GPNotificationSystemFacade();

	void sendGPNotificationForPatient(Patient* p);

	virtual void alertChange(Patient* p) override;

};

