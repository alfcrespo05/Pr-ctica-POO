#pragma once
#include <iostream>
#include <string>

class User {
protected:
	int userID;
	int sancion;
private:
	std::string name;
	std::string rol;

public:
	//Leer CSV. Ej: 1,Usuario1,estudiante.

	//Constructor
	User(int userID, std::string name, std::string rol)
		: userID(userID), name(name), rol(rol), sancion(0) {
	};
	
	//Constructor por defecto 
	User()
		: userID(0), name(""), rol(""), sancion(0) {
	};

	//Estado sancion
	void setSancion(int dias) {
		sancion += 0, 1 * dias;//EN € SE ASUME QUE CADA DÍA DE SANCION AUMENTA EN 0.1 LA SANCIÓN TOTAL
	};

	//Bloquear préstamo
	bool isBlocked() const {
		return sancion > 10;

	}


};
