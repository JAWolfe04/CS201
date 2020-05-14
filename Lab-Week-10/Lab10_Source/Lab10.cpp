//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/4/19
// Project: Lab 10
// Class: CS 201 Lab
//-----------------------------------------------------------------------------

#include "StudentInfo.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {

    StudentInfo* headPtr = nullptr;
    string fileName = "input7.txt";

	ifstream fin(fileName);
	
	if (!fin.is_open())
	{
		cout << "Could not open the input file " + fileName << endl;
		return -1;
	}
	
	while (!fin.eof())
	{
		string item, command;
		fin >> item >> command;

		// Logic of handling the input.
        if (command == "add")
        {
            AlphaInsertNode(&headPtr, item);
        }
        else if (command == "del")
        {
            DeleteNode(&headPtr, item);
        }

	}
	fin.close();

	// Output the final linked list.
    PrintList(headPtr);

	// Free up all memory.
    DeleteList(&headPtr);

}