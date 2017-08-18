//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#12
//Due by 7/31/2017

/*Write a program that uses a structure to store the following inventory data in a Þle:
Item Description
Quantity on Hand
Wholesale Cost
Retail Cost
Date Added to Inventory
The program should have a menu that allows the user to perform the following tasks:
¥ Add new records to the file.
¥ Display any record in the file.
¥ Change any record in the file.
Input Validation: The program should not accept quantities, or wholesale or retail costs,
less than 0. The program should not accept dates that the programmer determines are unreasonable.*/

// Note: text file used in this program is called inventory.txt

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

const int size = 51;
int datesize = 11;
//ofstream infile;
//ifstream infile;
//fstream file;

struct Inventory {
	char description[size];
	int quantity;
	double wholesale;
	double retail;
	char dateadded[11];
};

// prototypes
void add();
void display();
void change();

int main() {

	int holder = 0;
	int choice = 0;
	bool flag = true;

	////////////////

	ofstream outfile;
	outfile.open("inventory.txt");
	outfile << "Hello";
	outfile.close();

	string place;
	ifstream infile;
	infile.open("inventory.txt");
	while (!infile.eof()) {
		infile >> place;
	}
	cout << place;
	infile.close();

	///////////////

	//file.open("inventory.txt", ios::in | ios::out | ios::binary);

	cout << "Welcome to Inventory Manager!" << endl;

	// looping to keep program running
	while (flag) {

		// looping for input validation
		do {
			cout << "Please choose an option : " << endl;
			cout << "Enter (1) for adding an new item" << endl;
			cout << "Enter (2) for displaying item information" << endl;
			cout << "Enter (3) for editting a record on file" << endl;
			cin >> holder;
			switch (holder) {
				case 1: add(); break;
				case 2: display(); break;
				case 3: change(); break;
				default: cout << "Please enter a valid choice!" << endl;
			}
		} while (holder != 1 && holder != 2 && holder != 3);

		cout << "\nDo you wish to continue?" << endl;
		cout << "Enter (1) for yes" << endl;
		cout << "Enter (2) for no" << endl;
		cin >> choice;
		switch (choice) {
			case 1: break;
			case 2: flag = false; break;
			default: cout << "Please enter a valid choice!" << endl;
		}
	}

	//file.close();
	cout << "Exiting program..";

	return 0;
}

// function to add an item to inventory
void add() {

	Inventory Item;
	int recnum;
	fstream outfile;

	// opening file
	outfile.open("inventory.txt", ios::out | ios::ate | ios::in | ios::binary);

	if (outfile.fail())
		cout << "\nFile failed to open" << endl;

	cout << "\nPlease enter the record ID to be added (will overwrite duplicates) : ";
	cin >> recnum;
	cout << "\n" << recnum << " has been set as the record ID for this item." << endl;

	cout << "Please enter item description in 50 characters or less : ";
	cin.ignore();
	cin.getline(Item.description, size);

	// do-whiles below are for looping for input validation
	do {
		cout << "Please enter the number of items on hand : ";
		cin >> Item.quantity;
		if (Item.quantity < 0)
			cout << "Please enter a valid number." << endl;
	} while (Item.quantity < 0);

	do {
		cout << "Please enter the wholesale price for this item : ";
		cin >> Item.wholesale;
		if (Item.wholesale < 0.01)
			cout << "Please enter a valid number." << endl;
	} while (Item.wholesale < 0.01);

	do {
		cout << "Please enter the retail price for this item : ";
		cin >> Item.retail;
		if (Item.retail < 0.01)
			cout << "Please enter a valid number." << endl;
	} while (Item.retail < 0.01);

	// couldn't figure out how to perform input validation for date
	cout << "Please enter the date this item was added (format: mm/dd/yyyy) : ";
	cin.ignore();
	cin.getline(Item.dateadded, datesize);

	// finding position in file, writing to file, closing file
	outfile.seekp(recnum*sizeof(Item), ios::beg);
	outfile.write(reinterpret_cast<char *>(&Item), sizeof(Item));
	outfile.close();

}

void display() {

	Inventory Item;
	int recnum;
	ifstream infile;

	// opening file
	infile.open("inventory.txt", ios::in | ios::binary);

	if (infile.fail())
		cout << "\nFile failed to open" << endl;

	cout << "\nPlease enter record ID of item to display : ";
	cin >> recnum;

	// finding position of file, readinf information at position into program
	infile.seekg(recnum*sizeof(Item), ios::beg);
	infile.read(reinterpret_cast<char *>(&Item), sizeof(Item));

	// displaying information on file
	cout << "Decription : " << Item.description << endl;
	cout << "Quantity : " << Item.quantity << endl;
	cout << "Wholesale : " << Item.wholesale << endl;
	cout << "Retail : " << Item.retail << endl;
	cout << "Date Added : " << Item.dateadded << endl;

	// closing file
	infile.close();

}

void change() {

	Inventory Item;
	int recnum;
	fstream file;

	// opening file
	file.open("inventory.txt", ios:: in | ios::ate | ios::out | ios::binary);

	if (file.fail())
		cout << "\nFile failed to open" << endl;

	cout << "\nPlease enter record ID of item to edit : ";
	cin >> recnum;

	// finding position of file, readinf information at position into program
	file.seekg(recnum*sizeof(Item), ios::beg);
	file.read(reinterpret_cast<char *>(&Item), sizeof(Item));

	// displaying information on file
	cout << "Information on file : " << endl << endl;
	cout << "Decription : " << Item.description << endl;
	cout << "Quantity : " << Item.quantity << endl;
	cout << "Wholesale : " << Item.wholesale << endl;
	cout << "Retail : " << Item.retail << endl;
	cout << "Date Added : " << Item.dateadded << endl << endl;
	cout << "Please enter the updated information : " << endl << endl;

	// accepting new information from user
	cout << "Please enter item description in 50 characters or less : ";
	cin.ignore();
	cin.getline(Item.description, size);

	// do-while loops below for input validation
	do {
		cout << "Please enter the number of items on hand : ";
		cin >> Item.quantity;
		if (Item.quantity < 0)
			cout << "Please enter a valid number." << endl;
	} while (Item.quantity < 0);

	do {
		cout << "Please enter the wholesale price for this item : ";
		cin >> Item.wholesale;
		if (Item.wholesale < 0.01)
			cout << "Please enter a valid number." << endl;
	} while (Item.wholesale < 0.01);

	do {
		cout << "Please enter the retail price for this item : ";
		cin >> Item.retail;
		if (Item.retail < 0.01)
			cout << "Please enter a valid number." << endl;
	} while (Item.retail < 0.01);

	// couldn't figure out how to perform input validation for date
	cout << "Please enter the date this item was added (format: mm/dd/yyyy) : ";
	cin.ignore();
	cin.getline(Item.dateadded, datesize);

	// finding position in file, writing to file, closing file
	file.seekp(recnum*sizeof(Item), ios::beg);
	file.write(reinterpret_cast<char *>(&Item), sizeof(Item));
	file.close();

}
