#include "Item.h"
class Journal : public Item {
	private:
	std::string editor;
public:
	//Constructor
	Journal(int itemID, std::string title, std::string editor, int yearPublished, int numerodePrestamos)
		: Item(itemID, title, "Journal", yearPublished, numerodePrestamos), editor(editor) {
	};

	void imprimirDetalles() const {
		std::cout << "Journal Title: " << title << ", Editor: " << editor << ", Year Published: " << yearPublished << ", Number of Loans: " << numerodePrestamos << std::endl;
	}
	
};
#pragma once