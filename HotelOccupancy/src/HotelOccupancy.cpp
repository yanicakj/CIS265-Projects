//courseID:CIS165-001
//name: Jacob Yanicak
//Prof. Wang
//Assignment#1
//Due by 5/29/2017

#include <iostream>
#include <string>
using namespace std;

/* Write a program that calculates the occupancy rate for a hotel.
The program should start by asking the user how many ßoors the hotel has.
 A loop should then iterate once for each ßoor. In each iteration,
 the loop should ask the user for the number of rooms on the ßoor and how many of them are occupied.
 After all the iterations, the program should display how many rooms the hotel has,
 how many of them are occupied, how many are unoccupied, and the percentage of rooms that are occupied.
 The percentage may be calculated by dividing the number of rooms occupied by the number of rooms. */

int main() {

	// declaring and initializing variables
	int floors = 0;
	int totalrooms = 0;
	int totaloccupied = 0;
	int totalunoccupied = 0;
	double percentage = 0.0;
	double totaloccupado = 0.0;
	double totalroomz = 0.0;

	// prompting for # of floors and storing, looping for logic
	do {
		cout << "\n\t\tPlease enter the number of floors in the hotel : ";
		cin >> floors;
		if (floors < 1)
			cout << "\n\t\t\tError - Please enter a logical number\n";
	} while ( floors < 1);


	// iterating through floors
	for (int i = 1; i <= floors; i++) {

		int rooms = 0; // counters for rooms and # occupied
		int occupied = 0;

		// loop to check user logic
		do {
			cout << "\n\t\tHow many rooms are on floor " << i << "? Please enter the number : "; // prompting for and storing # rooms
			cin >> rooms;
			cout << "\t\tHow many of the " << rooms << " rooms are occupied? Please enter the number : "; // prompting for and storing # of occupied rooms
			cin >> occupied;
			if (occupied > rooms)
				cout << "\n\t\t\tError - Please enter a logical number\n";
		} while (occupied > rooms);

		// converting ints to double for
		totalrooms += rooms;
		totaloccupied += occupied;
	}

	// converting needed values for percentage calculation to doubles
	totaloccupado = totaloccupied;
	totalroomz = totalrooms;

	// arithmetic for total unoccupied rooms and percentage occupied
	totalunoccupied = totalrooms - totaloccupied;
	percentage = ( totaloccupado / totalroomz ) * 100;

	// prompting final answers
	cout << "\n\t\tTotal number of rooms : " << totalrooms << endl;
	cout << "\t\tTotal number of rooms occupied : " << totaloccupied << endl;
	cout << "\t\tTotal number of rooms unoccupied : " << totalunoccupied << endl;
	cout << "\t\tPercentage of rooms in hotel occupied : " << percentage << "%"<< endl;


	return 0;
}
