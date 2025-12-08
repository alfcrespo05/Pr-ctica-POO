#pragma once
#include "Item.h"
#include <string>

class Journal : public Item {
private:
    std::string editor;

public:
    Journal(int itemID, std::string title, std::string editor,
        int yearPublished, int numerodePrestamos);

    void imprimirDetalles() const;
    std::string info() const override;
};
