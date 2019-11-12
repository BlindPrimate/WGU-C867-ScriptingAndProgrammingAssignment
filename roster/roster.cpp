// roster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "SecurityStudent.h"
#include <list>
#include <iterator>
#include <string>
#include "Roster.h"



Roster::Roster(const std::string students[])
{
	num_students = (sizeof(students) / sizeof(students[0]));
	std::cout << students;
	class_roster_raw = students;
	Roster::build_class_roster_array();
}

void Roster::build_class_roster_array()
{
	std::cout << class_roster_raw;
	//Student** classRosterArray = new Student * [num_students];
	for (int i = 0; i < num_students; i++) {
		std::string student = class_roster_raw[i];
		classRosterArray[i] = new Student(student);
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

	std::list<int>::iterator x;

	Roster roster(studentData);
	SecurityStudent student("Ben", "Jamison", "A1", "e@mail.com", 20, 20, 30, 40);
	Student* ben = &student;
	ben->print();

	//std::cout << student.get_first_name();
	//std::cout << "\n";
	//student.set_first_name("Todd");
	//std::cout << student.get_first_name();
	//std::cout << "\n";
	//std::list<int> days = student.get_days_in_course();
	//for (x = days.begin(); x != days.end(); x++) {
	//	std::cout << *x;
	//	std::cout << "\n";
	//}
	//std::cout << "\n";
	//std::cout << student.degree;
	//std::cout << "\n";
	//std::cout << student.last_name;
	//std::cout << "\n";
	//std::cout << student.id;
	//std::cout << "\n";
	//std::cout << student.degree;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
