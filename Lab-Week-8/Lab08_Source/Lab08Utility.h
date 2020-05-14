//-----------------------------------------------------------------------------
// Name: Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Due: 3/14/19
// Project: Midterm Week 8
// Class: CS 201
//-----------------------------------------------------------------------------

#pragma once
#include <vector>

// Holds media type, total, mean and median costs for a type of media
struct Costs
{
	std::string type;
	float total;
	float mean;
	float median;
};

/*PRE: DVD, Music and TV are vectors that data will be added and fileName should be a vaild file
POST: Data will be read into DVD, Music and TV from fileName
I/O: None.
USER INTERACTION:  None.
ERROR HANDLING: Throws runtime error if file doesn't exist, invalid media types or costs that are not numbers. */
void GetData(std::vector<float>& DVD, std::vector<float>& Music, std::vector<float>& TV, std::string fileName);

/*PRE: list is a vector of any size
POST: Sorts list
I/O: None.
USER INTERACTION:  None.
ERROR HANDLING: None. Unexpected results may occur */
void InsertSort(std::vector<float>& list);

/*PRE: list is a vector of any size
POST: Returns the sum of list values
I/O: None.
USER INTERACTION:  None.
ERROR HANDLING: None. Unexpected results may occur */
float TotalCosts(std::vector<float>& list);

/*PRE: list is a vector of any size
POST: Returns the mean of list values
I/O: None.
USER INTERACTION:  None.
ERROR HANDLING: Throws runtime error if list is empty */
float MeanCosts(std::vector<float>& list);

/*PRE: list is a vector of any size
POST: Returns the median of list values and sorts list in the process
I/O: None.
USER INTERACTION:  None.
ERROR HANDLING: Throws runtime error if list is empty */
float MedianCosts(std::vector<float>& list);

/*PRE: list is a list of Costs structs containing calculations of each type
POST: Prints data from the list onto the console
I/O: None.
USER INTERACTION:  None.
ERROR HANDLING: None. Unexpected results may occur */
void PrintResults(std::vector<Costs>& list);