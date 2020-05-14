//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/25/19
// Project: Lab 13 - Recursion
// Class: CS 201L
//-----------------------------------------------------------------------------
#include "Helper.h"
#include <iostream>

int main() 
{
    // Get integer for factorial and Fibonacci from user
    int input;
    std::cout << "Enter an integer" << std::endl;
    std::cin >> input;

    std::cout << "\n" << input << "! = " << Factorial(input) << "\n\n";

    std::cout << "Fibonacci(" << input << ") = " << Fibonacci(input) << "\n\n";

    // Get integer for Prime test
    std::cout << "Enter a number to check if it is a prime number" << std::endl;
    std::cin >> input;

    if (IsPrime(input))
        std::cout << "\n" << input << " is a prime number" << std::endl;
    else
        std::cout << "\n" << input << " is not a prime number" << std::endl;

    // Get list to sum and print in reverse from user
    std::cout << "\nNext we will enter 5 values into an array" << std::endl;

    int list[5];
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Enter a value for index " << i << std::endl;
        std::cin >> list[i];
        std::cin.ignore(256, '\n');
    }

    std::cout << "\nThe sum of all the values is " << Sum(list, 5) << std::endl;

    std::cout << "The list output in reverse is" << std::endl;
    OutputReverseList(list, 5);

	return EXIT_SUCCESS;
}