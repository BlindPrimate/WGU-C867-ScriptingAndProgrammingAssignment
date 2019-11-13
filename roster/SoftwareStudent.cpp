#include "SoftwareStudent.h"
#include "degree.h"



std::string SoftwareStudent::get_degree_program() {
	return "Software";
}


void SoftwareStudent::print() {
	std::cout << "\tID: " << get_id() << "\tFirst Name: " << get_first_name()
		<< "\tLastName: " << get_last_name() << "\tDays in Course: "
		<< get_days_in_course() << "\tDegree: " << get_degree_program() << std::endl;
}
