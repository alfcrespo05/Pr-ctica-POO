#pragma once
#include "Item.h"
#include <string>

class EBook : public Item {
private:
    std::string author;
    std::string format;

public:
    EBook(int itemID, std::string title, std::string author, std::string format,
        int yearPublished, int numerodePrestamos);

    void imprimirDetalles() const;
    std::string info() const override;
};
