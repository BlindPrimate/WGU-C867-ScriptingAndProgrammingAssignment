#pragma once
#include "Student.h"
#include "degree.h"
#include <string>

class SecurityStudent :
	public Student
{
	using Student::Student;
	public:
		Degree degree = Degree::SECURITY;
		Degree get_degree_program();

};

