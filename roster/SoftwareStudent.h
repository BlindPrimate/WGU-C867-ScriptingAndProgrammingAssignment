#pragma once
#include "Student.h"
#include "degree.h"

class SoftwareStudent :
	public Student
{
	using Student::Student;
	public:
		std::string get_degree_program();
		void print() override;
};

