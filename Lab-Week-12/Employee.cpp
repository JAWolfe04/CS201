//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/18/19
// Project: Exam 2
// Class: CS 201L
//-----------------------------------------------------------------------------
#include <string>
#include "Employee.h"

void Employee::giveRaise(int rate)
{
    // Convert rate to a percentage and increase payRate
    this->payRate *= 1 + (rate / 100.0);
}

void Employee::pay()
{
    this->balance += this->payRate;
}

void Employee::fire()
{
    this->payRate = 0;
    this->employed = false;
}
