#include "Catalog.h"
#include "user.h"
#include "Loan.h"
#include <vector>
#include <iostream>

class Library {
	private:
	Catalog catalog;
	std::vector<User*> users;
	std::vector<Loan*> loans;
	std::vector<Item*> items;
public:
	//Constructor por defecto automatico
	Library() = default;
	
	//Añadir ítem
	void addItem(Item* item) {
		catalog.addItem(item);
	}

	//Quitar ítem
	void removeItem(int itemID) {
		catalog.removeItem(itemID);
	}

	//Editar ítem
	void editItem(int itemID) {
		catalog.editItem(itemID);
	}

	//Mostrar ítems
	void displayItems() {
		for (Item* item : items) {
			item->displayCategory();
		}
	}

	//Añadir usuario
	void addUser() {
		std::string name;
		std::string rol;
		
		std::cout << "Ingresa el nombre del usuario: ";
		std::cin >> name;
		std::cout << "Ingresa el rol del usuario (estudiante/profesor): ";
		std::cin >> rol;
		int userID = users.size() + 1; // Generar un ID único basado en el tamaño actual del vector
		User* newUser = new User(userID, name, rol);
		users.push_back(newUser);
	}

	//blockear usuario
	void blockUser(int userID) {
		//El ID de usuario no puede ser menor de 1 o mayor que el tamaño de la lista de usuarios
		if (userID < 1 || userID > users.size()) {
			std::cout << "ID de usuario inválido." << std::endl;
			return;
		}
		int userID;
		std::cout << "Ingresa el ID del usuario a bloquear: ";
		std::cin >> userID;
		User* user = users[userID];
		if (user->isBlocked()) {
			std::cout << "El usuario con ID " << userID << " estaba ya bloqueado." << std::endl;
		} 
		else {
			user->setSancion(11); // Establecer sanción mayor a 10 para bloquear
		}
	}


	//Añadir préstamo
	void addLoan(Loan* loan) {
		loans.push_back(loan);
	}
	//Acceder al catálogo
	Catalog& getCatalog() {
		return catalog;
	}
};
#pragma once
