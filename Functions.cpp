#include <iostream>

using namespace std;

// get user input from the Menu
int get_user_input()
{
	int choice = 0;

	cout << "1. Initialize (clear all records)" << endl;
	cout << "2. Save contact information to file" << endl;
	cout << "3. Read contact information from file" << endl;
	cout << "4. Add new person to phone book" << endl;
	cout << "5. Remove a person from the phone book" << endl;
	cout << "6. Print a list of persons who live in the given city" << endl;
	cout << "7. Print all contact information, relatives are printed before other persons" << endl;
	cout << "8. Exit" << endl;

	cout << "SELECT ONE OF THE OPTIONS GIVEN ABOVE (Enter a number between 1-8):";
	cin >> choice;

	cout << endl;

	return choice;
}