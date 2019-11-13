// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* 

C867 - Scripting and Programming Foundations
Language: C++
Name: Eric Cleek
ID: 001172916

*/




#include <iostream>
#include "Student.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "NetworkStudent.h"
#include <iterator>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Roster.h"
#include <regex>



int main()
{

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Eric,Cleek,ecleek@wgu.edu,34,50,58,40,SOFTWARE",
	};


	Roster roster(studentData, 5);
	roster.print_all();
	roster.print_invalid_emails();
	roster.print_avg_days_in_course("A4");
	roster.print_by_degree_type("SOFTWARE");
	roster.remove("A3");
	roster.remove("A3");
	roster.print_all();
	roster.~roster();
}


// check if value passed is an integer
inline bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

// constructor
Roster::Roster(const std::string students[], int student_arr_size) : class_roster_raw(students)
{
	for (int i = 0; i < student_arr_size; i++) {

		std::vector<std::string> stripped_strs;
		std::vector<int> stripped_ints;
		Degree tempDegree;
		// convert student string to stringstream
		std::stringstream ss(class_roster_raw[i]);
		// parse strings with commas as delimiter and push into string vectors
		while (ss.good()) {
			std::string new_str;
			std::getline(ss, new_str, ',');
			if (isInteger(new_str)) {
				stripped_ints.push_back(std::stoi(new_str));
			}
			else {
				if (new_str == "NETWORK") {
					tempDegree = NETWORK;
				}
				else if (new_str == "SECURITY") {
					tempDegree = SECURITY;
				} 
				else if (new_str == "SOFTWARE") {
					tempDegree = SOFTWARE;
				}
				else {
					tempDegree = UNDECIDED;
				}
				stripped_strs.push_back(new_str);
			}
		}

		// add student
		Roster::add(stripped_strs[0], stripped_strs[1], stripped_strs[2], stripped_strs[3],
			stripped_ints[0], stripped_ints[1], stripped_ints[2], stripped_ints[3], tempDegree);

	}
}


void Roster::add(std::string id, std::string first_name, std::string last_name, std::string email,
				int age, int days_1, int days_2, int days_3, int degree)
{
		// initialize pointer for student object
		Student *ptr = nullptr;
	
		// sort student based on degree and create appropriate Student obj
		if (degree == NETWORK) {
			ptr = new NetworkStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		} 
		else if (degree == SECURITY) {
			ptr = new SecurityStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		}
		else {
			ptr = new SoftwareStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		}

		// pass student object pointer to class_roster_array
		class_roster_array[student_total] = ptr;
		student_total++;
}


// returns positional index of student within class_roster_array by passing student id as parameter or NULL if not found
int Roster::student_position_index(std::string student_id)
{
	Student* student;
	for (int i = 0; i < student_total; i++) {
		// returns student object with appropriate ID
		student = class_roster_array[i];
		// returns position index
		if (student->get_id() == student_id) {
			return i;
		}
	}
	// else returns NULL
	return NULL;
}


// deletes target student object in array, deletes obj, and removes from array
void Roster::delete_student_entry(int student_array_index) {
		Student* student;
		student = class_roster_array[student_array_index];
		student->~Student();
		for (int i = student_array_index; i < student_total; i++) {
			class_roster_array[i] = class_roster_array[i + 1];
		}
		student_total--;
}


// remove student from array from passed student ID parameter
void Roster::remove(std::string student_id)
{

	int position = student_position_index(student_id);

	// if student ID exists, delete student
	if (position) {
		delete_student_entry(position);
	}
	else {      // if ID isn't found, print
		std::cout << "Student ID: '" << student_id <<  "' not found." << std::endl;
	}
	return;
}

// print contents of student array
void Roster::print_all() 
{
	std::cout << "Printing Roster:" << std::endl;
	for (int i = 0; i < student_total; i++) {
		Student* student = class_roster_array[i];
		std::cout << i + 1 << " ";
		student->print(); 
	}
}

void Roster::print_avg_days_in_course(std::string student_id) 
{
	int student_pos = student_position_index(student_id);
	Student* student = class_roster_array[student_pos];
	unsigned int days = student->get_average_days_in_course();
	std::cout << "Avearge Days in course for ID '" << student->get_id() << "':" << days << std::endl;
}

void Roster::print_invalid_emails()
{
	std::regex proper_email_addr("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	for (int i = 0; i < student_total; i++) {
		Student* student = class_roster_array[i];
		std::string email = student->get_email();

		if (!std::regex_match(email, proper_email_addr)) {
			std::cout << "Invalid Email: " << email << std::endl;
		}

	}
}

void Roster::print_by_degree_type(std::string degree_type)
{
	Degree temp_degree;
	if (degree_type == "NETWORK") {
		temp_degree = NETWORK;
	}
	else if (degree_type == "SECURITY") {
		temp_degree = SECURITY;
	} 
	else if (degree_type == "SOFTWARE") {
		temp_degree = SOFTWARE;
	}
	else {
		temp_degree = UNDECIDED;
	}


	for (int i = 0, j = 1; i < student_total; i++) {
		Student* student = class_roster_array[i];
		if (student->get_degree_program() == temp_degree) {
			std::cout << j << "\t";
			student->print();
			j++;
		}
	}

}

