#include "Book.h"

Book::Book()
{
    publisher = "undefined";
}

Book::Book(string ISBN, string title, string author, int year, string publisher)
    : Edition(ISBN, title, author, year)
{
    this->publisher = publisher;
}

void Book::setPublisher(string publisher)
{
    this->publisher = publisher;
}

string Book::getPublisher() const
{
    return publisher;
}

void Book::showInfo() const
{
    cout << "Book: " << endl;
    cout << "\tTitle: " << title << endl;
    cout << "\tAuthor: " << author << endl;
    cout << "\tYear: " << year << endl;
    cout << "\tISBN: " << ISBN << endl;
    cout << "\tPublisher: " << publisher << endl << endl;
}
