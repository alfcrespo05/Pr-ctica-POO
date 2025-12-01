#pragma once
#include "Item.h"
#include <string>
class Book : public Item {
	private:
	std::string author;
public:
	//Constructor
	Book(int itemID, std::string title, std::string author, int yearPublished, int numerodePrestamos)
		: Item(itemID, title, "Book", yearPublished, numerodePrestamos), author(author) {
	};

	void imprimirDetalles() const {
		std::cout << "Book Title: " << title << ", Author: " << author << ", Year Published: " << yearPublished << ", Number of Loans: " << numerodePrestamos << std::endl;
	}
};
