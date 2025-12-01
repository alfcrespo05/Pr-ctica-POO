#pragma once
#include "Item.h" 
#include <string>
class EBook : public Item {
	private:
	std::string author; // Autor del eBook
	std::string format; // Formato del eBook (e.g., PDF, EPUB)
public:
	//Constructor
	EBook(int itemID, std::string title, std::string author, std::string format, int yearPublished, int numerodePrestamos)
		: Item(itemID, title, "EBook", yearPublished, numerodePrestamos), author(author), format(format) {
	};

	void imprimirDetalles() const {
		std::cout << "EBook Title: " << title << ", Author: " << author << ", Format: " << format << ", Year Published: " << yearPublished << ", Number of Loans: " << numerodePrestamos << std::endl;
	}
};