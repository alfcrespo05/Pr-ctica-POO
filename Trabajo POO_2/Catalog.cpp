#include "Catalog.h"
#include "Book.h"
#include "Journal.h"
#include "EBook.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

Catalog::~Catalog() {
    for (Item* item : items) {
        delete item;
    }
}

void Catalog::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo abrir el fichero " << filename << std::endl;
        return;
    }

    std::string line;
    char delim = ',';

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string s_id, title, s_isAvailable, category, s_year, s_prestamos;

        // --------- CAMPOS BÁSICOS ---------
        if (!std::getline(ss, s_id, delim) ||
            !std::getline(ss, title, delim) ||
            !std::getline(ss, s_isAvailable, delim) ||
            !std::getline(ss, category, delim) ||
            !std::getline(ss, s_year, delim) ||
            !std::getline(ss, s_prestamos, delim))
        {
            std::cerr << "Línea CSV mal formada: " << line << std::endl;
            continue;
        }

        int id = 0;
        int year = 0;
        int nPrestamos = 0;

        try {
            id = std::stoi(s_id);
            year = std::stoi(s_year);
            nPrestamos = std::stoi(s_prestamos);
        }
        catch (const std::exception&) {
            std::cerr << "Error convirtiendo números en línea: " << line << std::endl;
            continue;
        }

        // --------- CAMPOS EXTRA SEGÚN TIPO ---------
        std::string author, editor, format;

        if (category == "Book") {
            std::getline(ss, author, delim);
            if (author.empty()) author = "Desconocido";
        }
        else if (category == "Journal") {
            std::getline(ss, editor, delim);
            if (editor.empty()) editor = "Desconocido";
        }
        else if (category == "EBook") {
            std::getline(ss, author, delim);
            std::getline(ss, format, delim);

            if (author.empty()) author = "Desconocido";
            if (format.empty()) format = "PDF";
        }
        else {
            std::cerr << "Categoría desconocida en CSV: " << category << std::endl;
            continue;
        }

        // --------- CONSTRUCCIÓN DEL OBJETO ---------
        Item* item = nullptr;

        if (category == "Book") {
            item = new Book(id, title, author, year, nPrestamos);
        }
        else if (category == "Journal") {
            item = new Journal(id, title, editor, year, nPrestamos);
        }
        else if (category == "EBook") {
            Fecha expiry(31, 12, 2099);
            item = new EBook(id, title, author, format, expiry, year, nPrestamos);
        }

        items.push_back(item);
    }

    if (file.bad()) {
        std::cerr << "Error de lectura en el fichero " << filename << std::endl;
    }

    file.close();
}

void Catalog::addItem(Item* item) {
    if (item) items.push_back(item);
}

std::vector<Item*> Catalog::filterAndSortByYearAndLoans(int year) const {
    std::vector<Item*> filtered;

    for (Item* item : items) {
        if (item && item->getYearPublished() > year) {
            filtered.push_back(item);
        }
    }

    std::sort(filtered.begin(), filtered.end(),
        [](Item* a, Item* b) {
            return a->getNumerodePrestamos() > b->getNumerodePrestamos();
        });

    return filtered;
}

void Catalog::displayAll() const {
    for (Item* item : items) {
        if (item) item->imprimirDetalles();
    }
}
