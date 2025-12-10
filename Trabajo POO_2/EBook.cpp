#include "EBook.h"
#include <iostream>

EBook::EBook(int itemID,
    const std::string& title,
    const std::string& author,
    const std::string& license,
    const Fecha& expiryDate,
    int yearPublished,
    int numerodePrestamos)
    : Item(itemID, title, "EBook", yearPublished, numerodePrestamos),
    author(author),
    license(license),
    expiryDate(expiryDate) {
}

void EBook::imprimirDetalles() const {
    std::cout << "[EBOOK] ID: " << itemID
        << " | Título: " << title
        << " | Autor: " << author
        << " | Licencia: " << license
        << " | Expira: ";
    expiryDate.imprimir();
    std::cout << " | Año pub.: " << yearPublished
        << " | Préstamos: " << numerodePrestamos
        << " | Disponible: " << (isAvailable ? "Sí" : "No")
        << std::endl;
}

std::string EBook::info() const {
    return "EBook: " + title + " (" + author + ", licencia: " + license + ")";
}
