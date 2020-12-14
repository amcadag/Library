#pragma once

#include "Book.h"
#include <vector>

class Inventory
{
private:
	std::vector<Book> Books; //vector of type Book, named Books
public:
	Inventory();

	int MaxBookId;
	int GetNextBookId();
	int NumberOfBooks();
	Book* GetBookByIndex(int index);
	void AddBook(Book book);
	void RemoveBook(std::string title);
	int FindBookByTitle(std::string title); //return type is Book
	void CheckOutBook(Book* book);
	void CheckInBook(Book* book);

};

