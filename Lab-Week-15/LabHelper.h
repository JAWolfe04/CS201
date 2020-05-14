//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 5/9/19
// Project: Lab 15 - List(STL)
// Class: CS 201L
//-----------------------------------------------------------------------------
#pragma once
#include <list>
#include <string>
#include <fstream>

void fillList(std::list<char> &strList, std::string &addStr);

void printList(std::ostream &outFile, std::list<char> &strList);

void removeCharacter(std::list<char> &strList, char removeChar);