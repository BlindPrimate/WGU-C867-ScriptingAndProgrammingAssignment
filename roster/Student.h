#pragma once
#include <string>
#include "degree.h"
#include <iostream>

class Student
{
	private:
		std::string first_name, last_name, id, degree, email;
		int age, days_1, days_2, days_3;

	public:
		Student(
			std::string id,
			std::string first_name,
			std::string last_name,
			std::string email,
			int age,
			int days_1,
			int days_2,
			int days_3
		);

		~Student();

		virtual void print() { return; };
		virtual std::string get_degree_program() { return NULL; };

		std::string get_first_name();
		std::string get_last_name();
		std::string get_id();
		std::string get_email();
		std::string get_days_in_course();
		int get_age();


		void set_first_name(std::string value);
		void set_last_name(std::string value);
		void set_id(std::string value);
		void set_email(std::string value);
		void set_days_in_course(int day_1, int day_2, int day_3);
		void set_age(int value);

};

