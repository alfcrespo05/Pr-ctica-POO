#pragma once
#include "Item.h"

/*
 * Clase concreta Journal que representa una revista científica. [file:1]
 */
class Journal : public Item {
private:
    std::string editor; // Nombre de la revista/editor.

public:
    Journal(int itemID,
        const std::string& title,
        const std::string& editor,
        int yearPublished,
        int numerodePrestamos);

    void imprimirDetalles() const override;
    std::string info() const override;

    const std::string& getEditor() const { return editor; }
};
