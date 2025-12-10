#include "Loan.h"

Loan::Loan(User* user,
    Item* item,
    const Fecha& inicio,
    const Fecha& limite)
    : user(user),
    item(item),
    inicio(inicio),
    limite(limite),
    devolucion(),
    devuelto(false) {
}

void Loan::devolver(const Fecha& fDevolucion) {
    devolucion = fDevolucion;
    devuelto = true;

    // Marcar ítem disponible y bajar préstamos activos del usuario
    if (item) item->setAvailable(true);
    if (user) user->decrementarPrestamosActivos();

    // Calcular días de retraso: si devolucion es después de limite
    int diasRetraso = limite.diasDiferencia(devolucion); // >0 si hay retraso
    if (diasRetraso > 0 && user) {
        double multa = diasRetraso * 0.10;
        if (multa > 15.0) multa = 15.0;
        user->anadirSancion(multa);  // método que acumula la sanción en el usuario
    }
}
