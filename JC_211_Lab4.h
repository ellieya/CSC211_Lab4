/*
Lab 4 - Contact Database
Jiali Chen
We create a contact database by using two classes, one which contains the other.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

class contact {
	string first_name;
	string last_name;
	string email;
	string phone;

public:
	contact();
	contact(string, string, string, string);
    //Accessor methods
	string get_name();
	string get_fname();
	string get_lname();
	string get_email();
	string get_phone();
    
	//Mutator methods
	void set_first_name(string);
	void set_last_name(string);
	void set_email(string);
	void set_phone(string);

    //Input methods
	void input_name();
	void input_email();
	void input_phone();

    //Overloaded << function (friend)
	friend ostream& operator <<(ostream& out, contact& target);
	//Prints contact class in this format: "FIRSTNAME LASTNAME EMAIL PHONENUMBER"
};

class database {

	contact _database[100];
	int total_contacts = 0;
    
public:

	void initialize();
	//Make all element data members equal to " ". Then, populates the contact list with data from file.

	void menu();
	//Print the main menu. Uses user input to direct user to the correct function.
	
	void add_contact();
	//Look through database for the next empty slot, then ask user for input
	//POST:
	//User input placed into data member
	//SHOULD ADD FEATURE WHERE YOU CAN SEARCH FOR SAME PHONE NUMBER AND DENY ENTRY

	void edit_contact();
	//Searches contact by ID, then edits contact with that ID.
	//POST:
	//Selected contact's selected data member will be revised with user input
	//If contact is not found, returns error message.

	void delete_contact();
	//Searches contact by ID, then deletes contact with that ID.
	//POST:
	//Selected contact data blanked out to default values
	//If contact is not found, returns error message.

	void display_all_contacts();
	//POST:
	//Lists all contacts with a valid phone number
	//If there are no contacts, prints 'NONE FOUND'.

//SEARCH FUNCTIONS
	int search_by_phone(string);
	int search_by_id(int);
	//POST (for all search functions):
	//If successful: returns element index
	//If unsuccessful: returns -1

};
