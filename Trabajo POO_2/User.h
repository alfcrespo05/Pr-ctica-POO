#pragma once
#include <string>

/*
 * Clase User que representa a un usuario de la biblioteca.
 * Rol: Estudiante, PDI, PAS(cada uno de ellos tiene distinto límite de préstamos); sanción acumulada en euros.
 */
class User {
private:
    int userID{};            // Identificador único.ID ordenado por orden de creación
    std::string name;        // Nombre.
    std::string rol;         // Rol (Estudiante, PDI, PAS).
    double sancion{ 0.0 };     // Importe acumulado de sanción (A1).Double para que pueda tener los céntimos.
    int prestamosActivos{ 0 }; // Número de préstamos activos.

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

    // Añade importe a la sanción, con tope máximo de 15 €.
    void anadirSancion(double importe);

    // Usuario bloqueado si sanción > 10 €.
    bool isBlocked() const;
};

