#include "Magazine.h"

Magazine::Magazine()
{
    number = 0;
}

Magazine::Magazine(string ISBN, string title, string author, int year, int number)
    : Edition(ISBN, title, author, year)
{
    this->number = number;
}

void Magazine::setNumber(int number)
{
    this->number = number;
}

int Magazine::getNumber() const
{
    return number;
}

void Magazine::showInfo() const
{
    cout << "Magazine: " << endl;
    cout << "\tTitle: " << title << endl;
    cout << "\tAuthor: " << author << endl;
    cout << "\tYear: " << year << endl;
    cout << "\tISBN: " << ISBN << endl;
    cout << "\tNumber: " << number << endl << endl;
}
