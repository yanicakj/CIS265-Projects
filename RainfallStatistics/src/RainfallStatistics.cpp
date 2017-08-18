//courseID:CIS165-001
//name: Jacob Yanicak
//Prof. Wang
//Assignment#4
//Due by 6/19/2017

#include <iostream>
#include <string>
using namespace std;

/* Write a program that lets the user enter the total rainfall for each of 12 months into an array of doubles.
 * The program should calculate and display the total rainfall for the year, the average monthly rainfall,
 * and the months with the highest and lowest amounts. Input Validation: Do not accept negative numbers for
 * monthly rainfall Þgures.*/

// prototypes
void display(double rainfallarray[12], string months[12]);
double totalrainfallfunction(double rainfallarray[12]);
void findhighest(double rainfall[12], string months[12]);
void findlowest(double rainfall[12], string months[12]);

int main() {

	// declaration & initialization
	double totalrainfall = 0.0;
	double averagerainfall = 0.0;
	double rainfallnumbers[12] = {};
	string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September","October", "November", "December" };

	// looping to get rainfall stats for each month, rejecting negative numbers
	for (int i = 0; i <= 11; i++) {
		do {
		cout << "\n\t\tPlease enter total rainfall for the month of " << months[i] << " in inches : ";
		cin >> rainfallnumbers[i];
		if (rainfallnumbers < 0)
			cout << "\n\t\tPlease enter a valid, positive number." << endl;
		} while (rainfallnumbers[i] < 0);
	}

	// display function if needed
	//display(rainfallnumbers, months);

	// calling functions to get total & average
	totalrainfall = totalrainfallfunction(rainfallnumbers);
	averagerainfall  = totalrainfall / 12;

	// prompting the total and average from previous functions
	cout << "\n\t\tThe total rainfall of the year is " << totalrainfall << " inches." << endl;
	cout << "\n\t\tThe average monthly rainfall is " << averagerainfall << " inches." << endl;

	// calling functions to find highest and lowest rainfalls
	findhighest(rainfallnumbers, months);
	findlowest(rainfallnumbers, months);

	return 0;
}

// display function if needed
/* void display(double rainfallarray[12], string months[12]) {

	for (int i = 0; i <= 11; i++) {
		cout << "The total rainfall in " << months[i] << " was " << rainfallarray[i] << " inches. " << endl;
	}

} */

// function to find total rainfall, adds 12 months together
double totalrainfallfunction(double rainfallarray[12]) {

	double totalamount = 0.0;

	for (int i = 0; i <= 11; i++) {
		totalamount += rainfallarray[i];
	}

	return totalamount;
}

// function to find month with highest rainfall amount
void findhighest(double rainfall[12], string months[12]) {

	double highcontainer = 0.0;

	for (int i = 0; i <= 11; i++) {
		if (rainfall[i] > highcontainer)
			highcontainer = rainfall[i];
	}

	// matching a rainfall number to a month's name
	for (int i = 0; i <= 11; i++) {
		if (highcontainer == rainfall[i])
			cout << "\n\t\t" << months[i] << " had the greatest amount of rainfall with " << rainfall[i] << " inches." << endl;
	}
}

// function to find month with lowest rainfall amount
void findlowest(double rainfall[12], string months[12]) {

	double lowcontainer = 1000000000.0;

	for (int i = 0; i <= 11; i++) {
		if (rainfall[i] < lowcontainer)
			lowcontainer = rainfall[i];
	}

	// matching a rainfall number to a month's name
	for (int i = 0; i <= 11; i++) {
		if (lowcontainer == rainfall[i])
			cout << "\n\t\t" << months[i] << " had the least amount of rainfall with " << rainfall[i] << " inches." << endl;
	}

}
