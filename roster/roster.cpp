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


inline bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

Roster::Roster(const std::string students[], int student_arr_size) : class_roster_raw(students)
{
	for (int i = 0; i < student_arr_size - 1; i++) {

		std::vector<std::string> stripped_strs;
		std::vector<int> stripped_days;
		std::stringstream ss(class_roster_raw[i]);
		while (ss.good()) {
			std::string new_str;
			std::getline(ss, new_str, ',');
			if (isInteger(new_str)) {
				stripped_days.push_back(std::stoi(new_str));
				//std::cout << "ints: " << new_str << std::endl;
			}
			stripped_strs.push_back(new_str);
			//std::cout << new_str << std::endl;
		}

		//for (i = 0; i < stripped_strs.size(); i++) {
		//	std::cout << stripped_strs[i] << std::endl;
		//}

		//for (i = 0; i < stripped_days.size(); i++) {
		//	std::cout << stripped_days[i] << std::endl;
		//}


		Roster::add(stripped_strs[0], stripped_strs[1], stripped_strs[2], stripped_strs[3],
			stripped_days[0], stripped_days[1], stripped_days[2], stripped_days[3], stripped_strs[8]);

	}
}


void Roster::add(std::string id, std::string first_name, std::string last_name, std::string email,
				int age, int days_1, int days_2, int days_3, std::string degree)
{
		// initialize pointer for student object
		Student *ptr = nullptr;
	
		// sort student based on degree
		if (degree == "NETWORK" ) {
			std::cout << "network" << std::endl;
			ptr = new NetworkStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
			std::cout << ptr << std::endl;
		} else if (degree == "SECURITY") {
			std::cout << "security" << std::endl;
			ptr = new SecurityStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		} else {
			std::cout << "software" << std::endl;
			ptr = new SoftwareStudent(id, first_name, last_name, email, age, days_1, days_2, days_3);
		}

		class_roster_array[student_roster_index] = ptr;
		student_roster_index++;
}

void Roster::remove(std::string student_id)
{
	return;
}

void Roster::print_all() {
	
	for (int i = 0; i < student_roster_index; i++) {
		Student student = *class_roster_array[i];
		std::cout << student.get_degree_program();
	}

}



int main()
{

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,[firstname],[lastname],[emailaddress],[age],[numberofdaystocomplete3courses],SOFTWARE"
	};


	Roster roster(studentData, 5);
	roster.print_all();
}