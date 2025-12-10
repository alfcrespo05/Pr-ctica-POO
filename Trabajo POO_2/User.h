#pragma once
#include <string>

/*
 * Clase User que representa a un usuario de la biblioteca.
 * Rol: Estudiante, PDI, PAS; sanción acumulada en euros. [file:1]
 */
class User {
private:
    int userID{};            // Identificador único.
    std::string name;        // Nombre.
    std::string rol;         // Rol (Estudiante, PDI, PAS).
    double sancion{ 0.0 };     // Importe acumulado de sanción (A1). [file:1]
    int prestamosActivos{ 0 }; // Número de préstamos activos (C1). [file:1]

public:
    User(int userID, const std::string& name, const std::string& rol);
    User() = default;

    int getUserID() const { return userID; }
    const std::string& getName() const { return name; }
    const std::string& getRol() const { return rol; }
    double getSancion() const { return sancion; }
    int getPrestamosActivos() const { return prestamosActivos; }

    void incrementarPrestamosActivos();
    void decrementarPrestamosActivos();

    // Añade importe a la sanción, con tope máximo de 15 €. [file:1]
    void anadirSancion(double importe);

    // Usuario bloqueado si sanción > 10 €. [file:1]
    bool isBlocked() const;
};
