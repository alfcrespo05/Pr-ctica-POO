#pragma once
#include <vector>
#include <string>
#include "Item.h"

/*
 * Catalog almacena y gestiona todos los Item* de la biblioteca.
 * Es propietario de los ítems y se encarga de liberarlos. [file:1]
 */
class Catalog {
private:
    std::vector<Item*> items;

public:
    Catalog() = default;
    ~Catalog(); // Libera los Item*.

    const std::vector<Item*>& getItems() const { return items; }

    void loadFromCSV(const std::string& filename);
    void addItem(Item* item);

    // Variante E2: filtro por año y orden por nº de préstamos desc. [file:1]
    std::vector<Item*> filterAndSortByYearAndLoans(int year) const;

    void displayAll() const;
};
