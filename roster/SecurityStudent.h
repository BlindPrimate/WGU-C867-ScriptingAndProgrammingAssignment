#pragma once
#include "Student.h"
#include "degree.h"

class SecurityStudent :
	public Student
{
	using Student::Student;
	public:
		Degree degree = SECURITY;
		virtual Degree get_degree_program();

};

