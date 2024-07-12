#pragma once
#include "Book.h"
class ClassBook : public Book
{
protected:
	int level;
public:
	ClassBook();
	ClassBook(string ISBN, string title, string author, int year, string publisher, int level);

	void setLevel(int level);
	int getLevel()const;

	void showInfo()const override;
};

