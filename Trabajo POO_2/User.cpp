#include "User.h"
//Constructor de User
User::User(int userID, const std::string& name, const std::string& rol)
    : userID(userID), name(name), rol(rol) {
}
//Funcion para añadir préstamos activos,para que en caso de que no sea un rol válido no se pueda realizar la prestación
void User::incrementarPrestamosActivos() {
    ++prestamosActivos;
}
//Si devuelve un libro se resta 1 a los préstamos activos.
void User::decrementarPrestamosActivos() {
    if (prestamosActivos > 0) --prestamosActivos;
}
//Añade sanción al usuario,con limite de 15.
void User::anadirSancion(double importe) {
    sancion += importe;
    if (sancion > 15.0) sancion = 15.0;
}
//Si la sancion supera el 10 ,usuario bloqueado.
bool User::isBlocked() const {
    return sancion > 10.0;
}

