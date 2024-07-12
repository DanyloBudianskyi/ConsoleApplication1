#include "Customer.h"

Customer::Customer()
{
    name = "undefinded";
}

Customer::Customer(string name)
{
    this->name = name;
}

void Customer::setName(string name)
{
    this->name = name;
}

string Customer::getName() const
{
    return name;
}

void Customer::takeEdition(Edition* obj)
{
    if (obj == nullptr)return;
    listEd.push_back(obj);
}

Edition* Customer::returnEdition(string ISBN)
{
    auto obj = find_if(listEd.begin(), listEd.end(), [ISBN](const Edition* a) {
        return a->getISBN() == ISBN;
        });
    if (obj == listEd.end()) {
        cout << "Edition not found!" << endl;
        return nullptr;
    }
    Edition* tmp = *obj;
    listEd.erase(obj);
    return tmp;
}

void Customer::showInfo() const
{
    cout << "Name: " << name << endl;
    cout << "List: " << endl;
    for (auto item : listEd) {
        item->showInfo();
    }
    cout << endl;
}
