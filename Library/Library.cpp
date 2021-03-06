#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include <string> 

using namespace std;

Inventory _inventory; //underscore denotes global variable

void DisplayMainMenu()
{
    cout << "Choose an option:" << endl;
    cout << "1. Add book" << endl;
    cout << "2. List all books" << endl;
    cout << "3. Check out book" << endl;
    cout << "4. Check in book" << endl;
    cout << "5. Remove book from library" << endl;
    cout << "6. List all checked books" << endl;
    cout << "0. Exit" << endl;
}

void AddNewBook()
{
    cout << "Enter Title: ";
    string title;
    getline(cin, title); //getline gets multiple words, cin gets one word

    cout << "Enter Author: ";
    string author;
    getline(cin, author);

    int id = _inventory.GetNextBookId();

    Book newBook(id, title, author); //create new Book object

    _inventory.AddBook(newBook);
}

void ListAllBooks()
{
    cout << "\nID\tTitle\tAuthor" << endl;
    for (int i = 0; i < _inventory.NumberOfBooks(); i++)
    {
        cout << _inventory.GetBookByIndex(i)->Id << "\t" << _inventory.GetBookByIndex(i)->Title << "\t" << _inventory.GetBookByIndex(i)->Author << endl;
    }
    cout << endl;
}

void CheckInOrOutBook(bool checkIn)
{
    string inOrOut;
    if (checkIn)
    {
        inOrOut = "in";
    }
    else {
        inOrOut = "out";
    }

    cout << "Enter title to check " + inOrOut + ": ";
    string title;
    getline(cin, title);

    int foundBookIndex = _inventory.FindBookByTitle(title);


    if (foundBookIndex >= 0)
    {
        Book* foundBook = _inventory.GetBookByIndex(foundBookIndex); //use pointer so it is not a copy

        //if CheckedOut == false, we are checked in
        //if CheckedOut == true, we are checkout out
        if (!foundBook->CheckedOut == checkIn) { 
            cout << "Book already checked " + inOrOut + "." << endl;
            return;
        }

        if (checkIn)
        {
            _inventory.CheckInBook(foundBook);
        }
        else {
            _inventory.CheckOutBook(foundBook);
        }
        cout << "Book checked " + inOrOut + "." << endl;
    }
    else {
        cout << "Book not found." << endl;
    }
}

void RemoveBook()
{
    cout << "Enter Title: ";
    string title;
    getline(cin, title); //getline gets multiple words, cin gets one word

    _inventory.RemoveBook(title);
}

void DisplayCheckedOutbooks()
{
    cout << "\nID\tTitle\tAuthor" << endl;
    for (int i = 0; i < _inventory.NumberOfBooks(); i++)
    {
        if (_inventory.GetBookByIndex(i)->CheckedOut)
        {
            cout << _inventory.GetBookByIndex(i)->Id << "\t" << _inventory.GetBookByIndex(i)->Title << "\t" << _inventory.GetBookByIndex(i)->Author << endl;
        }
    }
    cout << endl;
}

int main()
{
    while (true)
    {
        DisplayMainMenu();

        int input;
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 0:
            cout << "Thank you, goodbye.";
            return 0;
        case 1: 
            AddNewBook();
            break;
        case 2: 
            ListAllBooks();
            break;
        case 3: 
            CheckInOrOutBook(false);
            break;
        case 4: 
            CheckInOrOutBook(true);
            break;
        case 5:
            RemoveBook();
            break;
        case 6:
            DisplayCheckedOutbooks();
            break;
        default:
            cout << "Invalid Selection. Try again." << endl;
            break;
        }
    }
    return 0;
}