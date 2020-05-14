//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/18/19
// Project: Exam 2
// Class: CS 201L
//-----------------------------------------------------------------------------
#pragma once
#include <string>

class Employee
{
public:
	// Default Constructor
    Employee() {}
    // Need a default constructor to sort vector

    // Constructor
    Employee(int id, std::string myName) 
        : employeeID(id), name(myName), payRate(10.00), balance(0) {}

	// Getter to return the employee ID
    int getEmployeeID() { return employeeID; }

	// Getter to return the current pay rate
    double getPayRate() { return payRate; }

	// Getter to return the current amount of pay earned
    double getBalance() { return balance; }

	// Getter to get Employee's name
    std::string getName() { return name; }

	// Function to give the raise. It takes in a percent in whole numbers 
	// (ex: 5 for 5%)
    void giveRaise(int rate);

	// Pays the employee
	void pay();

	// Fires the Employee
	void fire();

	// Returns if the Employee is currently employed
    bool isEmployed() { return employed; }

private:
    int employeeID;
    std::string name;
    double balance;
    double payRate;
    bool employed = true;
};