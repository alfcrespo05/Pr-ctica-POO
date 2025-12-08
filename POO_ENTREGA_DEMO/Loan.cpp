#include "Loan.h"

Loan::Loan(User* u, Item* it, const Fecha& i, const Fecha& l, const Fecha& d)
    : user(u), item(it), inicio(i), limite(l), devolucion(d) {
}

void Loan::calcularDiasRetraso() {
    int dias = devolucion.calcularDiasDiferencia(limite);
    if (dias > 0) {
        user->setSancion(dias);
    }
}
