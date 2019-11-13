#include "NetworkStudent.h"
#include "degree.h"

std::string NetworkStudent::get_degree_program() {
	return "Network";
}

void NetworkStudent::print() {
	std::cout << "ID: " << get_id() << "\tFirst Name: " << get_first_name()
		<< "\tLast Name: " << get_last_name() << "\tAge: " << get_age() << "\tDays in Course: "
		<< get_days_in_course() << "\tDegree: " << get_degree_program() << std::endl;
}
