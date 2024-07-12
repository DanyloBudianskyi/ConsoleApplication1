#pragma once
#include "Edition.h"
class Magazine : public Edition
{
protected:
	int number;
public:
	Magazine();
	Magazine(string ISBN, string title, string author, int year, int number);

	void setNumber(int number);
	int getNumber()const;

	void showInfo()const override;
};

