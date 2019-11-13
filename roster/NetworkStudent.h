#pragma once
#include "Student.h"
#include "degree.h"

class NetworkStudent :
	public Student
{
	using Student::Student;
	public:
		Degree degree = NETWORK;
		virtual Degree get_degree_program();
};

