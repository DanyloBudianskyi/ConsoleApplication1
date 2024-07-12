#pragma once
#include <iostream>
#include <string>
using namespace std;

class Edition
{
protected:
	string ISBN;
	string title;
	string author;
	int year;
public:
	Edition();
	Edition(string ISBN, string title, string author, int year);
	virtual ~Edition() {};

	void setISBN(string ISBN);
	void setTitle(string title);
	void setAuthor(string author);
	void setYear(int year);

	string getISBN()const;
	string getTitle()const;
	string getAuthor()const;
	int getYear()const;

	virtual void showInfo()const = 0;
};

