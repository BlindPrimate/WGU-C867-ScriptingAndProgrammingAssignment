#include "Student.h"
#include <string>
#include <vector>
#include <iostream>


Student::Student(std::string id, std::string first_name, std::string last_name, std::string email, int age,
				int days_1, int days_2, int days_3)
	: id(id),  first_name(first_name), last_name(last_name), email(email), age(age), days_1(days_1), days_2(days_2), days_3(days_3)
		
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

std::string Student::get_days_in_course()
{
	std::vector<int> days;
	std::string result = "(";
	days.push_back(days_1);
	days.push_back(days_2);
	days.push_back(days_3);
	for (int i = 0; i < days.size(); i++) {
		std::string str = std::to_string(days[i]);
		if (i == days.size() - 1) {
			result = result + str + ")";
		} else {
			result = result + str + ", ";
		}
	}
	return result;
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

void Student::set_days_in_course(int day_1, int day_2, int day_3)
{
	days_1 = day_1;
	days_2 = day_2;
	days_3 = day_3;
}


