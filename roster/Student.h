#include <string>
#include <list>
#include <iostream>
#include "degree.h"

#pragma once
class Student
{
	private:
		std::string first_name, last_name, id, degree, email;
		std::list<int> days_in_course;
		int age, days_1, days_2, days_3;

	public:
		Student(std::string s_first_name,
			std::string s_last_name,
			std::string s_id,
			std::string s_email,
			int s_age,
			int days_1,
			int days_2,
			int days_3
		);

		~Student();

		virtual void print()
		{
			std::cout << "Student ID: " << id << std::endl;
			std::cout << "Name: " << first_name << " " << last_name << std::endl;
			std::cout << "Email: " << email << std::endl;
			std::cout << "Age: " << age << std::endl;
			//std::cout << "Days in Course: " << days_in_course << std::endl;
			std::cout << std::endl << std::endl;
			//std::list<int> days = student.get_days_in_course();
			//for (x = days.begin(); x != days.end(); x++) {
			//	std::cout << *x;
			//	std::cout << "\n";
			//}
		}

		std::string get_first_name();
		std::string get_last_name();
		std::string get_id();
		std::string get_email();
		std::list<int> get_days_in_course();
		int get_age();


		void set_first_name(std::string value);
		void set_last_name(std::string value);
		void set_id(std::string value);
		void set_email(std::string value);
		void set_days_in_course(std::list<int> value);
		void set_age(int value);

};

