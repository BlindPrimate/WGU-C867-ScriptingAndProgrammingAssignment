#pragma once
#include "Student.h"
#include "degree.h"

class SecurityStudent :
	public Student
{
	using Student::Student;
	public:
		virtual std::string get_degree_program();
		virtual void print();

};

