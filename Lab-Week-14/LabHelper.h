#pragma once
#include <typeinfo>
#include <iostream>
#include <fstream>

template<typename T>
void mySwap(T swapArray[], int positionA, int positionB)
{
    int arraySize = sizeof(swapArray) / sizeof(T);
    //Handle positionA or positionB is greater than the size of the array

    T temp = swapArray[positionA];
    swapArray[positionA] = swapArray[positionB];
    swapArray[positionB] = temp;
}

// This should work but the array is not reading the size
template<typename T>
T myMin(T minArray[])
{
    //int arraySize = sizeof(minArray) / sizeof(minArray);

    //Handle empty arrays
    if (arraySize == 0)
        throw std::exception("Array size is 0, cannot determine minimum value.");

    T minEntry = minArray[0];

    for (int i = 0; i < 100; ++i)
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

template<typename T>
void outputResults(T outputArray[], std::ofstream& outFile, T target1, T target2)
{
    if (typeid(T) == typeid(int))
        outFile << "Integers:\n";
    else if (typeid(T) == typeid(double))
        outFile << "Doubles:\n";
    else if (typeid(T) == typeid(std::string))
        outFile << "Strings:\n";

    outFile << "Swapped items at positions 10 and 20\n";
    outFile << "Before: [10] " << outputArray[10] << " [20] " << outputArray[20] << "\n";

    mySwap(outputArray, 10, 20);

    outFile << "After: [10] " << outputArray[10] << " [20] " << outputArray[20] << "\n";
    outFile << "Minimum: " << myMin(outputArray) << "\n";
    outFile << "Maximum: " << myMax(outputArray) << "\n";
    outFile << "The number " << target1 << " is at position " << mySearch(outputArray, target1) << "\n";
    outFile << "The number " << target2 << " is at position " << mySearch(outputArray, target2) << "\n\n";
}