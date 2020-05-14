//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/4/19
// Project: Lab 10
// Class: CS 201 Lab
//-----------------------------------------------------------------------------

#pragma once
#include <string>

class StudentInfo {
public:
    StudentInfo(std::string value, StudentInfo* nextItem)
        : name(value), nextStudentPtr(nextItem) {}
    inline std::string getName() { return name; }
    inline StudentInfo* getNextStudent() { return nextStudentPtr; }
    inline void setNextStudent(StudentInfo* item) { nextStudentPtr = item; }

private:
    std::string name;
    StudentInfo* nextStudentPtr;
};