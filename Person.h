#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Person {

	friend ostream& operator<< (ostream& output, const Person& person);
	friend istream& operator>> (istream& input, Person& p);

public:
	int get_max_width(Person p);
	bool operator== (const string& p2_name) const;
	void add_person();
	void print_person_in_given_city(Person p, string user_input_city);
	void print_all(Person p);

private:
	string name, email, number, city, relative;
};