#include "Item.h"
#include "Book.h"
#include "Journal.h"
#include "EBook.h"

Item::Item(int itemID, std::string title, std::string category,
    int yearPublished, int numerodePrestamos)
    : itemID(itemID), title(title), category(category),
    yearPublished(yearPublished), numerodePrestamos(numerodePrestamos) {
}

Item::Item() : itemID(0), title(""), category(""), yearPublished(0), numerodePrestamos(0) {}

void Item::displayCategory() {
    if (category == "Book") {
        Book* book = dynamic_cast<Book*>(this);
        if (book) book->imprimirDetalles();
    }
    else if (category == "Journal") {
        Journal* journal = dynamic_cast<Journal*>(this);
        if (journal) journal->imprimirDetalles();
    }
    else if (category == "EBook") {
        EBook* ebook = dynamic_cast<EBook*>(this);
        if (ebook) ebook->imprimirDetalles();
    }
    else {
        std::cout << "Unknown category.\n";
    }
}
