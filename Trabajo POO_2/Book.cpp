#include "Book.h"
#include <iostream>

Book::Book(int itemID,
    const std::string& title,
    const std::string& author,
    int yearPublished,
    int numerodePrestamos)
    : Item(itemID, title, "Book", yearPublished, numerodePrestamos),
    author(author) {
}

void Book::imprimirDetalles() const {
    std::cout << "[BOOK] ID: " << itemID
        << " | Título: " << title
        << " | Autor: " << author
        << " | Año: " << yearPublished
        << " | Préstamos: " << numerodePrestamos
        << " | Disponible: " << (isAvailable ? "Sí" : "No")
        << std::endl;
}

std::string Book::info() const {
    return "Book: " + title + " (" + author + ")";
}
