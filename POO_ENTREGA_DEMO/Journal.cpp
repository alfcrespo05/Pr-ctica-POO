#include "Journal.h"
#include <iostream>

Journal::Journal(int itemID, std::string title, std::string editor,
    int yearPublished, int numerodePrestamos)
    : Item(itemID, title, "Journal", yearPublished, numerodePrestamos),
    editor(editor) {
}

void Journal::imprimirDetalles() const {
    std::cout << "Journal Title: " << title
        << ", Editor: " << editor
        << ", Year Published: " << yearPublished
        << ", Loans: " << numerodePrestamos << "\n";
}

std::string Journal::info() const {
    return "Journal: " + title + " (" + editor + ")";
}
