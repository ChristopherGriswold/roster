#pragma once
#include <string>
class Degree
{
public:
	enum DegreeProgram
	{
		SECURITY,
		NETWORK,
		SOFTWARE
	};

		//Methods to convert Strings to a DegreeProgram enum and vice versa.


	static DegreeProgram StringToDegreeProgram(std::string s) {
		DegreeProgram degreeProgram = Degree::SECURITY;
		if (s == "SECURITY") {
			degreeProgram = Degree::SECURITY; 
		}
		else if (s == "NETWORK") {
			degreeProgram = Degree::NETWORK;
		}
		else if (s == "SOFTWARE") {
			degreeProgram = Degree::SOFTWARE;
		}
		return degreeProgram;
	}

	static std::string DegreeProgramToString(DegreeProgram dp) {
		std::string outStr = "Security";
		if (dp == 0) {
			outStr = "Security";
		}
		else if (dp == 1) {
			outStr = "Network";
		}
		else if (dp == 2) {
			outStr = "Software";
		}
		return outStr;
	}
};
