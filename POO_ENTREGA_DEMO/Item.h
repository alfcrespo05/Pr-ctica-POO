#pragma once
#include <iostream>
#include <string>

class Book;
class Journal;
class EBook;

class Item {
protected:
    int yearPublished{};
    int numerodePrestamos{};
    std::string title{};
    int itemID{};
    std::string category{};
    bool isAvailable{ true };

public:
    virtual ~Item() {}
    Item(int itemID, std::string title, std::string category, int yearPublished, int numerodePrestamos);
    Item();

    virtual std::string info() const = 0;

    void displayCategory();

    int getYearPublished() const { return yearPublished; }
    int getNumerodePrestamos() const { return numerodePrestamos; }

    int getItemID() const { return itemID; }
    std::string getCategory() const { return category; }
};
