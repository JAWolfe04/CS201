//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Name:  Jonathan Wolfe
// Email: jawhf4@mail.umkc.edu
// Lab:   Lab02
// Due:   1/31/19
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
	std::string name;
	float homeworkScore, testScore, quizScore, attendanceScore, totalScore;

	std::cout << "Please enter the students name >>> ";
	std::getline(std::cin, name);

	std::cout << "\nPlease enter the homework score >>> ";
	std::cin >> homeworkScore;

	std::cout << "\nPlease enter the test score >>> ";
	std::cin >> testScore;

	std::cout << "\nPlease enter the quiz score >>> ";
	std::cin >> quizScore;

	std::cout << "\nPlease enter the attendance score >>> ";
	std::cin >> attendanceScore;

	std::cout << std::endl;

	totalScore = (0.2f * homeworkScore) + (0.5f * testScore) + (0.2f * quizScore) + (0.1f * attendanceScore);

	std::cout << "Grades for " << name << std::endl;
	std::cout << "   Homework     : " << homeworkScore << std::endl;
	std::cout << "   Test         : " << testScore << std::endl;
	std::cout << "   Quiz         : " << quizScore << std::endl;
	std::cout << "   Attendance   : " << attendanceScore << std::endl;
	std::cout << "============================" << std::endl;
	std::cout << " Total Score    : " << totalScore << std::endl;

	return 0;
}