//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/11/19
// Project: Lab 11
// Class: CS 201 Lab
//-----------------------------------------------------------------------------

#include "Fraction.h"
#include <iostream>
#include <string>

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
    int remainder = num2 % num1;
    if (remainder != 0)
        return getGCD(remainder, num1);
    return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
    // Handle zeros in the fraction
    if (denominator == 0 || numerator == 0)
        return;

    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

Fraction Fraction::operator+(Fraction & rhFraction)
{
    // Find the left and right side to add
    int leftNumerator = this->numerator * rhFraction.denominator;
    int rightNumerator = this->denominator * rhFraction.numerator;
    // Find the new denominator
    int newDenominator = this->denominator * rhFraction.denominator;

    // Create a new fraction to pass
    Fraction newFraction(leftNumerator + rightNumerator, newDenominator);
    newFraction.reduce();

    return newFraction;
}

Fraction Fraction::operator-(Fraction & rhFraction)
{
    // Get the left and right numerators to subtract
    int leftNumerator = this->numerator * rhFraction.denominator;
    int rightNumerator = this->denominator * rhFraction.numerator;

    // Get the new denominator
    int newDenominator = this->denominator * rhFraction.denominator;

    // Create a new fraction to pass
    Fraction newFraction(leftNumerator - rightNumerator, newDenominator);
    newFraction.reduce();

    return newFraction;
}

Fraction Fraction::operator*(Fraction & rhFraction)
{
    int newNumerator = this->numerator * rhFraction.numerator;
    int newDenominator = this->denominator * rhFraction.denominator;

    // Create a new fraction to pass
    Fraction newFraction(newNumerator, newDenominator);
    newFraction.reduce();

    return newFraction;
}

Fraction Fraction::operator/(Fraction & rhFraction)
{
    int newNumerator = this->numerator * rhFraction.denominator;
    int newDenominator = this->denominator * rhFraction.numerator;

    // Create a new fraction to pass
    Fraction newFraction(newNumerator, newDenominator);
    newFraction.reduce();

    return newFraction;
}

bool Fraction::operator==(Fraction & rhFraction)
{
    // Reduce both fractions to compare
    this->reduce();
    rhFraction.reduce();

    return this->numerator == rhFraction.numerator 
        && this->denominator == rhFraction.denominator;
}

std::ostream& operator<<(std::ostream& outStream, const Fraction& fract)
{
    outStream << fract.numerator << "/" << fract.denominator;

    return outStream;
}

std::istream& operator>>(std::istream& inStream, Fraction& fract)
{
    char slash; // Temp char just to handle the slash in the input

    inStream >> fract.numerator >> slash >> fract.denominator;

    return inStream;
}
