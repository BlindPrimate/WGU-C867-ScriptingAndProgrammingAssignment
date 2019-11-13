// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
		std::vector<int> stripped_days;
		// convert student string to stringstream
		std::stringstream ss(class_roster_raw[i]);
		// parse strings with commas as delimiter and push into string vectors
		while (ss.good()) {
			std::string new_str;
			std::getline(ss, new_str, ',');
			if (isInteger(new_str)) {
				stripped_days.push_back(std::stoi(new_str));
			}
			stripped_strs.push_back(new_str);
		}


		// add student
		Roster::add(stripped_strs[0], stripped_strs[1], stripped_strs[2], stripped_strs[3],
			stripped_days[0], stripped_days[1], stripped_days[2], stripped_days[3], stripped_strs[8]);

	}
}


void Roster::add(std::string id, std::string first_name, std::string last_name, std::string email,
				int age, int days_1, int days_2, int days_3, std::string degree)
{
		// initialize pointer for student object
		Student *ptr = nullptr;
	
		// sort student based on degree and create appropriate Student obj
		if (degree == "NETWORK" ) {
			ptr = new NetworkStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		} 
		else if (degree == "SECURITY") {
			ptr = new SecurityStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		}
		else {
			ptr = new SoftwareStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		}

		// pass student object pointer to class_roster_array
		class_roster_array[student_roster_index] = ptr;
		student_roster_index++;
}


void Roster::remove(std::string student_id)
{
	Student* student;
	std::string id;
	bool is_removed = false;
	// loop student roster
	for (int i = 0; i < student_roster_index; i++) {
		student = class_roster_array[i];
		id = student->get_id();
		// check against ID parameter and delete if student matches
		if (id == student_id) {
			is_removed = true;

			// delete student obj
			student->~Student();

			// delete item from array
			for (int j = i; j < student_roster_index; i++) {
				class_roster_array[j++] = class_roster_array[i + 1];
			}
			student_roster_index--;
			break;
		}
	}
	// if ID isn't found, print
	if (!is_removed) {
		std::cout << "Student ID: '" << id <<  "' not found." << std::endl;
	}
	return;
}

// print contents of student array
void Roster::print_all() {
	std::cout << "Printing Roster:" << std::endl;
	for (int i = 0; i < student_roster_index; i++) {
		Student* student = class_roster_array[i];
		std::cout << i + 1 << " ";
		student->print(); 
	}
}



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
	roster.remove("A2");
	roster.remove("D1");
	roster.print_all();
}