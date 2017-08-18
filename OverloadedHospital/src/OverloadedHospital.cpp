//courseID:CIS165-001
//name: Jacob Yanicak
//Prof. Wang
//Assignment#3
//Due by 6/5/2017

#include <iostream>
using namespace std;

/* Write a program that computes and displays the charges for a patient’s hospital stay. First,
the program should ask if the patient was admitted as an in-patient or an outpatient.
If the patient was an in-patient, the following data should be entered:
• The number of days spent in the hospital
• The daily rate
• Hospital medication charges
• Charges for hospital services (lab tests, etc.)
The program should ask for the following data if the patient was an out-patient:
• Charges for hospital services (lab tests, etc.)
• Hospital medication charges
The program should use two overloaded functions to calculate the total charges.
One of the functions should accept arguments for the in-patient data,
while the other function accepts arguments for out-patient information.
Both functions should return the total charges. Input Validation: Do not accept negative numbers for any data.*/

double patientcontroller(int daysin, double rate, double charges, double services);
double patientcontroller(double charges, double services);

int main() {

	// declaring and initializing variables
	int patienttype = 0;
	int daysin = 0;
	double dailyrate = 0.0;
	double medicationcharges = 0.0;
	double hospitalservices = 0.0;
	double totalamount = 0.0;
	string type = "";

	// input validation loop for patient type (in or out)
	do {
		cout << "\n\t\tWas the patient admitted as an in-patient or outpatient?" << endl;
		cout << "\t\t\t(1) in-patient" << endl;
		cout << "\t\t\t(2) outpatient" << endl;
		cout << "\n\t\tPlease enter 1 or 2 : ";
		cin >> patienttype;
		if (patienttype != 1 && patienttype != 2)
			cout << "\n\t\tPlease enter a valid value (1 or 2)."<< endl;
	} while (patienttype != 1 && patienttype != 2);

	// takes information from user input and decides if patient is in- or out-
	switch (patienttype) {
		case 1: // in-patient scenario
			// collecting all data from user in main, input validation on all 4 collectors
			do {
				cout << "\n\t\tEnter the number of days spent in the hospital : ";
				cin >> daysin;
				if (daysin <= 0)
					cout << "\n\t\tPlease enter valid information." << endl;
			} while (daysin <= 0);
			do {
				cout << "\n\t\tPlease enter the daily rate : ";
				cin >> dailyrate;
				if (dailyrate < 0)
					cout << "\n\t\tPlease enter valid information." << endl;
			} while (dailyrate < 0);
			do {
				cout << "\n\t\tPlease enter hospital medication charges : ";
				cin >> medicationcharges;
				if (medicationcharges < 0)
					cout << "\n\t\tPlease enter valid information." << endl;
			} while (medicationcharges < 0);
			do {
				cout << "\n\t\tPlease enter total charges for hospital services (lab tests, etc.) : ";
				cin >> hospitalservices;
				if (hospitalservices < 0)
					cout << "\n\t\tPlease enter valid information" << endl;
			} while (hospitalservices < 0);
			// calling first overloaded function, returns total charges
			totalamount = patientcontroller(daysin, dailyrate, medicationcharges, hospitalservices);
			break;
		case 2: // outpatient scenario
			// collecting all data from user in main, input validation on both collectors
			do {
				cout << "\n\t\tPlease enter hospital medication charges : ";
				cin >> medicationcharges;
				if (medicationcharges < 0)
					cout << "\n\t\tPlease enter valid information." << endl;
			} while (medicationcharges < 0);
			do {
				cout << "\n\t\tPlease enter total charges for hospital services (lab tests, etc.) : ";
				cin >> hospitalservices;
				if (hospitalservices < 0)
					cout << "\n\t\tPlease enter valid information" << endl;
			} while (hospitalservices < 0);
			// calling second overloaded function, returns total charges
			totalamount = patientcontroller(medicationcharges, hospitalservices);
			break;
		default:
			cout << "Error : An invalid choice has somehow been processed" << endl;
		}

	// prompting total charges
	if (patienttype == 1)
		type = "in-";
	else
		type = "out";
	cout << "\n\t\tThe " << type << "patient's total charges amount to $" << totalamount << "." << endl;

	return 0;
}

// first overloaded function for in-patient scenario
double patientcontroller(int daysin, double rate, double charges, double services) {

	double total = 0.0;

	total = daysin * rate + charges + services;

	return total;
}

// second overloaded function for outpatient scenario
double patientcontroller(double charges, double services) {

	double total = 0.0;

	total = charges + services;

	return total;
}
