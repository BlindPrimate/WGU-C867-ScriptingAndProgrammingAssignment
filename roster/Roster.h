#include "Student.h"
#include <string>

#pragma once


class Roster
{

	private:
		int num_students;

	public:

		Roster(const std::string students[]);
		Student** classRosterArray;
		const std::string* class_roster_raw;
		void build_class_roster_array();


};
