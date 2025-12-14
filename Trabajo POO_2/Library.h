#pragma once
#include "Catalog.h"
#include "User.h"
#include "Loan.h"
#include <vector>
#include <map>

/*
 * Library orquesta catálogo, usuarios y préstamos y expone operaciones
 * tipo CLI (menú). [file:1]
 */
class Library {
private:
    Catalog catalog;
    std::vector<User*> users;
    std::vector<Loan*> loans;

public:
    Library();
    ~Library();

    Catalog& getCatalog() { return catalog; }

    // Gestión de usuarios.
    void addUserFromConsole();
    User* findUserByID(int id) const;

    // Gestión de ítems.
    Item* findItemByID(int id) const;

    // Lógica de préstamos.
    int maxPrestamosParaRol(const std::string& rol) const;
    void crearPrestamo();
    void devolverPrestamo();

    // Búsqueda/ordenación.
    void buscarYOrdenarPorAnioYPrestamos();

    // Reporte por rol.
    void reportePorRol() const;

    // Mostrar todos los ítems.
    void mostrarCatalogo() const { catalog.displayAll(); }

    // Menú principal de consola.
    void mostrarMenu();
    void ejecutar();
};

