#pragma once
#include "Item.h"

/*
 * Clase concreta Book que representa un libro físico. 
 */
class Book : public Item {
private:
    std::string author; // Autor del libro.

public:
    Book(int itemID,
        const std::string& title,
        const std::string& author,
        int yearPublished,
        int numerodePrestamos);

    void imprimirDetalles() const override;
    std::string info() const override;

    const std::string& getAuthor() const { return author; }
};

