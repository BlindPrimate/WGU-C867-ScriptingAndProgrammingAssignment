#pragma once
#include "Student.h"
#include "degree.h"

class SoftwareStudent :
	public Student
{
	using Student::Student;
	public:
		Degree degree = SOFTWARE;
		virtual Degree get_degree_program();
};

