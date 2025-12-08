#include "Library.h"
#include <iostream>
#include <algorithm>

void Library::addItem(Item* item) {
    catalog.addItem(item);
}

void Library::removeItem(int itemID) {
    catalog.removeItem(itemID);
}

void Library::editItem(int itemID) {
    catalog.editItem(itemID);
}

void Library::addUser() {
    std::string name, rol;
    std::cout << "Nombre: ";
    std::cin >> name;
    std::cout << "Rol: ";
    std::cin >> rol;

    int id = users.size() + 1;
    users.push_back(new User(id, name, rol));
}

void Library::blockUser(int id) {
    for (User* u : users) {
        if (u->getUserID() == id) {
            u->setSancion(20);
            return;
        }
    }
}

void Library::addLoan(Loan* loan) {
    loans.push_back(loan);
}

void Library::filterAndSortItems(int year) {
    auto items = catalog.getItems();

    std::vector<Item*> filtered;
    for (Item* item : items)
        if (item->getYearPublished() > year)
            filtered.push_back(item);

    std::sort(filtered.begin(), filtered.end(),
        [](Item* a, Item* b) {
            return a->getNumerodePrestamos() > b->getNumerodePrestamos();
        });

    for (Item* item : filtered) item->displayCategory();
}

Catalog& Library::getCatalog() {
    return catalog;
}