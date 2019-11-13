#pragma once
#include "Student.h"
#include <string>



class Roster
{

	private:
		int student_total;
		const std::string* class_roster_raw;
		int student_position_index(std::string student_id);
		void delete_student_entry(int student_array_index);
		Student* class_roster_array[50];

	public:
		Roster(const std::string students[], int num_students);


		void add(std::string id, std::string first_name, std::string last_name, std::string email,
			int age, int days_1, int days_2, int days_3, int degree);

		void remove(std::string student_id);

		void print_all();

		void print_days_in_course(std::string student_id);

		void print_invalid_emails();

		void print_by_degree_type(std::string degree_program);

};
