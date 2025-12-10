#include "Journal.h"
#include <iostream>

Journal::Journal(int itemID,
    const std::string& title,
    const std::string& editor,
    int yearPublished,
    int numerodePrestamos)
    : Item(itemID, title, "Journal", yearPublished, numerodePrestamos),
    editor(editor) {
}

void Journal::imprimirDetalles() const {
    std::cout << "[JOURNAL] ID: " << itemID
        << " | Título: " << title
        << " | Editor: " << editor
        << " | Año: " << yearPublished
        << " | Préstamos: " << numerodePrestamos
        << " | Disponible: " << (isAvailable ? "Sí" : "No")
        << std::endl;
}

std::string Journal::info() const {
    return "Journal: " + title + " (" + editor + ")";
}
