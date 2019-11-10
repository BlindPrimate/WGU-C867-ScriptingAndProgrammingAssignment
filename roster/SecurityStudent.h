#pragma once
#include "Student.h"
#include <string>
class SecurityStudent :
	public Student
{
	using Student::Student;
	public:
		std::string degree = "Security";

};

