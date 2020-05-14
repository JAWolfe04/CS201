//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/11/19
// Project: Lab 11
// Class: CS 201 Lab
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>

class Fraction
{
public:
    Fraction() : numerator(0), denominator(0) {}
    Fraction(int numerator, int denominator) 
        : numerator(numerator), denominator(denominator){}

    // Reduce the fraction
    void reduce();

    // Add functions
    Fraction operator+(Fraction& rhFraction);
    // Subtract Fractions
    Fraction operator-(Fraction& rhFraction);
    // Multiply Fractions
    Fraction operator*(Fraction& rhFraction);
    // Divide Fractions
    Fraction operator/(Fraction& rhFraction);
    // Fraction equality
    bool operator==(Fraction& rhFraction);

    // Gets the numerator and denominator from the stream
    friend std::ostream& operator<<(std::ostream& outStream, const Fraction& fract);

    // Puts the numerator and denominator into the stream
    friend std::istream& operator>>(std::istream& inStream, Fraction& fract);

private:
    // Greatest common denominator
    int getGCD(int num1, int num2);

    int numerator; // Fraction numerator
    int denominator; // Fraction denominator
};

