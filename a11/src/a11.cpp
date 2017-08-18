//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#11
//Due by 7/17/2017

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

/*A student has established the following monthly budget:
Housing 500.00
Utilities 150.00
Household Expenses 65.00
Transportation 50.00
Food 250.00
Medical 30.00
Insurance 100.00
Entertainment 150.00
Clothing 75.00
Miscellaneous 50.00
Write a program that has a MonthlyBudget structure designed to hold each of these expense categories.
The program should pass the structure to a function that asks the user to enter the amounts spent in
each budget category during a month. The program should then pass the structure to a function that
displays a report indicating the amount over or under in each category, as well as the amount over or
under for the entire monthly budget.
*/

// monthly budget struct
struct MonthlyBudget {
	double housing;
	double utilities;
	double householdexpenses;
	double transportation;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothing;
	double miscellaneous;
};

// prototypes
void collector(MonthlyBudget &budget);
void evaluator(MonthlyBudget &budget);

int main() {

	// making MonthlyBudget member
	MonthlyBudget budget;

	// calling function to collect values
	collector(budget);
	// calling function to evaluate user's fiscal responsibility
	evaluator(budget);

	return 0;
}

// function collects values for a struct passed as argument
void collector(MonthlyBudget &budget) {

	// prompting and storing 10 values for struct
	cout << "\n\t\tPlease enter money spent on the following:" << endl << endl;
	cout << "\t\t\tHousing : ";
	cin >> budget.housing;
	cout << "\t\t\tUtilities : ";
	cin >> budget.utilities;
	cout << "\t\t\tHousehold Expenses : ";
	cin >> budget.householdexpenses;
	cout << "\t\t\tTransportation : ";
	cin >> budget.transportation;
	cout << "\t\t\tFood : ";
	cin >> budget.food;
	cout << "\t\t\tMedical : ";
	cin >> budget.medical;
	cout << "\t\t\tInsurance : ";
	cin >> budget.insurance;
	cout << "\t\t\tEntertainment : ";
	cin >> budget.entertainment;
	cout << "\t\t\tClothing : ";
	cin >> budget.clothing;
	cout << "\t\t\tMiscellaneous : ";
	cin >> budget.miscellaneous;

}

// function determines if user is over/under/or right-on budget for 10 areas included, accepts struct as argument
void evaluator(MonthlyBudget &budget) {

	// declaring and initializing needed arrays
	double goals[10] = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};
	double actual[10] = {budget.housing, budget.utilities, budget.householdexpenses, budget.transportation, budget.food, budget.medical, budget.insurance, budget.entertainment, budget.clothing, budget.miscellaneous};
	string topics[10] = {"Housing", "Utlities", "Household Expenses", "Transportation", "Food", "Medical", "Insurance", "Entertainment", "Clothing", "Miscellaneous" };

	cout << "\n\t\tSo this is how you did.." << endl << endl;

	// looping for budget evaluation, compares actual to goal set by user
	for (int i = 0; i < 10; i++) {
		if (actual[i] > goals[i])
			cout << "\t\t\t" << topics[i] << " spending is $" << actual[i] - goals[i] << " over-budget." << endl;
		else if (actual[i] < goals[i])
			cout << "\t\t\t" << topics[i] << " spending is $" << goals[i] - actual[i] << " under-budget." << endl;
		else
			cout << "\t\t\t" << topics[i] << " spending is right-on budget." << endl;
	}

}
