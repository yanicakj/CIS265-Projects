//courseID:CIS165-001
//name: Jacob Yanicak
//Prof. Wang
//Assignment#2
//Due by 6/5/2017

#include <iostream>
#include <string>
using namespace std;

/* Write a program that determines which of a company’s four divisions (Northeast,
Southeast, Northwest, and Southwest) had the greatest sales for a quarter.
It should include the following two functions, which are called by main.
• double getSales() is passed the name of a division. It asks the user for a division’s quarterly sales figure,
validates the input, then returns it. It should be called once for each division.
• void findHighest() is passed the four sales totals. It determines which is the largest and
prints the name of the high grossing division, along with its sales figure.
Input Validation: Do not accept dollar amounts less than $0.00. */

double getSales (string divisionname);
void findHighest(double NEsale, double SEsale, double NWsale,double SWsale);

int main() {

	// declaring and initializing variables
	double northeastsales, southeastsales, northwestsales, southwestsales;
	string divisions[] = { "Northeast", "Southeast", "Northwest", "Southwest" };

	// calling getSales
	northeastsales = getSales(divisions[0]);
	southeastsales = getSales(divisions[1]);
	northwestsales = getSales(divisions[2]);
	southwestsales = getSales(divisions[3]);

	// calling findHighest
	findHighest(northeastsales, southeastsales, northwestsales, southwestsales);

	return 0;
}

// getSales function, input a division name, outputs sales figure
double getSales (string divisionname) {

	double salesfigure = 0.0;

	// do while loop for input validation
	do {
		cout << "\n\t\tWhat is the " << divisionname << " division's quarterly sales figure : ";
		cin >> salesfigure;
		if (salesfigure < 0.00)
			cout << "\n\t\t\tPlease enter a number greater than 0.00" << endl;
		} while (salesfigure < 0.00);

	return salesfigure;
}

// findHighest function, input 4 division names, prompts greatest earner with amount
void findHighest(double NEsale, double SEsale, double NWsale,double SWsale) {

	double container = 0.0;
	double sales[] = { NEsale, SEsale, NWsale, SWsale };
	string highestdivision = "";

	// loop to find highest sales figure
	for (int i = 0; i < 4; i++) {
		if (sales[i] > container)
			container = sales[i];
	}

	// matching highest salesfigure to a name
	if (container == NEsale)
		highestdivision = "Northeast";
	else if (container == SEsale)
		highestdivision = "Southeast";
	else if (container == NWsale)
		highestdivision = "Northwest";
	else
		highestdivision = "Southwest";

	cout << "\n\t\tThe highest grossing division is the " << highestdivision << " division with a quarterly sales figure of $" << container << "." << endl;
}
