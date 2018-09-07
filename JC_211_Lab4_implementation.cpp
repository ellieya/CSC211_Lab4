#include "JC_211_Lab4.h"

contact::contact()
	: first_name(" "), last_name(" "), email(" "), phone(" ")
{
	//Intentionally blank
}

contact::contact(string fname, string lname, string email, string phone)
	: first_name(fname), last_name(lname), email(email), phone(phone)
{

}

string contact::get_name() {
	return (first_name + " " + last_name);
}

string contact::get_lname() {
	return last_name;
}

string contact::get_fname() {
	return first_name;
}

string contact::get_email() {
	return email;
}

string contact::get_phone() {
	return phone;
}

void contact::set_first_name(string name) {
	first_name = name;
}

void contact::set_last_name(string name) {
	last_name = name;
}

void contact::set_email(string txt) {
	email = txt;
}

void contact::set_phone(string num) {
	phone = num;
}

void contact::input_name() {
	cout << "Enter name: ";
	cin >> first_name >> last_name;
}

void contact::input_email() {
	cout << "Enter e-mail: ";
	cin >> email;
}

void contact::input_phone() {
	cout << "Enter phone number: ";
	cin >> phone;
	
}

void database::initialize() {
	ifstream fin;
	int counter = 0;
	string temp_fname, temp_lname, temp_email, temp_phone;

	//Clean out _database
	for (int i = 0; i < 100; i++) {
		_database[i].set_first_name(" ");
		_database[i].set_last_name(" ");
		_database[i].set_email(" ");
		_database[i].set_phone(" ");
	}

	//Plug file data into database
	fin.open("10sample.txt");

	if (fin.fail()) {
		cout << "File failed to open. Terminating program." << endl;
		exit(1);
	}

	while (!fin.eof()) {
		fin >> temp_fname >> temp_lname >> temp_email >> temp_phone;
		_database[counter].set_first_name(temp_fname);
		_database[counter].set_last_name(temp_lname);
		_database[counter].set_email (temp_email);
		_database[counter].set_phone(temp_phone);
		counter++;

		//Increment total contacts
		total_contacts++;
	}
	fin.close();
}

void database::menu() {

	int userInput;

	do {
		cout << "Menu: " << '\n'
			<< "1) View all contacts\n"
			<< "2) Add contact\n"
			<< "3) Edit a contact\n"
			<< "4) Delete a contact\n"
			<< "0) Exit program" << "\n\n"
			<< "Input: ";

		cin >> userInput;
		system("cls");


		switch (userInput) {
		case 1:
			display_all_contacts();
			break;
		case 2:
			cout << "ADD CONTACT" << endl;
			add_contact();
			break;
		case 3:
			cout << "EDIT CONTACT" << endl;
			edit_contact();
			break;
		case 4:
			cout << "DELETE CONTACT" << endl;
			delete_contact();
			break;
		case 0:
			cout << "Program exiting." << endl;
			break;
		default:
			system("cls");
			cout << "UNRECOGNIZED COMMAND. Try again.\n" << endl;
		}
	} while (userInput != 0);
}

void database::add_contact() {
	int temp = 0;
	int duplicate_flag = -1;

	string temp_fname, temp_lname, temp_email, temp_phone;

	//Ask for input; contact class input methods cannot be used due to check searching itself
	cout << "Enter name: ";
	cin >> temp_fname >> temp_lname;
	cout << "Enter email: ";
	cin >> temp_email;
	cout << "Enter phone number: ";
	cin >> temp_phone;

	//Check for duplicates
	duplicate_flag = search_by_phone(temp_phone);

	if (duplicate_flag != -1) {
		cout << "\nContact " << _database[duplicate_flag].get_name()
			<< " already has the phone number \'"
			<< temp_phone
			<< "\'\nPhone numbers must be UNIQUE. Contact cannot be added." << endl;
		Sleep(3000); //Additional sleep time due to long message
	}
	else {
		//Look through database for the next empty slot
		while (_database[temp].get_phone() != " ") {
			temp++;
		}

		//Transfer temporary data to database
		_database[temp].set_first_name(temp_fname);
		_database[temp].set_last_name(temp_lname);
		_database[temp].set_email(temp_email);
		_database[temp].set_phone(temp_phone);

		//Confirmation message
		cout << "Contact added. Returning to main menu...";

		//Increment total_contacts
		total_contacts++;
	}

	Sleep(2000);
	system("cls");

}

void database::edit_contact() {
	int temp, temp2;
	int userInput;
	display_all_contacts();

	cout << "Enter contact ID: ";
	cin >> userInput;

	temp = search_by_id(userInput);

	if (temp != -1) {
		cout << "\nEDITING: " << _database[temp];
		cout << "\nWhat do you want to change?\n\n"
			<< "1) Name\n"
			<< "2) E-mail address\n"
			<< "3) Phone number\n" << endl;
		cin >> temp2;
		cout << '\n';

		switch (temp2) {
		case 1:
			_database[temp].input_name();
			cout << "Name updated to " << _database[temp].get_name() << '.' << endl;
			break;
		case 2:
			_database[temp].input_email();
			cout << "Email updated to " << _database[temp].get_email() << '.' << endl;
			break;
		case 3:
			_database[temp].input_phone();
			cout << "Phone updated to " << _database[temp].get_phone() << '.' << endl;
			break;
		}
		cout << "\nNEW: " << _database[temp];
		Sleep(3000);
	}
	else
		cout << "Contact not found." << endl;

	system("cls");
}

void database::delete_contact() {
	int temp;
	int userInput;
	display_all_contacts();

	cout << "Enter contact ID: ";
	cin >> userInput;

	temp = search_by_id(userInput);

	if (temp != -1) {
		cout << _database[temp] << "has been deleted." << endl;

		//Decrement total_contacts
		total_contacts--;

		//Replace element data member values with space
		_database[temp].set_first_name(" ");
		_database[temp].set_last_name(" ");
		_database[temp].set_email(" ");
		_database[temp].set_phone(" ");
	}
	else
		cout << "Contact not found." << endl;

	Sleep(2000);
	system("cls");
}

void database::display_all_contacts() {

	int counter = 0;
	cout << "Existing contacts " << '(' << total_contacts << ")\n" << endl;
	for (int i = 0; i < 100; i++) {
		if (_database[i].get_fname() != " ") {
			counter++;
			cout << counter << ") " << _database[i];
		}
	}
	if (counter == 0) {
		cout << "NONE FOUND." << endl;
	}
	cout << '\n';
}

int database::search_by_id(int userInput) {

	int counter = 0, index = -1;

	while ((index < 100) && (userInput != counter)) {
		index++;
		if (!(_database[index].get_fname() == " ")) {
			counter++;
		}
	}

	if (index == 100) {
		return -1;
	}
	else {
		return index;
	}
}

int database::search_by_phone(string userInput) {
	int index = 0;

	while ( (index < 100) && (userInput != _database[index].get_phone()) ) { //Sentinel must be placed first or else program crashes due to array overflow
		index++;
	}

	if (index == 100)
		return -1;
	else
		return index;
}


ostream& operator <<(ostream& out, contact& target) {
	out << target.first_name << ' '
		<< target.last_name << ' '
		<< target.email << ' '
		<< target.phone << ' '
		<< endl;

	return out;
}

