//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#9
//Due by 7/10/2017


/*Write a program that has an array of at least 10 string objects that hold people’s names and phone numbers.
You may make up your own strings, or use the following: "Becky Warren, 555-1223" "Joe Looney, 555-0097"
"Geri Palmer, 555-8787" "Lynn Presnell, 555-1212" "Holly Gaddis, 555-8878" "Sam Wiggins, 555-0998" "Bob Kain, 555-8712"
"Tim Haynes, 555-7676" "Warren Gaddis, 555-9037" "Jean James, 555-4939" "Ron Palmer, 555-2783"
The program should ask the user to enter a name or partial name to search for in the array.
Any entries in the array that match the string entered should be displayed. For example, if the user enters “Palmer”
the program should display the following names from the list: Geri Palmer, 555-8787 Ron Palmer, 555-2783*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {

	// declarations & initializations
	const int size = 11;
	int position = 1;
	string input;

	// hardcoding array of data
	string names[size] = {"Becky Warren, 555-1223",
			"Joe Looney, 555-0097",
			"Geri Palmer, 555-8787",
			"Lynn Presnell, 555-1212",
			"Holly Gaddis, 555-8878",
			"Sam Wiggins, 555-0998",
			"Bob Kain, 555-8712",
			"Tim Haynes, 555-7676",
			"Warren Gaddis, 555-9037",
			"Jean James, 555-4939",
			"Ron Palmer, 555-2783", };

	// displaying data
	cout << "\n\tHere is the information on file : " << endl << endl;
    for (int i = 0; i < size; i++) {
            cout << "\t" << names[i] << endl;
    }

    // prompting and storing user input
	cout << "\n\tNow, we will perform a case-sensitive search on this data." << endl << "\n\tPlease enter search criteria : ";
	getline(cin, input);

	// displaying matches using .find function
	cout << "\n\tResults found based on \"" << input << "\" are :" << endl << endl;
    for (int i = 0; i < size; i++) {
        position = names[i].find(input); // searching for index of input in each row's string
        if (position > -1) { // if input exists in row, index will be >= 0
            cout << "\t" << names[i] << endl;
        }
        position = -1;
    }


	return 0;
}
