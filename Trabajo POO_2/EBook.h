#pragma once
#include "Item.h"
#include "Fecha.h"

/*
 * Variante B1: EBook con licencia y fecha de expiración.
 */
class EBook : public Item {
private:
    std::string author;   // Autor del eBook.
    std::string license;  // Texto de licencia (ej. "Campus").
    Fecha expiryDate;     // Fecha de expiración de la licencia.

public:
    EBook(int itemID,
        const std::string& title,
        const std::string& author,
        const std::string& license,
        const Fecha& expiryDate,
        int yearPublished,
        int numerodePrestamos);

    void imprimirDetalles() const override;
    std::string info() const override;

    const Fecha& getExpiryDate() const { return expiryDate; }
    const std::string& getAuthor() const { return author; }
};

