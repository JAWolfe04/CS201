//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 5/9/19
// Project: Lab 15 - List(STL)
// Class: CS 201L
//-----------------------------------------------------------------------------
#include <list>
#include <string>
#include <fstream>
#include <iostream>

#include "LabHelper.h"

int main()
{
    std::string inputString;
    std::list<char> charList;
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");

    if (inFile.bad() || outFile.bad())
    {
        std::cerr << "Unable to open/create required files" << std::endl;
        return 1;
    }

    while (!inFile.eof())
    {
        std::getline(inFile, inputString);

        if (inputString == "END")
            break;

        fillList(charList, inputString);
    }

    removeCharacter(charList, 'A');
    removeCharacter(charList, 'E');
    removeCharacter(charList, 'I');
    removeCharacter(charList, 'O');
    removeCharacter(charList, 'U');

    printList(outFile, charList);

    return 0;
}