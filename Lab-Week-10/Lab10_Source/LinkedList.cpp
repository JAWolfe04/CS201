//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/4/19
// Project: Lab 10
// Class: CS 201 Lab
//-----------------------------------------------------------------------------

#include "LinkedList.h"
#include <iostream>

void AppendNode(StudentInfo** headPtr, std::string name)
{
    StudentInfo* newNode = new StudentInfo(name, nullptr);
    StudentInfo* lastNode = *headPtr;

    if (*headPtr == nullptr)
        *headPtr = newNode;
    else
    {
        while (lastNode->getNextStudent() != nullptr)
            lastNode = lastNode->getNextStudent();

        lastNode->setNextStudent(newNode);
    }
}

void AlphaInsertNode(StudentInfo** headPtr, std::string name)
{
    StudentInfo* curNode = *headPtr;
    StudentInfo* prevNode = nullptr;


    if (*headPtr == nullptr)
        *headPtr = new StudentInfo(name, nullptr);
    else
    {
        while (curNode != nullptr && curNode->getName() < name)
        {
            prevNode = curNode;
            curNode = curNode->getNextStudent();
        }

        if (prevNode == nullptr)
            *headPtr = new StudentInfo(name, curNode);
        else
            prevNode->setNextStudent(new StudentInfo(name, curNode));
    }
}

void DeleteNode(StudentInfo** headPtr, std::string name)
{
    StudentInfo* tempNode = *headPtr;
    StudentInfo* prevNode = nullptr;

    if (tempNode != nullptr && tempNode->getName() == name)
    {
        *headPtr = tempNode->getNextStudent();
        delete tempNode;
        return;
    }

    while (tempNode != nullptr && tempNode->getName() != name)
    {
        prevNode = tempNode;
        tempNode = tempNode->getNextStudent();
    }

    if (tempNode != nullptr && prevNode != nullptr)
    {
        prevNode->setNextStudent(tempNode->getNextStudent());
        delete tempNode;
    }
}

void PrintList(StudentInfo* headPtr)
{
    while (headPtr)
    {
        std::cout << "->" << headPtr->getName();
        headPtr = headPtr->getNextStudent();
    }
}

void DeleteList(StudentInfo** headPtr)
{
    StudentInfo* curNode = *headPtr;
    StudentInfo* nextNode;

    while (curNode)
    {
        nextNode = curNode->getNextStudent();
        delete curNode;
        curNode = nextNode;
    }

    *headPtr = nullptr;
}