#pragma once
#include "Student.h"
#include "degree.h"

class SoftwareStudent :
	public Student
{
	using Student::Student;
	public:
		Degree degree = Degree::SOFTWARE;
		Degree get_degree_program();
};

