#include "Inventory.h"
#include <vector>
#include <iostream>
#include <string>

void Inventory::AddBook(Book book) //push book to vector
{
	Inventory::Books.push_back(book); //Books is a vector; push_back pushes book variable onto the vector
}

void Inventory::RemoveBook(std::string title) 
{
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));
	if (it != Inventory::Books.end()) //finds book at iterator it
	{
		Inventory::Books.erase(it); //then erases book at iterator it

	}

	
}

int Inventory::FindBookByTitle(std::string title)
{
	//compares book to a refernce book, and tries to find a match
	std::vector<Book>::iterator it = std::find(Inventory::Books.begin(), Inventory::Books.end(), Book(0, title, ""));
	if (it == Inventory::Books.end()) 
	{
		return -1; //if we got past the end, and nothing was found
	
	}

	int index = it - Inventory::Books.begin(); //find where iterator it is, offset from beginning

	return index;
}

void Inventory::CheckOutBook(Book* book)
{
	book->CheckedOut = true;
}
void Inventory::CheckInBook(Book* book)
{
	book->CheckedOut = false;
}
