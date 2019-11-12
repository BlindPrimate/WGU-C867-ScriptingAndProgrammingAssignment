#include "Student.h"
#include <string>
#include <list>
#include <iostream>


Student::Student(std::string first_name, std::string last_name, std::string id, std::string email, int age,
				int days_1, int days_2, int days_3)
	: first_name(first_name), last_name(last_name), id(id), email(email), age(age), days_1(days_1), days_2(days_2), days_3(days_3)
		
{
	return;
}

Student::~Student()
{
	return;
}



// getters
std::string Student::get_first_name()
{
	return first_name;
}

std::string Student::get_last_name()
{
	return last_name;
}

std::string Student::get_id()
{
	return id;
}

std::string Student::get_email()
{
	return id;
}

int Student::get_age()
{
	return age;
}

std::list<int> Student::get_days_in_course()
{
	return days_in_course;
}





// setters
void Student::set_first_name(std::string value)
{
	first_name = value;
}

void Student::set_last_name(std::string value)
{
	last_name = value;
}

void Student::set_id(std::string value)
{
	id = value;
}

void Student::set_email(std::string value)
{
	id = value;
}

void Student::set_age(int value)
{
	age = value;
}

void Student::set_days_in_course(std::list<int> value)
{
	days_in_course = value;
}


