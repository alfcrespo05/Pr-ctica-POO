#include <vector>
#include <string>
#include "item.h"

class Catalog {
private:
    std::vector<Item*> items; // almacena punteros a Item

public:
    // Cargar items desde un CSV
    //void loadFromCSV(const std::string& filename);
   
	//constructor por defecto automático
    Catalog() = default;

	//destructor para liberar memoria
	

    // Añadir un Item* (por si quieres añadir a mano)
   //Añadir ítem
	void addItem(Item* item) {
		std::string title;
		std::string category;
		std::string author_or_editor;
		int yearPublished;
		int numerodePrestamos;
		int itemID = items.size() + 1; // Generar un ID único basado en el tamaño actual del vector
		std::cout << "Ingresa el título del ítem: ";
		std::cin >> title;
		std::cout << "Ingresa la categoría del ítem (Book/Journal/EBook): ";
		std::cin >> category;
		std::cout << "Ingresa el autor o editor del ítem: ";
		std::cin >> author_or_editor;
		std::cout << "Ingresa el año de publicación del ítem: ";
		std::cin >> yearPublished;
		std::cout << "Ingresa el número de préstamos del ítem: ";
		std::cin >> numerodePrestamos;

		items.push_back(item);
	}

	//Quitar item
	void removeItem(int itemID) {
		std::cout << "Indique el ID del ítem a eliminar: ";
		std::cin >> itemID;
		items.erase(items.begin() + itemID);
	}


	//Editar ítem
	void editItem(int itemID) {
		std::string title;
		std::string category;
		std::string author_or_editor;
		int yearPublished = 0;
		int numerodePrestamos = 0;
		std::cout << "Indique el ID del ítem a editar: ";
		std::cin >> itemID;
		
		std::cout << itemID << " " << title << " " << category << " " << author_or_editor << " " << yearPublished << " " << numerodePrestamos << std::endl;
		std::cout << "1) Título\n2) Categoría\n3) Autor/Editor\n4) Año de publicación\n5) Número de préstamos\nSeleccione el campo a editar: ";
		int choice;
		std::cin >> choice;
		switch (choice) {
			case 1:
			std::cout << "Nuevo título: ";
			std::cin >> title;
			break;
			case 2:
				std::cout << "Nueva categoría: ";
				std::cin >> category;
				break;
			case 3:
				std::cout << "Nuevo autor/editor: ";
				std::cin >> author_or_editor;
				break;
			case 4:
				std::cout << "Nuevo año de publicación: ";
				std::cin >> yearPublished;
				break;
			case 5:
				std::cout << "Nuevo número de préstamos: ";
				std::cin >> numerodePrestamos;
				break;
			default:
				std::cout << "Opción inválida." << std::endl;
				return;

		}
	}
};



#pragma once
