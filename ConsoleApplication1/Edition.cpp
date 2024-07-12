#include "Edition.h"

Edition::Edition()
{
    ISBN = "12345A";
    title = "undefined";
    author = "undefined";
    year = 0;
}

Edition::Edition(string ISBN, string title, string author, int year)
{
    this->ISBN = ISBN;
    this->title = title;
    this->author = author;
    this->year = year;
}

void Edition::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

void Edition::setTitle(string title)
{
    this->title = title;
}

void Edition::setAuthor(string author)
{
    this->author = author;
}

void Edition::setYear(int year)
{
    this->year = year;
}

string Edition::getISBN() const
{
    return ISBN;
}

string Edition::getTitle() const
{
    return title;
}

string Edition::getAuthor() const
{
    return author;
}

int Edition::getYear() const
{
    return year;
}
