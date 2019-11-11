#include "Student.h"
#include <string>
#include <list>

Student::Student(std::string s_first_name,
	std::string s_last_name,
	std::string s_id,
	std::string s_email,
	int s_age,
	int days_1,
	int days_2,
	int days_3
)
{
	first_name = s_first_name;
	last_name = s_last_name;
	id = s_id;
	email = s_email;
	age = s_age;
	days_in_course = { days_1, days_2, days_3 };
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

