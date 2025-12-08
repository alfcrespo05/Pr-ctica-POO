#pragma once
#include <string>

class User {
protected:
    int sancion = 0;

private:
    int userID{};
    std::string name;
    std::string rol;

public:
    User(int userID, const std::string& name, const std::string& rol);
    User() = default;

    void setSancion(int dias);
    bool isBlocked() const;

    int getUserID() const { return userID; }
    int getSancion() const { return sancion; }
    const std::string& getName() const { return name; }
    const std::string& getRol() const { return rol; }
};
