#include <iostream>
#include "roster.h"
#include "student.h"
#include <string>

using namespace std;

void PrintGreeting();

int main() {

	//Array containing all the information that will be used to generate Student objects.
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Chris,Griswold,cgrisw4@wgu.edu,30,10,20,30,SOFTWARE"
	};

	// Displays required course information in the header.
	PrintGreeting();

	//Creates a local instance of Roster and populates it's student array with informaion from above student data array.
	Roster classRoster;
	classRoster.StudentsFromArray(studentData, 5);

	//Displays all the student records in tabular form and then displays any email addresses that are considered invalid.
	classRoster.printAll();
	classRoster.printInvalidEmails();

	//Iterates through pointer array by pointer and prints the average days-per-course for each individual student.
	{
		cout << "------------------------------------------------" << endl;
		cout << "Average days per course:\n" << endl;
		Student** rosterPtr = classRoster.GetClassRosterArray();
		for (int i = 0; i < 5; ++i) {
			classRoster.printAverageDaysInCourse(rosterPtr[i]->GetStudentId());
		}
		cout << endl;
	}
	//Displays the Student ID, First and Last Names of the students that are currently enrolled in the SOFTWARE degree program.
	classRoster.printByDegreeProgram(Degree::DegreeProgram::SOFTWARE);

	//Removes a student from the class roster array and then verifies that it was successfully removed.
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	cout << endl;
	cout << "------------------------------------------------" << endl;

	return 0;
}

void PrintGreeting() {
	cout << "------------------------------------------------" << endl;
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "#001164982 - Christopher Griswold" << endl;
}
