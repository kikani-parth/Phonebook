#include "Person.h"
#include "constants.h"
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>


// overloaded output operator 
ostream& operator<<(ostream& output, const Person& person)
{
	output << person.name << endl << person.email << endl << person.number
		<< endl << person.city << endl << person.relative << endl;

	return output;
}

//overloaded input operator
istream& operator>>(istream& input, Person& p)
{
	getline(input, p.name);
	getline(input, p.email);
	getline(input, p.number);
	getline(input, p.city);
	getline(input, p.relative);

	return input;
}

// get the max width out of all the data values
int Person::get_max_width(Person p)
{
	int max_width = -1;

	// getting lengths of the data members
	int name_size = p.name.size();
	int email_size = p.email.size();
	int number_size = p.number.size();
	int city_size = p.city.size();
	int relative_size = p.relative.size();

	// comparing each value to get the max_width
	if (max_width < name_size)
	{
		max_width = name_size;
	}
	if (max_width < email_size)
	{
		max_width = email_size;
	}
	if (max_width < number_size)
	{
		max_width = number_size;
	}
	if (max_width < city_size)
	{
		max_width = city_size;
	}
	if (max_width < relative_size)
	{
		max_width = relative_size;
	}


	return max_width;
}

// overloaded comparison operator (checks whether 2 persons' name match)
bool Person::operator==(const string& p2_name) const
{
	if (name == p2_name)
	{
		return true;
	}

	return false;
}

// 4. Add person (this will add person to itself)
void Person::add_person()
{
	cin.ignore();		// clear buffer

	// get user info
	cout << "Enter name:";
	getline(cin, name);

	cout << "Enter email:";
	getline(cin, email);

	cout << "Enter number:";
	getline(cin, number);

	cout << "Enter city:";
	getline(cin, city);

	cout << "Enter relative(s):";
	getline(cin, relative);

	cout << endl << "Person added to the phonebook. Remember to SAVE to file! Press ENTER to continue..." << endl << endl;
}

// 6.
void Person::print_person_in_given_city(Person p, string user_input_city)
{
	int max_width = 0;

	if (p.city == user_input_city)
	{
		// get max width for printing in formatted columns
		max_width = get_max_width(p);

		cout << "Name: " << setw(NAME_LABEL + static_cast<std::streamsize>(max_width)) << p.name << endl;
		cout << "Email: " << setw(EMAIL_LABEL + static_cast<std::streamsize>(max_width)) << p.email << endl;
		cout << "Phone number: " << setw(max_width) << p.number << endl;
		cout << "City: " << setw(CITY_LABEL + static_cast<std::streamsize>(max_width)) << p.city << endl;
		cout << "Relative(s): " << setw(RELATIVE_LABEL + static_cast<std::streamsize>(max_width)) << p.relative << endl << endl;

	}

}

// 7. print all contact info
void Person::print_all(Person p)
{
	int max_width = 0;

	// get max width for printing in formatted columns
	max_width = get_max_width(p);

	cout << "Relative(s): " << setw(RELATIVE_LABEL + static_cast<std::streamsize>(max_width)) << p.relative << endl;
	cout << "Name: " << setw(NAME_LABEL + static_cast<std::streamsize>(max_width)) << p.name << endl;
	cout << "Email: " << setw(EMAIL_LABEL + static_cast<std::streamsize>(max_width)) << p.email << endl;
	cout << "Phone number: " << setw(max_width) << p.number << endl;
	cout << "City: " << setw(CITY_LABEL + static_cast<std::streamsize>(max_width)) << p.city << endl << endl;

}