#include "student.h"

//Class constructor requiring all input paramaters. 

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram)
{
	this->studentID = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->degreeProgram = degreeProgram;
}

//Prints the students entire record in a tab-seperated list.

void Student::Print() const {
	cout << studentID << "\t" << "First Name : " << firstName << "\tLast Name : " << lastName << "\tAge : " << age
		<< "\tDays In Course : {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\tDegree Program : " 
		<< Degree::DegreeProgramToString(degreeProgram) << endl;
}

//Simple getters and setters for all member variables.

void Student::SetStudentId(string id)
{
	studentID = id;
}

string Student::GetStudentId() const
{
	return studentID;
}

void Student::SetFirstName(string fn)
{
	firstName = fn;
}

string Student::GetFirstName() const
{
	return firstName;
}

void Student::SetLastName(string ln)
{
	lastName = ln;
}

string Student::GetLastName() const
{
	return lastName;
}

void Student::SetEmailAddress(string e)
{
	emailAddress = e;
}

string Student::GetEmailAddress() const
{
	return emailAddress;
}

void Student::SetAge(int a)
{
	age = a;
}

int Student::GetAge() const
{
	return age;
}

void Student::SetDaysInCourse(int* d)
{
	*daysInCourse = *d;
}

int* Student::GetDaysInCourse()
{
	return daysInCourse;
}

void Student::SetDegreeProgram(Degree::DegreeProgram dp)
{
	degreeProgram = dp;
}

Degree::DegreeProgram Student::GetDegreeProgram() const
{
	return degreeProgram;
}
