#include "Archive.h"


void Archive::regNewCustomer(string name)
{
	reestr.insert(pair<Time_, Customer>(Time_(), Customer(name)));
}

void Archive::showCustomersList() const
{
	for (auto item : reestr) {
		cout << item.first << endl;
		item.second.showInfo();
	}
}

void Archive::takeEd(Time_ t, string ISBN)
{
	if (reestr.find(t) != reestr.end()) {
		reestr[t].takeEdition(library.searchByISBN(ISBN));
		library.delEdition(ISBN);
	}
}

void Archive::returnEdition(Time_ t, string ISBN)
{
	if (reestr.find(t) != reestr.end()) {
		Edition* obj = reestr[t].returnEdition(ISBN);
		library.addEdition(obj);
	}
}

void Archive::showLibrary() const
{
	library.showInfo();
}
