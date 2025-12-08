#include "EBook.h"
#include <iostream>

EBook::EBook(int itemID, std::string title, std::string author, std::string format,
    int yearPublished, int numerodePrestamos)
    : Item(itemID, title, "EBook", yearPublished, numerodePrestamos),
    author(author), format(format) {
}

void EBook::imprimirDetalles() const {
    std::cout << "EBook Title: " << title
        << ", Author: " << author
        << ", Format: " << format
        << ", Year Published: " << yearPublished
        << ", Loans: " << numerodePrestamos << "\n";
}

std::string EBook::info() const {
    return "EBook: " + title + " (" + author + ", " + format + ")";
}
