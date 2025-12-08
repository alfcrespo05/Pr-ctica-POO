#pragma once
#include <vector>
#include "Catalog.h"
#include "User.h"
#include "Loan.h"

class Library {
private:
    Catalog catalog;
    std::vector<User*> users;
    std::vector<Loan*> loans;

public:
    Library() = default;

    void addItem(Item* item);
    void removeItem(int itemID);
    void editItem(int itemID);

    void addUser();
    void blockUser(int userID);

    void addLoan(Loan* loan);

    void filterAndSortItems(int year);

	Catalog& getCatalog();
};
