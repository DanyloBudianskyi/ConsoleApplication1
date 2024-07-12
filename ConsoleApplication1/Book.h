#pragma once
#include "Edition.h"
class Book : public Edition
{
protected:
	string publisher;
public:
	Book();
	Book(string ISBN, string title, string author, int year, string publisher);

	void setPublisher(string publisher);
	string getPublisher()const;

	void showInfo()const override;
};

