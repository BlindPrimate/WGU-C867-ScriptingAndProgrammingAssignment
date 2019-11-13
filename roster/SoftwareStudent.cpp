#include "SoftwareStudent.h"
#include "degree.h"



std::string SoftwareStudent::get_degree_program() {
	return "Software";
}


void SoftwareStudent::print() {
	std::cout << "ID: " << get_id() << "\tFirst Name: " << get_first_name()
		<< "\tLast Name: " << get_last_name() << "\tAge: " << get_age() << "\tDays in Course: "
		<< get_days_in_course() << "\tDegree: " << get_degree_program() << std::endl;
}
