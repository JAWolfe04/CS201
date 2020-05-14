//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 5/8/19
// Project: Lab 14 - Templates
// Class: CS 201L
//-----------------------------------------------------------------------------
//#include "LabHelper.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>

template<typename T>
void mySwap(T swapArray[], int positionA, int positionB)
{
    int arraySize = sizeof(swapArray) / sizeof(T);
    //Handle positionA or positionB is greater than the size of the array

    T temp = swapArray[positionA];
    swapArray[positionA] = swapArray[positionB];
    swapArray[positionB] = temp;
}

template<typename T>
T myMin(T minArray[])
{
    int arraySize = sizeof(minArray) / sizeof(minArray);

    //Handle empty arrays
    if (arraySize == 0)
        throw std::exception("Array size is 0, cannot determine minimum value.");

    T minEntry = minArray[0];

    for (int i = 0; i < arraySize; ++i)
    {
        if (minArray[i] < minEntry)
            minEntry = minArray[i];
    }

    return minEntry;
}

template<typename T>
T myMax(T maxArray[])
{
    int arraySize = sizeof(maxArray) / sizeof(T);

    //Handle empty arrays
    if (arraySize == 0)
        throw std::exception("Array size is 0, cannot determine minimum value.");

    T maxEntry = maxArray[0];

    for (int i = 0; i < arraySize; ++i)
    {
        if (maxArray[i] > maxEntry)
            maxEntry = maxArray[i];
    }

    return maxEntry;
}

template<typename T>
int mySearch(T searchArray[], T target)
{
    int arraySize = sizeof(searchArray) / sizeof(T);

    //Handle empty arrays
    if (arraySize > 0)
    {
        for (int i = 0; i < arraySize; ++i)
        {
            if (target == searchArray[i])
                return i;
        }
    }

    return -1;
}

int main()
{
    double doublesArray[100];
    int integersArray[100];
    std::string stringsArray[100];
    int counter = 0;

    std::ifstream inDoubles("doubles.txt");
    std::ifstream inIntegers("integers.txt");
    std::ifstream inStrings("strings.txt");
    std::ofstream outFile("output.txt");

    if (!inDoubles.is_open() || !inIntegers.is_open() || !inStrings.is_open())
    {
        std::cerr << "Unable to open required files" << std::endl;
        return 1;
    }

    while (!inDoubles.eof())
        inDoubles >> doublesArray[counter++];

    counter = 0;
    while (!inIntegers.eof())
        inIntegers >> integersArray[counter++];

    counter = 0;
    while (!inStrings.eof())
        std::getline(inStrings, stringsArray[counter++]);

    inDoubles.close();
    inIntegers.close();
    inStrings.close();

    // Integer
    outFile << "Integers:\n";

    outFile << "Swapped items at positions 10 and 20\n";
    outFile << "Before: [10] " << integersArray[10] << " [20] " << integersArray[20] << "\n";

    mySwap(integersArray, 10, 20);

    outFile << "After: [10] " << integersArray[10] << " [20] " << integersArray[20] << "\n";
    outFile << "Minimum: " << myMin(integersArray) << "\n";
    outFile << "Maximum: " << myMax(integersArray) << "\n";
    outFile << "The number 1 is at position " << mySearch(integersArray, 1) << "\n";
    outFile << "The number 5 is at position " << mySearch(integersArray, 5) << "\n\n";


    // Doubles 
    outFile << "Doubles:\n";

    outFile << "Swapped items at positions 10 and 20\n";
    outFile << "Before: [10] " << doublesArray[10] << " [20] " << doublesArray[20] << "\n";

    mySwap(doublesArray, 10, 20);

    outFile << "After: [10] " << doublesArray[10] << " [20] " << doublesArray[20] << "\n";
    outFile << "Minimum: " << myMin(doublesArray) << "\n";
    outFile << "Maximum: " << myMax(doublesArray) << "\n";
    outFile << "The number 1 is at position " << mySearch(doublesArray, 1.0) << "\n";
    outFile << "The number 5 is at position " << mySearch(doublesArray, 5.0) << "\n\n";

    // Strings
    outFile << "Strings:\n";

    outFile << "Swapped items at positions 10 and 20\n";
    outFile << "Before: [10] " << stringsArray[10] << " [20] " << stringsArray[20] << "\n";

    mySwap(stringsArray, 10, 20);

    outFile << "After: [10] " << stringsArray[10] << " [20] " << stringsArray[20] << "\n";
    outFile << "Minimum: " << myMin(stringsArray) << "\n";
    outFile << "Maximum: " << myMax(stringsArray) << "\n";
    outFile << "The number 1 is at position " << mySearch(stringsArray, std::string("1")) << "\n";
    outFile << "The number 5 is at position " << mySearch(stringsArray, std::string("5")) << "\n\n";

    return 0;
}