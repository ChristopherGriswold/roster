#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;
class Student
{
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	Degree::DegreeProgram degreeProgram;

public:
	void SetStudentId(string id);
	string GetStudentId() const;
	void SetFirstName(string fn);
	string GetFirstName() const;
	void SetLastName(string ln);
	string GetLastName() const;
	void SetEmailAddress(string e);
	string GetEmailAddress() const;
	void SetAge(int a);
	int GetAge() const;
	void SetDaysInCourse(int* d);
	int* GetDaysInCourse();
	void SetDegreeProgram(Degree::DegreeProgram dp);
	Degree::DegreeProgram GetDegreeProgram() const;

	Student(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		Degree::DegreeProgram degreeProgram);

	void Print() const;

};

