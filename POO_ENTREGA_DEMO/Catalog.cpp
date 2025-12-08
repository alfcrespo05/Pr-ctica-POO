#include "Catalog.h"
#include "Book.h"
#include "Journal.h"
#include "EBook.h"
#include <fstream>
#include <sstream>
#include <iostream>

void Catalog::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
	// Verificar si el archivo se abrió correctamente
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo abrir " << filename << "\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string s_id, title, cat, s_year, s_loans;

        std::getline(ss, s_id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, cat, ',');
        std::getline(ss, s_year, ',');
        std::getline(ss, s_loans, ',');

        int id = stoi(s_id);
        int year = stoi(s_year);
        int loans = stoi(s_loans);

        Item* item = nullptr;

        if (cat == "Book") item = new Book(id, title, "Autor", year, loans);
        if (cat == "Journal") item = new Journal(id, title, "Editor", year, loans);
        if (cat == "EBook") item = new EBook(id, title, "Autor", "PDF", year, loans);

        if (item) items.push_back(item);
    }
}

void Catalog::addItem(Item* item) {
    items.push_back(item);
}

void Catalog::removeItem(int id) {
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i]->getItemID() == id) {
            items.erase(items.begin() + i);
            return;
        }
    }
}

void Catalog::editItem(int id) {
    for (Item* item : items) {
        if (item->getItemID() == id) {
            std::cout << "Item editable pero estructura no definida.\n";
            return;
        }
    }
}

