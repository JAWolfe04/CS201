//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/21/19
// Project: Lab 9 - Library Books
// Class: CS 201 Lab
//-----------------------------------------------------------------------------
#include "FileHelper.h"
#include "LibraryBook.h"
#include <fstream>
#include <exception>

void RegisterBooks(std::vector<LibraryBook>& books, std::string fileName)
{
	std::ifstream inFS(fileName);

	if(inFS.fail())
		throw std::runtime_error("Cannot read file " + fileName);

	while (!inFS.eof())
	{
		// Get the info for each book from the file  and add it to books
		std::string title, author, ISBN;

		std::getline(inFS, title);
		std::getline(inFS, author);
		std::getline(inFS, ISBN);

		books.push_back(LibraryBook(title, author, ISBN));
	}

	inFS.close();
}

void SetBooksStatus(std::vector<LibraryBook>& books, std::string fileName)
{
	std::ifstream inFS(fileName);

	if (inFS.fail())
		throw std::runtime_error("Cannot read file " + fileName);

	while (!inFS.eof())
	{
		std::string ISBN;

		std::getline(inFS, ISBN);

		// Look for book with matching ISBN and update its status
		for (LibraryBook& book : books)
		{
			if (book.GetISBN() == ISBN)
			{
				book.updateCheckedOut();
				break;
			}
		}
	}

	inFS.close();
}

void PrintReport(std::vector<LibraryBook>& books, std::string fileName)
{
	std::ofstream outFS;

	outFS.open(fileName);

	if (outFS.fail())
		throw std::runtime_error("Cannot read file " + fileName);

	// Print out each book that is checked out
	outFS << "Books checked out:\n";
	outFS << "------------------\n\n\n";
	outFS << "Title\tAuthor\tISBN\n\n";

	for (LibraryBook book : books)
	{
		if (book.isCheckedOut())
			outFS << book.GetTitle() << "\t" << book.GetAuthor() << "\t" << book.GetISBN() << "\n\n";
	}

	outFS.close();
}
