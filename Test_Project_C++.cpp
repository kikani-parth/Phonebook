#include <iostream>
#include <vector>
#include "Person.h"
#include "Functions.h"
#include "constants.h"
#include "Phonebook.h"

using namespace std;

int main()
{
	Phonebook phonebook_obj;
	int choice = 0;

	while (choice != EXIT)
	{
		choice = get_user_input();		// get user input from the MENU

		switch (choice)
		{

		case 1:

			phonebook_obj.initialize();
			break;

		case 2:

			try
			{
				phonebook_obj.save_to_file();
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
			}

			break;

		case 3:

			try
			{
				phonebook_obj.read_from_file();
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
			}

			break;

		case 4:

			phonebook_obj.add_person_to_phonebook();

			/*
				continuing only if user presses 'Enter' key on the keyboard.
				(Implemented this functionality so that the user does not miss to read the SAVE message)
			*/
			cin.ignore();

			break;

		case 5:

			try
			{
				phonebook_obj.remove_person_from_file();
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
			}

			break;

		case 6:

			try
			{
				phonebook_obj.print_person_in_given_city();
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
			}

			break;

		case 7:

			try
			{
				phonebook_obj.print_all();
			}
			catch (runtime_error& e)
			{
				cout << e.what() << endl;
			}

			break;

		case 8:

			cout << "You have exited the program." << endl;
			break;


		default:
			cout << "Error: Please enter a number between 1-8. Press Enter to go back to MENU..." << endl;
			cin.ignore(2);
			break;
		}

	}

}

