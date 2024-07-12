#include "Catalogue.h"
#include "Customer.h"
#include "Archive.h"
#include <Windows.h>

int main()
{
    //Catalogue library;
    //library.showInfo();
    //Customer a("Danylo");
    //a.takeEdition(library.searchByISBN("012C"));
    //a.takeEdition(library.searchByISBN("456B"));
    //library.delEdition("012C");
    //library.delEdition("456B");
    //cout << "\n-------------------------------------------\n\n";
    //a.showInfo();
    //cout << "\n-------------------------------------------\n\n";
    //library.showInfo();

    Archive ItStep;

    ItStep.regNewCustomer("Danylo");
    Sleep(1000);
    ItStep.regNewCustomer("Mio");
    Sleep(2000);
    ItStep.regNewCustomer("Lio");
    ItStep.showCustomersList();
    Time_ a;

    cout << "Input customer time: ";
    cin >> a;

    ItStep.takeEd(a, "012C");
    ItStep.showCustomersList();
    cout << "\n---------------------------\n";
    ItStep.showLibrary();
}