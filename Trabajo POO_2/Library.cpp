#include "Library.h"
#include "EBook.h"
#include <iostream>

Library::Library() = default;

Library::~Library() {
    for (User* u : users) delete u;
    for (Loan* l : loans) delete l;
}

void Library::addUserFromConsole() {
    std::string name;
    std::string rol;

    std::cout << "Nombre del usuario: ";
    std::getline(std::cin >> std::ws, name);
    std::cout << "Rol (Estudiante/PDI/PAS): ";
    std::getline(std::cin >> std::ws, rol);

    int userID = static_cast<int>(users.size()) + 1;
    User* newUser = new User(userID, name, rol);
    users.push_back(newUser);

    std::cout << "Usuario creado con ID: " << userID << std::endl;
}

User* Library::findUserByID(int id) const {
    for (User* u : users) {
        if (u && u->getUserID() == id) return u;
    }
    return nullptr;
}

Item* Library::findItemByID(int id) const {
    const auto& items = catalog.getItems();
    for (Item* it : items) {
        if (it && it->getItemID() == id) return it;
    }
    return nullptr;
}

int Library::maxPrestamosParaRol(const std::string& rol) const {
    if (rol == "Estudiante") return 3;
    if (rol == "PDI") return 6;
    if (rol == "PAS") return 5;
    return 0; // Rol desconocido.
}

void Library::crearPrestamo() {
    int userID, itemID;
    std::cout << "ID de usuario: ";
    std::cin >> userID;
    std::cout << "ID de ítem: ";
    std::cin >> itemID;

    User* u = findUserByID(userID);
    Item* it = findItemByID(itemID);

    if (!u || !it) {
        std::cout << "Usuario o ítem no encontrado.\n";
        return;
    }

    if (u->isBlocked()) {
        std::cout << "Usuario bloqueado por sanción. No se puede crear préstamo.\n";
        return;
    }

    int maxPrestamos = maxPrestamosParaRol(u->getRol());
    if (u->getPrestamosActivos() >= maxPrestamos) {
        std::cout << "Límite de préstamos activos alcanzado para este usuario.\n";
        return;
    }

    if (!it->getIsAvailable()) {
        std::cout << "Ítem no disponible (ya prestado).\n";
        return;
    }

    // Check licencia EBook (opcional, aquí asumimos no expirada por defecto).
    if (EBook* ebook = dynamic_cast<EBook*>(it)) {
        // Podrías comparar expiryDate con una fecha "hoy".
        (void)ebook; // Para evitar warning si no se usa.
    }

    int d, m, a;
    std::cout << "Fecha de inicio (d m a): ";
    std::cin >> d >> m >> a;
    Fecha inicio(d, m, a);

    std::cout << "Fecha límite (d m a): ";
    std::cin >> d >> m >> a;
    Fecha limite(d, m, a);

    Loan* loan = new Loan(u, it, inicio, limite);
    loans.push_back(loan);

    it->setAvailable(false);
    u->incrementarPrestamosActivos();
    it->incrementarPrestamos();

    std::cout << "Préstamo registrado correctamente.\n";
}

void Library::devolverPrestamo() {
    int itemID;
    std::cout << "ID de ítem a devolver: ";
    std::cin >> itemID;

    for (Loan* l : loans) {
        if (l && !l->estaDevuelto() && l->getItem() &&
            l->getItem()->getItemID() == itemID) {

            int d, m, a;
            std::cout << "Fecha de devolución (d m a): ";
            std::cin >> d >> m >> a;
            Fecha devolucion(d, m, a);

            l->devolver(devolucion);
            std::cout << "Devolución registrada.\n";
            return;
        }
    }

    std::cout << "No se encontró un préstamo activo para ese ítem.\n";
}

void Library::buscarYOrdenarPorAnioYPrestamos() {
    int year;
    std::cout << "Filtrar ítems publicados después del año: ";
    std::cin >> year;

    auto filtrados = catalog.filterAndSortByYearAndLoans(year);

    std::cout << "Ítems filtrados y ordenados:\n";
    for (Item* it : filtrados) {
        if (it) it->imprimirDetalles();
    }
}

void Library::reportePorRol() const {
    std::map<std::string, int> prestamosPorRol;
    std::map<std::string, double> sancionesPorRol;

    for (User* u : users) {
        if (!u) continue;
        const std::string& rol = u->getRol();
        prestamosPorRol[rol] += u->getPrestamosActivos();
        sancionesPorRol[rol] += u->getSancion();
    }

    std::cout << "=== Reporte por rol de usuario ===\n";
    for (const auto& par : prestamosPorRol) {
        const std::string& rol = par.first;
        int prestamos = par.second;
        double sancionTotal = sancionesPorRol.at(rol);
        std::cout << "Rol: " << rol
            << " | Préstamos activos: " << prestamos
            << " | Sanción total: " << sancionTotal << " €\n";
    }
}

void Library::mostrarMenu() {
    std::cout << "\n=== Menú Biblioteca ===\n";
    std::cout << "1) Listar ítems\n";
    std::cout << "2) Añadir usuario\n";
    std::cout << "3) Crear préstamo\n";
    std::cout << "4) Devolver préstamo\n";
    std::cout << "5) Buscar/ordenar por año y nº préstamos (E2)\n";
    std::cout << "6) Reporte por rol (F2)\n";
    std::cout << "0) Salir\n";
    std::cout << "Opción: ";
}

void Library::ejecutar() {
    int opcion = -1;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            mostrarCatalogo();
            break;
        case 2:
            addUserFromConsole();
            break;
        case 3:
            crearPrestamo();
            break;
        case 4:
            devolverPrestamo();
            break;
        case 5:
            buscarYOrdenarPorAnioYPrestamos();
            break;
        case 6:
            reportePorRol();
            break;
        case 0:
            std::cout << "Saliendo...\n";
            break;
        default:
            std::cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
}
