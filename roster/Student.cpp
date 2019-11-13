#include "Student.h"
#include <string>
#include <vector>
#include <iostream>


// constructor
Student::Student(std::string id, std::string first_name, std::string last_name, std::string email, int age,
				int days_1, int days_2, int days_3)
	: id(id),  first_name(first_name), last_name(last_name), email(email), age(age), days_1(days_1), days_2(days_2), days_3(days_3)
		
{
	return;
}

// destructor
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
	return email;
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
	// build days in course with format  '(day, day, day)'
	for (int i = 0; i < days.size(); i++) {
		std::string str = std::to_string(days[i]);
		if (i == days.size() - 1) {
			result = result + str + ")";
		} 
		else {
			result = result + str + ", ";
		}
	}
	return result;
}


unsigned int Student::get_average_days_in_course()
{
	return (days_1 + days_2 + days_3) / 3;
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
	email = value;
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


void Student::print() {

	std::cout << "ID: " << get_id() << "\tFirst Name: " << get_first_name()
		<< "\tLast Name: " << get_last_name() << "\tEmail:" << get_email()
		<< "\tAge: " << get_age() << "\tDays in Course: "
		<< get_days_in_course();

	std::cout << "\tDegree: ";

	switch (get_degree_program()) {
		case 0:
			std::cout << "NETWORK";
			break;
		case 1:
			std::cout << "SECURITY";
			break;
		case 2:
			std::cout << "SOFTWARE";
			break;
		case 3:
			std::cout << "OTHER";
			break;
	}
	std::cout << std::endl;
		
	return;
}

