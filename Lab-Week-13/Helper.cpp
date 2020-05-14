//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/25/19
// Project: Lab 13 - Recursion
// Class: CS 201L
//-----------------------------------------------------------------------------
#include "Helper.h"
#include <math.h>
#include <iostream>


double Factorial(double value)
{
    // Base case
    if (value <= 1)
        return 1;

    return value * Factorial(value - 1);
}

int Fibonacci(int n)
{
    // Base case
    if (n == 0 || n == 1)
        return n;

    return Fibonacci(n - 1) + Fibonacci( n - 2);
}

bool IsPrime(int value, int n)
{
    // Base case
    if (n > sqrt(value))
        return true;

    // Base case
    if (value % n == 0)
        return false;

    return IsPrime(value, n + 1);
}

int Sum(int list[], int size)
{
    // Base case
    if (size <= 0)
        return 0;
    else
        return list[size - 1] + Sum(list, size - 1);
}

void OutputReverseList(int list[], int size)
{
    // Base case
    if (size <= 0)
    {
        std::cout << std::endl;
        return;
    }
    
    std::cout << list[size - 1] << " ";

    OutputReverseList(list, size - 1);
}
