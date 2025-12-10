#pragma once
#include "User.h"
#include "Item.h"
#include "Fecha.h"

/*
 * Loan vincula un User* y un Item* con fechas de inicio, límite y devolución.
 * Los punteros no son propietarios, solo referencian objetos existentes. [file:1]
 */
class Loan {
private:
    User* user;       // Usuario que realiza el préstamo.
    Item* item;       // Ítem prestado.
    Fecha inicio;     // Fecha de inicio.
    Fecha limite;     // Fecha límite.
    Fecha devolucion; // Fecha de devolución.
    bool devuelto{ false };

public:
    Loan(User* user,
        Item* item,
        const Fecha& inicio,
        const Fecha& limite);

    User* getUser() const { return user; }
    Item* getItem() const { return item; }
    bool estaDevuelto() const { return devuelto; }

    // Registra la devolución, calcula retraso y añade sanción (A1). [file:1]
    void devolver(const Fecha& fechaDevolucion);
};
