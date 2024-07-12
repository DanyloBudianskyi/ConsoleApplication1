#include "Catalogue.h"

Catalogue::Catalogue()
{
	catalogue.insert(new Book("123A", "Name1", "Author1", 1999, "publisher1"));
	catalogue.insert(new Magazine("456B", "Magazine1", "Author2", 1999, 1234));
	catalogue.insert(new ClassBook("789C", "Math", "Author3", 2006, "publisher2", 3));
	catalogue.insert(new Book("789D", "Name2", "Author4", 1999, "publisher3"));
	catalogue.insert(new ClassBook("012C", "C++", "Author5", 1999, "publisher4", 1));

}

Catalogue::~Catalogue()
{
	for (auto item : catalogue) {
		delete item;
	}
}

void Catalogue::showInfo() const
{
	for (auto item : catalogue) {
		item->showInfo();
	}
}

void Catalogue::addEdition(Edition* obj)
{
	if(obj != nullptr)	catalogue.insert(obj);
}

void Catalogue::delEdition(string ISBN)
{
	auto item = find_if(catalogue.begin(), catalogue.end(), [ISBN](const Edition* a) {
		return a->getISBN() == ISBN;
		});
	if (item != catalogue.end()) {
		catalogue.erase(item);
	}
}

Edition* Catalogue::searchByISBN(string ISBN)
{
	auto item = find_if(catalogue.begin(), catalogue.end(), [ISBN](const Edition* a) {
		return a->getISBN() == ISBN;
		});
	if (item != catalogue.end()) {
		return *item;
	}
	else {
		return nullptr;
	}
}
