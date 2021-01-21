#pragma once
#include "degree.h"
#include "student.h"
#include <string>

using namespace std;


class Roster
{
	const size_t MAX_ARRAY_SIZE = 5;
	Student* classRosterArray[5] = {};

public:
	void StudentsFromArray(const string s[], size_t size);
	 Student* StudentFromString(string s);
	 size_t NextOpen();
	 int FindStudent(string studentID);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram);	
	void remove(string studentID); 

	void printAll(); 

	void printAverageDaysInCourse(string studentID);

	void printInvalidEmails(); 

	void printByDegreeProgram(Degree::DegreeProgram degreeProgram);
	Student** GetClassRosterArray();
	size_t GetMaxArraySize();

	~Roster();
};

