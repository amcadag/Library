#include "Book.h"

Book::Book() //to create dummy book object for testing
{

}

Book::Book(int id, std::string title, std::string author) //constructor definition
{
	Book::Id = id;					//capitalized refer to class variables
	Book::Title = title;			//lower cases are input paramters used to fill in class variables
	Book::Author = author;
	Book::CheckedOut = false;
}
