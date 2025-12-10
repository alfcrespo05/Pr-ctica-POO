#include "User.h"

User::User(int userID, const std::string& name, const std::string& rol)
    : userID(userID), name(name), rol(rol) {
}

void User::incrementarPrestamosActivos() {
    ++prestamosActivos;
}

void User::decrementarPrestamosActivos() {
    if (prestamosActivos > 0) --prestamosActivos;
}

void User::anadirSancion(double importe) {
    sancion += importe;
    if (sancion > 15.0) sancion = 15.0;
}

bool User::isBlocked() const {
    return sancion > 10.0;
}
