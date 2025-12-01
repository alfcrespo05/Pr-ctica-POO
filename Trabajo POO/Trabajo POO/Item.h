#pragma once
#include <iostream>
#include "Book.h"
#include "Journal.h"
#include "EBook.h"
class Item {
protected:
	virtual ~Item() {};//Destructor virtual
	virtual std::string info() const = 0;//Método puro virtual para obtener información del ítem
	int yearPublished;
	int numerodePrestamos;
	std::string title;
private:
	int itemID;
	bool isAvailable;
	std::string category;

public:
	//Leer CSV. Ej: 1,Item1,true,Book,2020,5
	
	//Constructor
	Item(int itemID, std::string title,std::string category,int yearPublished,int numerodePrestamos)
		: itemID(itemID), title(title), isAvailable(true), category(category), yearPublished(yearPublished), numerodePrestamos(numerodePrestamos) {
	};
	//Constructor por defecto
	Item()
		: itemID(0), title(""), isAvailable(true), category("") {
	};
		void displayCategory() {
			if(category == "Book") {
				Book* book = dynamic_cast<Book*>(this);
				if(book) {
					book->imprimirDetalles();
				}
			} else if(category == "Journal") {
				Journal* journal = dynamic_cast<Journal*>(this);
				if(journal) {
					journal->imprimirDetalles();
				}
			} else if(category == "EBook") {
				EBook* ebook = dynamic_cast<EBook*>(this);
				if(ebook) {
					ebook->imprimirDetalles();
				}
			} else {
				std::cout << "Unknown category." << std::endl;
			}
		}
};

