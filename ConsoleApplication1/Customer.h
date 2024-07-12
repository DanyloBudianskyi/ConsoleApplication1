#pragma once
#include "Edition.h"
#include <list>


class Customer
{
	string name;
	list<Edition*> listEd;
public:
	Customer();
	Customer(string name);

	void setName(string name);
	string getName()const;

	void takeEdition(Edition* obj);
	Edition* returnEdition(string ISBN);

	void showInfo()const;
};

