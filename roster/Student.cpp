#include "Student.h"

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


void get_first_name()
{
	return Student::first_name;
}
