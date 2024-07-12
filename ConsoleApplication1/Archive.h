#pragma once
#include "Catalogue.h"
#include "Customer.h"
#include <map>
#include "Time_ .h"

class Archive
{
	Catalogue library;
	map<Time_, Customer> reestr;
public:
	void regNewCustomer(string name);
	void showCustomersList()const;

	void takeEd(Time_ t, string ISBN);
	void returnEdition(Time_ t, string ISBN);

	void showLibrary()const;
};

