#include "Student.h"
#include <string>

#pragma once


class Roster
{

	private:
		int student_roster_index;
		const std::string* class_roster_raw;
		Student* class_roster_array[];

	public:
		Roster(const std::string students[], int num_students);
		void add(std::string first_name, std::string last_name, std::string id, std::string email,
			int age, int days_1, int days_2, int days_3, std::string degree);


};
