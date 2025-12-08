#include "Book.h"
#include <iostream>

Book::Book(int itemID, std::string title, std::string author,
    int yearPublished, int numerodePrestamos)
    : Item(itemID, title, "Book", yearPublished, numerodePrestamos),
    author(author) {
}

void Book::imprimirDetalles() const {
    std::cout << "Book Title: " << title
        << ", Author: " << author
        << ", Year Published: " << yearPublished
        << ", Loans: " << numerodePrestamos << "\n";
}

std::string Book::info() const {
    return "Book: " + title + " (" + author + ")";
}
