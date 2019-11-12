#pragma once
#include "Student.h"
#include "degree.h"

class NetworkStudent :
	public Student
{
	using Student::Student;
	public:
		Degree degree = Degree::NETWORK;
		Degree get_degree_program();
};

