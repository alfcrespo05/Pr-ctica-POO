#include "user.h"
#include "item.h"
#include "fecha.h"

class Loan : public User {//Clase préstamo que hereda de User para heredar la sancion del usuario
private:
	User* userID; //Puntero al ID del usuario que realiza el préstamo 
	Item* itemID; //Puntero al ID del ítem prestado
	Fecha Inicio;//Fecha de inicio del préstamo
	Fecha Límite;//Fecha de fin del préstamo
	Fecha Devolución;//Fecha de devolución del ítem

public:
	//Constructor
	Loan(User* userID, Item* item, const Fecha& inicio, const Fecha& limite,Fecha& devolucion)
		: userID(userID), itemID(itemID), Inicio(inicio), Límite(limite),  Devolución(devolucion){
	};
	//Leer CSV. Ej: 1(Usuario1),1(Item 1),2023-10-01(inicio),2023-10-15(Límite),2023-10-20(Devolución)

	//Calcular dias de retraso y aplicar sanción
	void calcularDiasRetraso() {
		Devolución.calcularDiasRetraso(Devolución, Límite);
	}
}; 

#pragma once
