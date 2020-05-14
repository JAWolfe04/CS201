//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/11/19
// Project: Lab 11
// Class: CS 201 Lab
//-----------------------------------------------------------------------------

#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Input/output files
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    // Throw error if can't open input file
    if (!fin || !fout)
    {
        if (!fin)
            std::cerr << "Error opening input file";
        else
            std::cerr << "Error creating output file";

        fin.close();
        fout.close();

        return 1;
    }

    // While there's data in the file, read in a line and calcuate it
    while (fin.good())
    {
        // Read in two fractions and the operator to perform
        Fraction fract1, fract2;
        char oper;
        fin >> fract1 >> oper >> fract2;

        // Print out original functions read in
        fout << fract1 << " " << oper << " " << fract2 << " = ";

        // Do math on them
        switch (oper)
        {
        case '+':
            fout << fract1 + fract2 << std::endl;
            break;

        case '-':
            fout << fract1 - fract2 << std::endl;
            break;

        case '*':
            fout << fract1 * fract2 << std::endl;
            break;

        case '/':
            fout << fract1 / fract2 << std::endl;
            break;

        case '=':
            if (fract1 == fract2)
                fout << "True" << std::endl;
            else
                fout << "False" << std::endl;
            break;

        }
    }

    // Close files
    fin.close();
    fout.close();

    // Quit without error
    return 0;

}