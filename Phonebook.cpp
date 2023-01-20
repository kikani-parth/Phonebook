#include "Phonebook.h"
#include <string> 

// 1. initialize (deletes the elements of the phonebook vector)
void Phonebook::initialize()
{
	phonebook.clear();
	cout << "Phonebook is initialized for further use!" << endl << endl;
}

// 2. saves the phonebook vector to file
void Phonebook::save_to_file()
{
	ofstream fout;
	fout.open(PHONEBOOK, ios::app);		//opening in append mode

	if (!fout)
	{
		throw runtime_error("Error opening the file: " + PHONEBOOK);
	}

	// write to file
	for (auto& p : phonebook)
	{
		fout << p;
	}

	fout.close();

	cout << "Saved successfully!" << endl << endl;

	initialize();

}

// 3. reads the file and stores it in the phonebook vector
void Phonebook::read_from_file()
{
	initialize();		// initializing the phonebook for reading
	Person p;
	ifstream fin;

	fin.open(PHONEBOOK);

	if (!fin)
	{
		throw runtime_error("Error opening the file: " + PHONEBOOK);
	}

	// read from file
	while (fin >> p)
	{
		// add person to phonebook
		phonebook.push_back(p);
	}

	fin.close();

	cout << "Reading from file is successful!" << endl << endl;

}

// 4. adds person to phonebook vector
void Phonebook::add_person_to_phonebook()
{
	Person p;

	p.add_person();		// adding person to itself

	// add person to phonebook
	phonebook.push_back(p);
}

// 5. remove person from the phonebook
void Phonebook::remove_person_from_file()
{
	ofstream fout;
	string person_to_be_removed;

	cin.ignore();

	cout << "Enter name of the person which shall be removed:";
	getline(cin, person_to_be_removed);

	cout << endl;

	//read contents of file
	read_from_file();

	//opening file in truncate mode to delete all the contents before writing
	fout.open(PHONEBOOK, ios::trunc);

	if (!fout)
	{
		throw runtime_error("Error opening the file: " + PHONEBOOK);
	}

	/*
		this loop will write everything to "phonebook.txt" file
		except the person that needs to be removed
	*/
	for (auto& p : phonebook)
	{
		if (!(p == person_to_be_removed))
		{
			// write to file
			fout << p;
		}
	}

	// close the file
	fout.close();

	cout << "Given person was removed successfully!" << endl << endl;

	initialize();		// initializing the phonebook for further use		

}

// 6. print person living in the given city
void Phonebook::print_person_in_given_city()
{
	string user_input_city;

	cin.ignore();

	cout << "Enter city:";
	getline(cin, user_input_city);

	cout << endl;

	// read contents from file
	read_from_file();

	// print persons who live in the given city
	cout << "Now printing data..." << endl << endl;

	for (auto& p : phonebook)
	{
		p.print_person_in_given_city(p, user_input_city);
	}

	initialize();		// initializing the phonebook for further use

}

// 7. print the whole phonebook but relatives of a person will be printed first
void Phonebook::print_all()
{
	// read contents from file
	read_from_file();

	cout << "Now printing data..." << endl << endl;

	for (auto& p : phonebook)
	{
		p.print_all(p);
	}

	initialize();		// initializing the phonebook for further use
}
