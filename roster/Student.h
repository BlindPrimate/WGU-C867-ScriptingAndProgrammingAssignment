#include <string>;
#include <list>;

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
		void get_first_name();

};

