#pragma once
#include <vector>
#include <string>
#include "Item.h"

class Catalog {
private:
    std::vector<Item*> items;

public:
    Catalog() = default;

    void loadFromCSV(const std::string& filename);
    void addItem(Item* item);
    void removeItem(int itemID);
    void editItem(int itemID);

    const std::vector<Item*>& getItems() const { return items; }

    void showItems() const {
        for (const Item* item : items) {
            std::cout << item->info() << "\n";
        }
    }
};
