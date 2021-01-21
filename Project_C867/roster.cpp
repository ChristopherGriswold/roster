#include "roster.h"

	//Splits a string array of student records into individual strings and calls a method that will use them to populate the roster	
	//array.

void Roster::StudentsFromArray(const string s[], size_t size){
	for (int i = 0; i < size; ++i) {
		classRosterArray[i] = Roster::StudentFromString(s[i]);
	}
}

	//Creates a new student object on the heap and adds a pointer to it to the roster array.

Student* Roster::StudentFromString(string s) {
	size_t TABLE_COLUMNS = 9;

	string studentID = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	int age = 0;
	int daysInCourse1 = 0;
	int daysInCourse2 = 0;
	int daysInCourse3 = 0;
	string dpString = "";
	Degree::DegreeProgram degreeProgram = Degree::SOFTWARE;

	for (int i = 0; i < TABLE_COLUMNS; ++i) {
		int commaIndex = s.find(',');
		switch (i)
		{
		case 0: studentID = (s.substr(0, commaIndex));
			break;
		case 1: firstName = (s.substr(0, commaIndex));
			break;
		case 2: lastName = (s.substr(0, commaIndex));
			break;
		case 3: emailAddress = (s.substr(0, commaIndex));
			break;
		case 4:  age = (stoi(s.substr(0, commaIndex)));
			break;
		case 5:	daysInCourse1 = (stoi(s.substr(0, commaIndex)));
			break;
		case 6: daysInCourse2 = (stoi(s.substr(0, commaIndex)));
			break;
		case 7: daysInCourse3 = (stoi(s.substr(0, commaIndex)));
			break;
		case 8: dpString = (s.substr(0, commaIndex));
			break;
		default:
			break;
		}
		s.erase(0, commaIndex + 1);
	}
	degreeProgram = Degree::StringToDegreeProgram(dpString);
	Student* student = new Student{ studentID, firstName, lastName, emailAddress, 
		age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram };
	return student;
}

	//Helper method used to see if there is space available in the roster array. Returns first available array index.

size_t Roster::NextOpen()
{
	size_t i = 0;
	for (i; i < MAX_ARRAY_SIZE; ++i) {
		if (classRosterArray[i] == 0) {
			return i;
		}
	}
	return 0;
}

	//Helper method used to find a specific student in the roster array. If found, returnds the array index of the student record.

int Roster::FindStudent(string studentID)
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		if (classRosterArray[i] == 0) {
			break;
		}
		if (classRosterArray[i]->GetStudentId() == studentID) {
			return i;
		}
	}
//	cout << "ERROR: Student ID does not exist." << endl;         // Error message moved to remove() method for clarity.
	return -1;
}

	//Adds a new student record to the roster. Assuming there is space.

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram)
{
	Student* student1 = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	classRosterArray[NextOpen()] = student1;
}

	//Removes students from the roster by student ID. If the student ID does not exist, the function prints an error message 
	//indicating that the student was not found.

void Roster::remove(string studentID)
{
	cout << "------------------------------------------------" << endl;
	cout << "Attempting to remove StudentID:  " << studentID  << endl;
	int studentIndex = FindStudent(studentID);
	if (studentIndex < 0) {
		cout << "ERROR:\nStudent ID: " << studentID << " was not found." << endl;
		return;
	}
	else {
		delete classRosterArray[studentIndex];
		classRosterArray[studentIndex] = nullptr;
		cout << "Success!" << endl;
	}
}

	//Tells every individual Student object in the roster array to print.

void Roster::printAll()
{
	cout << "------------------------------------------------" << endl;
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		if (classRosterArray[i] == 0) {
			continue;
		}
		classRosterArray[i]->Print();
	}
	cout << endl;
}

	//Prints the average number of days a specific student takes to complete a couse.

void Roster::printAverageDaysInCourse(string studentID)
{
	int studentIndex = FindStudent(studentID);
	if (studentIndex < 0) {
		return;
	}
	else {
		int* daysArray = classRosterArray[studentIndex]->GetDaysInCourse();
		double daysTotal = 0.0;
		double averageDays = 0.0;
		for (int i = 0; i < 3; ++i) {
			daysTotal += *(daysArray + i);
		}
		averageDays = daysTotal / 3;
		cout << studentID <<  " : " << averageDays << endl;
	}
}

	//that verifies student email addressesand displays all invalid email addresses to the user.
	//Note : A valid email should include an at sign('@') and period('.') and should not include a space(' ').

void Roster::printInvalidEmails()
{
	cout << "------------------------------------------------" << endl;
	cout << "Invalid email addresses:\n" << endl;
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		string email = classRosterArray[i]->GetEmailAddress();
		if (email.find(' ') < email.length() || email.find('@') > email.length() || email.find('.') > email.length()) {
			cout << classRosterArray[i]->GetStudentId() << " : " << email << endl;
		}
	}
	cout << endl;
}

	//Prints out students in a particular Degree Program.

void Roster::printByDegreeProgram(Degree::DegreeProgram degreeProgram)
{
	cout << "------------------------------------------------" << endl;
	cout << Degree::DegreeProgramToString(degreeProgram) << " students:\n" << endl;
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
			cout << classRosterArray[i]->GetStudentId() << " : " << classRosterArray[i]->GetFirstName() << " " <<
				classRosterArray[i]->GetLastName() << endl;
		}
	}
	cout << endl;
}

	//Public accessor methods.

Student** Roster::GetClassRosterArray()
{
	return &classRosterArray[0];
}

size_t Roster::GetMaxArraySize()
{
	return MAX_ARRAY_SIZE;
}

	//Destructor deletes student objects that were created dynamically on the heap.

Roster::~Roster()
{
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
		delete classRosterArray[i];
	}
}
