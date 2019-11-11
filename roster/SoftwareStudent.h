#pragma once
#include "Student.h"
class SoftwareStudent :
	public Student
{
	using Student::Student;
	public:
		std::string degree = "Software";
		std::string get_degree();
};

