#pragma once
#include "AbstractPatientDatabaseLoader.h"
class Client
{
private:
	AbstractPatientDatabaseLoader* _AbstractPatientDatabaseLoader;
public:

	Client(AbstractPatientDatabaseLoader* AbstractPatientDatabaseLoader) {
		_AbstractPatientDatabaseLoader = AbstractPatientDatabaseLoader;
	}
	AbstractPatientDatabaseLoader* getFile() {
		return _AbstractPatientDatabaseLoader;
	}

	void setFile(AbstractPatientDatabaseLoader* AbstractPatientDatabaseLoader) {
		_AbstractPatientDatabaseLoader = AbstractPatientDatabaseLoader;
	}

};

