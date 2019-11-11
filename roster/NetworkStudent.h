#pragma once
#include "Student.h"
class NetworkStudent :
	public Student
{
	using Student::Student;
	public:
		std::string degree = "Network";
		std::string get_degree();
};

