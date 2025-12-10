#pragma once
#include <iostream>
#include <string>

// Declaraciones adelantadas para evitar dependencias circulares.
class Book;
class Journal;
class EBook;

//Clase abstracta Item que representa un ítem genérico de la biblioteca.
class Item {
protected:
    int itemID{};               // Identificador único del ítem.
    std::string title;          // Título del ítem.
    std::string category;       // Categoría (Book, Journal, EBook, ...).
    int yearPublished{};        // Año de publicación.
    int numerodePrestamos{};    // Número total de préstamos.
    bool isAvailable{ true };     // Si está disponible para prestar.

public:
    // Destructor virtual para permitir destrucción correcta vía puntero a Item.
    virtual ~Item() = default; 

    // Devuelve una descripción breve del ítem.
    virtual std::string info() const = 0;

    // Imprime detalles completos del ítem (polimórfico).
    virtual void imprimirDetalles() const = 0;

    // Constructor principal.
    Item(int itemID,
        const std::string& title,
        const std::string& category,
        int yearPublished,
        int numerodePrestamos);

    // Constructor por defecto.
    Item() = default;

    // Getters básicos para búsquedas/ordenaciones.
    int getItemID() const { return itemID; }
    const std::string& getTitle() const { return title; }
    const std::string& getCategory() const { return category; }
    int getYearPublished() const { return yearPublished; }
    int getNumerodePrestamos() const { return numerodePrestamos; }
    bool getIsAvailable() const { return isAvailable; }

    void setAvailable(bool available) { isAvailable = available; }

    // Incrementa el contador de préstamos (se llama al crear un préstamo).
    void incrementarPrestamos() { ++numerodePrestamos; }

    // Muestra el ítem usando el tipo real (Book/Journal/EBook) con dynamic_cast.
    void displayCategory();
};
