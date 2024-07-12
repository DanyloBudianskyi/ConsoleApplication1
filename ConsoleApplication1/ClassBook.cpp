#include "ClassBook.h"

ClassBook::ClassBook()
{
    level = 1;
}

ClassBook::ClassBook(string ISBN, string title, string author, int year, string publisher, int level)
    : Book(ISBN, title, author, year, publisher)
{
    this->level = level;
}

void ClassBook::setLevel(int level)
{
    this->level = level;
}

int ClassBook::getLevel() const
{
    return level;
}

void ClassBook::showInfo() const
{
    cout << "Class book: " << endl;
    cout << "\tTitle: " << title << endl;
    cout << "\tAuthor: " << author << endl;
    cout << "\tYear: " << year << endl;
    cout << "\tISBN: " << ISBN << endl;
    cout << "\tPublisher: " << publisher << endl;
    cout << "\tClass: " << level << endl << endl;
}
