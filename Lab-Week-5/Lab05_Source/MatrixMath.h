#pragma once

#include <vector>

//Gets an integer from the user
int GetInInt();

//Prompts the user for input to create a dynamic matrix and fill its contents 
//matrix is the created matrix
void CreateMatrix(std::vector<std::vector<int>>& matrix);

//Prints the matrix to the console
void PrintMatrix(std::vector<std::vector<int>>& matrix);

//Adds two matrices and prints the output to the console
void AddMatrices(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2);

//Multiplies two matrices and prints to the output to the console
void MultiplyMatrices(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2);