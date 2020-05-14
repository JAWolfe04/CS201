//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/4/19
// Project: Lab 10
// Class: CS 201 Lab
//-----------------------------------------------------------------------------

#pragma once
#include "StudentInfo.h"
#include <string>

void AppendNode(StudentInfo** headPtr, std::string name);

void AlphaInsertNode(StudentInfo** headPtr, std::string name);

void DeleteNode(StudentInfo** headPtr, std::string name);

void PrintList(StudentInfo* headPtr);

void DeleteList(StudentInfo** headPtr);