#include "PatientManagementSystem.h"

#include <iostream>
#include <map>
#include <tuple>

#include "Patient.h"
#include "PatientDatabaseLoader.h"
#include "Vitals.h"

#include "GPNotificationSystemFacade.h"
#include "HospitalAlertSystemFacade.h"
#include "Context.h"
#include "Boneitis.h"
#include "Greyscale.h"
#include "SimianFlu.h"
#include "FileLoaderAdapter.h"

using namespace std;


PatientManagementSystem::PatientManagementSystem() :
	//_patientDatabaseLoader(std::make_unique<PatientDatabaseLoader>()),
	//_FileLoaderAdapter(std::make_unique<FileLoaderAdapter>()),
	
	// make shared pointers 
	_patientDatabaseLoader(std::make_shared<PatientDatabaseLoader>()),
	_FileLoaderAdapter(std::make_shared<FileLoaderAdapter>()),
	_CompositeLoader(std::make_unique <Composite>()),
	
	// facades 
	_hospitalAlertSystem(std::make_unique<HospitalAlertSystemFacade>()),
	_gpNotificationSystem(std::make_unique<GPNotificationSystemFacade>())
{
	//_patientDatabaseLoader->initialiseConnection();
	//_FileLoaderAdapter->loadPatients(_patients);

	// load patient database and file 
	_CompositeLoader.get()->addLoadMethod(_patientDatabaseLoader);
	_CompositeLoader.get()->addLoadMethod(_FileLoaderAdapter);	
}

PatientManagementSystem::~PatientManagementSystem()
{
	//_patientDatabaseLoader->closeConnection();
	_CompositeLoader.get()->closeConnection();
	// clear patient memory
	for (Patient* p : _patients) {
		delete p;
	}
}

void PatientManagementSystem::init()
{
	//_patientDatabaseLoader->loadPatients(_patients);
	_CompositeLoader.get()->loadPatients(_patients);
	for (Patient* p : _patients) {
		_patientLookup[p->uid()] = p;
	}

	for (Patient* p : _patients) {
		p->subscribe(_hospitalAlertSystem.get());
		p->subscribe(_gpNotificationSystem.get());
	}
}

void PatientManagementSystem::run()
{
	printWelcomeMessage();

	bool running = true;
	while (running) {
		printMainMenu();
		int option = 0;
		cin >> option;

		// handle basic errors
		if (cin.bad()) {
			cin.clear();
			cin.ignore();
			continue;
		}

		// switch based on the selected option
		switch (option) {
		case 1:
			printPatients();
			break;
		case 2:
			addVitalsRecord();
			break;
		case 3:
			running = false;
			break;
		}
	}
}

void PatientManagementSystem::addVitalsRecord()
{
	cout << "Patients" << endl;
	printPatients();
	cout << endl;
	cout << "Enter the patient ID to declare vitals for > ";

	string pid { "" };
	cin >> pid;
	if (_patientLookup.count(pid)) {
		float bodyTemperature;
		int bloodPressure;
		int heartRate;
		int respitoryRate;
		auto lastname = _patientLookup[pid]->lastName();
		auto firstname = _patientLookup[pid]->firstName();
		auto id = _patientLookup[pid]->humanReadableID();
		auto age = _patientLookup[pid]->age();
		
		cout << "enter body temperature: ";
		cin >> bodyTemperature;
		cout << "enter blood pressure: ";
		cin >> bloodPressure;
		cout << "enter heart rate: ";
		cin >> heartRate;
		cout << "enter respitory rate: ";
		cin >> respitoryRate;
		
		Vitals* v = new Vitals(bodyTemperature, bloodPressure, heartRate, respitoryRate);
		_patientLookup[pid]->addVitals(v);

		// if person has Boneitis
		if (_patientLookup[pid]->primaryDiagnosis() == "Boneitis") {
			Context context(new Boneitis(), bodyTemperature, bloodPressure, heartRate, respitoryRate, lastname, firstname, id, age, _patientLookup[pid]);
			context.contextInterface();
		}
		// if person has Greyscale
		if (_patientLookup[pid]->primaryDiagnosis() == "Greyscale") {
			Context context(new Greyscale(), bodyTemperature, bloodPressure, heartRate, respitoryRate, lastname, firstname, id, age, _patientLookup[pid]);
			context.contextInterface();
		}
		// if person has Simian Flu
		if (_patientLookup[pid]->primaryDiagnosis() == "Simian Flu") {
			Context context(new SimianFlu(), bodyTemperature, bloodPressure, heartRate, respitoryRate, lastname, firstname, id, age, _patientLookup[pid]);
			context.contextInterface();
		}

		
		
	}
	else {
		cout << "Patient not found" << endl;
	}
}

void PatientManagementSystem::printWelcomeMessage() const
{
	cout << "WELCOME TO HEALTHCO 3000" << endl;
	cout << "------------------------" << endl;
}

void PatientManagementSystem::printMainMenu() const
{
	cout << endl << "Select an option:" << endl;
	cout << "1. List patients" << endl;
	cout << "2. Add vitals record" << endl;
	cout << "3. Quit" << endl;
	cout << "> ";
}

void PatientManagementSystem::printPatients() const
{
	for (Patient* p : _patients) {
		std::cout << *p << std::endl;
	}
}
