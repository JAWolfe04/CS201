//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/21/19
// Project: Lab 9 - Library Books
// Class: CS 201 Lab
//-----------------------------------------------------------------------------
#pragma once
#include <string>

// Manages the book title, author, ISBN and checked out status
class LibraryBook
{
public:
	// Inline constructors muaahaaa
	LibraryBook() : title(""), author(""), ISBN(""), checkedOut(false) {}
	LibraryBook(std::string title, std::string author, std::string ISBN)
		: title(title), author(author), ISBN(ISBN), checkedOut(false) {}

	// Bunch of getters, no comments needed
	inline std::string GetTitle() { return title; }
	inline std::string GetAuthor() { return author; }
	inline std::string GetISBN() { return ISBN; }

	// Sets the book to be checked out
	inline void checkOut() { checkedOut = true; }
	// Sets the books to be checked in
	inline void checkIn() { checkedOut = false; }
	// Returns the checked out status
	inline bool isCheckedOut() { return checkedOut; }

	// Switch the checkedOut status
	inline void updateCheckedOut() { checkedOut = !checkedOut; }
private: 
	std::string title; // Book title
	std::string author; // Book author
	std::string ISBN; // Book ISBN
	bool checkedOut; // Book checked out status, true means it is checked out
};