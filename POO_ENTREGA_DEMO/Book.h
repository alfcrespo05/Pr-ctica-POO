#pragma once
#include "Item.h"
#include <string>

class Book : public Item {
private:
    std::string author;

public:
    Book(int itemID, std::string title, std::string author,
        int yearPublished, int numerodePrestamos);

    void imprimirDetalles() const;
    std::string info() const override;
};
