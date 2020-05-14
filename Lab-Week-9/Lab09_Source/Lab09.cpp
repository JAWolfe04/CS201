//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/21/19
// Project: Lab 9 - Library Books
// Class: CS 201 Lab
//-----------------------------------------------------------------------------
#include "FileHelper.h"
#include "LibraryBook.h"
#include <vector>
#include <exception>
#include <iostream>

int main() 
{
	std::vector<LibraryBook> books; // Collection of library books

	// Fancy exception handling, I hate this so much
	try 
	{
		RegisterBooks(books, "books.txt");

		SetBooksStatus(books, "isbns.txt");

		PrintReport(books, "checkedout.txt");
	}
	// So fancy and slow
	catch (std::runtime_error e)
	{
		std::cout << e.what();
	}
	
	return 0;
}