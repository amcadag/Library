#pragma once //only loads .h file once

#include <iostream>

class Book
{
public:
	int Id;
	std::string Title;
	std::string Author;
	bool CheckedOut;

	Book();
	Book(int id, std::string title, std::string author); //constructor, automatically called when new object is made


	//overload operator so we can use 'find' properly
	bool operator==(const Book &book) const //operator overload to compare each book object
	{
		if (Title.compare(book.Title) == 0) //can also add Author.compare, etc. 
			return true;
		else
			return false;
	}
};

