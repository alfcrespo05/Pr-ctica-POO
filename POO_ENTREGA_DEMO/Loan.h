#pragma once
#include "User.h"
#include "Item.h"
#include "Fecha.h"

class Loan {
private:
    User* user;
    Item* item;
    Fecha inicio;
    Fecha limite;
    Fecha devolucion;

public:
    Loan(User* user, Item* item, const Fecha& inicio, const Fecha& limite, const Fecha& devolucion);

    void calcularDiasRetraso();
};
