#pragma once
#include "Student.h"
#include "degree.h"

class NetworkStudent :
	public Student
{
	using Student::Student;
	public:
		std::string get_degree_program();
		void print() override;
};

