#pragma once
class Patient;
class Observer
{
public:
	virtual void alertChange(Patient* p) = 0;
};

