//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 4/18/19
// Project: Exam 2
// Class: CS 201L
//-----------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include "Employee.h"

int main()
{
    std::vector<Employee> payroll;
    std::ifstream inFS("input.txt");
    std::ofstream outFS("output.txt");

    // Handle failed file opening
    if (inFS.fail() || outFS.fail())
    {
        std::cout << "Unable to open or create required files" << std::endl;
        inFS.close();
        outFS.close();
        return 1;
    }

    while (!inFS.eof())
    {
        std::string command;
        inFS >> command;

        if (command == "NEW")
        {
            int employeeID;
            std::string name;

            inFS >> employeeID;

            // Handle invalid employeeID
            if (inFS.fail())
            {
                std::cout << "Error occurred while reading employee ID from NEW command.\n";
                inFS.close();
                outFS.close();
                return 1;
            }

            // Skip a space then get employee name 
            // which is first space last names
            inFS.ignore(1);
            std::getline(inFS, name);

            // Craete and add employee
            payroll.push_back(Employee(employeeID, name));
        }
        else if (command == "RAISE")
        {
            int employeeID, rate;
            inFS >> employeeID >> rate;

            // Handle invalid employee ids
            if (inFS.fail())
            {
                std::cout << "Error occurred while reading employee ID and rate from RAISE command.\n";
                inFS.close();
                outFS.close();
                return 1;
            }

            // Find employee and give raise
            for (int i = 0; i < payroll.size(); ++i)
            {
                if (payroll[i].getEmployeeID() == employeeID)
                {
                    payroll[i].giveRaise(rate);
                    break;
                }
            }
        }
        else if (command == "PAY")
        {
            // Pay everyone
            for (int i = 0; i < payroll.size(); ++i)
                payroll[i].pay();
        }
        else if (command == "FIRE")
        {
            int employeeID;
            inFS >> employeeID;

            // Handle invalid IDs
            if (inFS.fail())
            {
                std::cout << "Error occurred while reading employee ID from FIRE command.\n";
                inFS.close();
                outFS.close();
                return 1;
            }

            // Find the employee and fire
            for (int i = 0; i < payroll.size(); ++i)
            {
                if (payroll[i].getEmployeeID() == employeeID)
                {
                    payroll[i].fire();
                    break;
                }
            }
        }
        // Handle invalid commands
        else
        {
            std::cout << "Unexpected command occurred" << command << " while reading.\n";
            inFS.close();
            outFS.close();
            return 1;
        }
    }

    inFS.close();

    //Insertion sort by employee ID ascending
    int i;
    int j;
    Employee temp;
    for (i = 1; i < payroll.size(); ++i) 
    {
        j = i;

        while (j > 0 && payroll[j].getEmployeeID() < payroll[j - 1].getEmployeeID())
        {
            temp = payroll[j];
            payroll[j] = payroll[j - 1];
            payroll[j - 1] = temp;
            --j;
        }
    }

    // Print the payroll info to output.txt
    for (int i = 0; i < payroll.size(); ++i)
    {
        outFS << payroll[i].getName() << ", ID Number " << payroll[i].getEmployeeID() << ":\n";
        
        if (payroll[i].isEmployed())
            outFS << "Current pay rate: $" << payroll[i].getPayRate() << '\n';
        else
            outFS << "Not employed with the company." << '\n';

        outFS << "Pay earned to date: $" << payroll[i].getBalance() << "\n\n";
    }

    outFS.close();

	return 0;
}