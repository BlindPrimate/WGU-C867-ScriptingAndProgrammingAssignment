#pragma once
#include "Student.h"
#include "degree.h"

class SecurityStudent :
	public Student
{
	using Student::Student;
	public:
		std::string get_degree_program();
		void print() override;

};

