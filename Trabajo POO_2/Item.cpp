#include "Item.h"
#include "Book.h"
#include "Journal.h"
#include "EBook.h"

Item::Item(int itemID,
    const std::string& title,
    const std::string& category,
    int yearPublished,
    int numerodePrestamos)
    : itemID(itemID),
    title(title),
    category(category),
    yearPublished(yearPublished),
    numerodePrestamos(numerodePrestamos),
    isAvailable(true) {
}

// Usa la categoría para intentar convertir al tipo derivado correcto.
void Item::displayCategory() {
    if (category == "Book") {
        if (auto* book = dynamic_cast<Book*>(this)) {
            book->imprimirDetalles();
        }
    }
    else if (category == "Journal") {
        if (auto* journal = dynamic_cast<Journal*>(this)) {
            journal->imprimirDetalles();
        }
    }
    else if (category == "EBook") {
        if (auto* ebook = dynamic_cast<EBook*>(this)) {
            ebook->imprimirDetalles();
        }
    }
    else {
        std::cout << "Unknown category.\n";
    }
}
