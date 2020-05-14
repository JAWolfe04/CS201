//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 5/9/19
// Project: Lab 15 - List(STL)
// Class: CS 201L
//-----------------------------------------------------------------------------
#include "LabHelper.h"
#include <cctype>

void fillList(std::list<char> &strList, std::string &addStr)
{
    for (std::string::iterator itr = addStr.begin(); itr != addStr.end(); ++itr)
        strList.push_back(*itr);

    strList.push_back('\0');
}

void printList(std::ostream & outFile, std::list<char>& strList)
{
    for (std::list<char>::iterator itr = strList.begin(); itr != strList.end(); ++itr)
    {
        if (*itr == '\0')
            outFile << "0\n\n";
        else
            outFile << "[" << *itr << "] -> ";
    }
}

void removeCharacter(std::list<char>& strList, char removeChar)
{
    // Using remove will work better but the assignment wants erase
    for (std::list<char>::iterator itr = strList.begin(); itr != strList.end(); )
    {
        if (*itr == std::toupper(removeChar) || *itr == std::tolower(removeChar))
            itr = strList.erase(itr);
        else
            ++itr;
    }
}