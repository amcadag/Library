#pragma once

#include "Book.h"
#include <vector>

class Inventory
{
public:
	std::vector<Book> Books; //vector of type Book, named Books

	void AddBook(Book book);
	void RemoveBook(std::string title);
	int FindBookByTitle(std::string title); //return type is Book
	void CheckOutBook(Book* book);
	void CheckInBook(Book* book);

};

