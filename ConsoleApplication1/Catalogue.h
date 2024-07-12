#pragma once
#include "Magazine.h"
#include "Book.h"
#include "ClassBook.h"
#include <set>
#include <algorithm>

struct MyCmp
{
	bool operator()(const Edition* left, const Edition* right)const {
		return left->getTitle() < right->getTitle();
	}
};

class Catalogue
{
	set<Edition*, MyCmp> catalogue;
public:
	Catalogue();
	~Catalogue();

	void showInfo()const;
	void addEdition(Edition* obj);
	void delEdition(string ISBN);
	Edition* searchByISBN(string ISBN);
};

