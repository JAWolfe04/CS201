//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/25/19
// Project: Lab 13 - Recursion
// Class: CS 201L
//-----------------------------------------------------------------------------
#pragma once

//-------------------------------------------------------------
// Returns the factorial of the value
//
// value must be a number
//-------------------------------------------------------------
double Factorial(double value);

//-------------------------------------------------------------
// Returns the Fibonacci number at n
//
// n should be 0 or greater
//-------------------------------------------------------------
int Fibonacci(int n);

//-------------------------------------------------------------
// Returns if value is a prime number
//
// n is for recursive purposes and should not be entered
// value should be a number
//-------------------------------------------------------------
bool IsPrime(int value, int n = 2);

//-------------------------------------------------------------
// Returns the sum of the list with the corresponding size
//
// list must be an int array and size should be a number
//-------------------------------------------------------------
int Sum(int list[], int size);

//-------------------------------------------------------------
// Outputs the list in reverse to the screen
//
// list must be an int array and size should be a number
//-------------------------------------------------------------
void OutputReverseList(int list[], int size);