#pragma once
#include "Student.h"
#include <string>



class Roster
{

	private:
		int student_roster_index;
		const std::string* class_roster_raw;
		Student* class_roster_array[50];

	public:
		Roster(const std::string students[], int num_students);

		void add(std::string id, std::string first_name, std::string last_name, std::string email,
			int age, int days_1, int days_2, int days_3, std::string degree);

		void remove(std::string student_id);

		void print_all();

};
