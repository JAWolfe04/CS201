//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/21/19
// Project: Lab 9 - Library Books
// Class: CS 201 Lab
//-----------------------------------------------------------------------------
#pragma once
#include "LibraryBook.h"
#include <vector>

// Reads the fileName file adding the book to books
// books is a collection of library books
// filename is the file name of the file containing the library books data
// Throws runtime error if the file cannot be opened
void RegisterBooks(std::vector<LibraryBook>& books, std::string fileName);

// Reads the fileName file setting the checked out statuses in books
// books is a collection of library books
// filename is the file name of the file containing checked out data
// Throws runtime error if the file cannot be opened
void SetBooksStatus(std::vector<LibraryBook>& books, std::string fileName);

// Prints the books that have been checked out to the fileName file
// books is a collection of library books
// fileName is the file name of the file for the checked out books to print
// Throws runtime error if the file cannot be created/opened
void PrintReport(std::vector<LibraryBook>& books, std::string fileName);