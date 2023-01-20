#pragma once

#include "Person.h"
#include "constants.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Phonebook {

public:
	void initialize();
	void save_to_file();
	void read_from_file();
	void add_person_to_phonebook();
	void remove_person_from_file();
	void print_person_in_given_city();
	void print_all();

private:
	vector<Person> phonebook;

};