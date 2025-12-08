#include "User.h"

User::User(int userID, const std::string& name, const std::string& rol)
    : userID(userID), name(name), rol(rol), sancion(0) {
}

void User::setSancion(int dias) {
    sancion += dias;
}

bool User::isBlocked() const {
    return sancion > 10;
}
