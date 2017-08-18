//courseID:CIS165-001
//name: Jacob Yanicak
//Prof. Wang
//Assignment#5
//Due by 6/19/2017

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

/* 16. 2D Array Operations Write a program that creates a two-dimensional array initialized with test data.
Use any data type you wish. The program should have the following functions:
¥ getTotal. This function should accept a two-dimensional array as its argument and return the total of all the values in the array.
¥ getAverage. This function should accept a two-dimensional array as its argument and return the average of all the values in the array.
¥ getRowTotal. This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a row in the array. The function should return the total of the values in the specified row.
¥ getColumnTotal. This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a column in the array. The function should return the total of the values in the specified column.
¥ getHighestInRow. This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a row in the array. The function should return the highest value in the specified row of the array.
¥ getLowestInRow. This function should accept a two-dimensional array as its first argument and an integer as its second argument.
The second argument should be the subscript of a row in the array. The function should return the lowest value in the specified row of the array.
Demonstrate each of the functions in this program.
*/

// prototypes
void fillarray(int array[3][3]);
void display(int array[3][3]) ;
int getTotal(int array[3][3]);
double getAverage(int array[3][3]);
int getRowTotal(int array[3][3], int row);
int getColumnTotal(int array[3][3], int col);
int getHighestInRow(int array[3][3], int row);
int getLowestInRow(int array[3][3], int row) ;

int main() {

	// random seed for array filler
	srand(time(NULL));
	int myarray[3][3];
	int total = 0;
	double average = 0.0;
	int rowtotal = 0;
	int coltotal = 0;
	int row = 0;
	int row2 = 0;
	int row3 = 0;
	int col = 0;
	int rowhigh = 0;
	int rowlow = 0;

	// calling filler
	fillarray(myarray);

	// displaying array
	display(myarray);

	// calling function to get total
	total = getTotal(myarray);
	cout << "\t\tThe total is : " << total << endl;

	// calling function to get average
	average = getAverage(myarray);
	cout << "\t\tThe average is : " << average << endl;

	// prompting to choose a row to add
	cout << "\t\tEnter a row (1, 2, or 3) to find respective total : ";
	cin >> row;

	// input validation
	while (row != 1 && row != 2 && row != 3) {
		cout << "\t\tPlease enter a valid row number (1, 2, or 3) : ";
		cin >> row;
	}

	// calling function to get row total
	rowtotal = getRowTotal(myarray, row);
	cout << "\t\tThe total of row " << row << " is : " << rowtotal << endl;

	// prompting to choose a column to add
	cout << "\t\tEnter a column (1, 2, or 3) to find respective total : ";
	cin >> col;

	// input validation
	while (col != 1 && col != 2 && col != 3) {
		cout << "\t\tPlease enter a valid column number (1, 2, or 3) : ";
		cin >> col;
	}

	// calling function to get column total
	coltotal = getColumnTotal(myarray, col);
	cout << "\t\tThe total of column " << col << " is : " << coltotal << endl;

	// prompting to select a row to find highest
	cout << "\t\tEnter a row (1, 2, or 3) to find highest member : ";
	cin >> row2;

	// input validation
	while (row2 != 1 && row2 != 2 && row2 != 3) {
		cout << "\t\tPlease enter a valid row number (1, 2, or 3) : ";
		cin >> row2;
	}

	// calling function to get highest in row
	rowhigh = getHighestInRow(myarray, row2);
	cout << "\t\tThe highest in row " << row2 << " is : " << rowhigh << endl;

	// prompting to select a row to find lowest
	cout << "\t\tEnter a row (1, 2, or 3) to find lowest member : ";
	cin >> row3;

	// input validation
	while (row3 != 1 && row3 != 2 && row3 != 3) {
		cout << "\t\tPlease enter a valid row number (1, 2, or 3) : ";
		cin >> row3;
	}

	// calling function to get highest in row
	rowlow = getLowestInRow(myarray, row3);
	cout << "\t\tThe lowest in row " << row3 << " is : " << rowlow << endl;
}

// filler function using random numbers
void fillarray(int array[3][3]) {

	for (int i = 0; i <=2; i++) {
		for (int j = 0; j <= 2; j++)
			array[i][j] = rand() % 10;
	}
}

// display function
void display(int array[3][3]) {

	cout << "\tColumn Numbers :" << endl;
	cout << "\t1\t2\t3" << endl;
	cout << endl;
	cout << "\tYour array :\t\tRow Numbers : ";
	for (int i = 0; i <=2; i++) {
		cout << endl;
		for (int j = 0; j <= 2; j++)
			cout << "\t" << array[i][j] << " ";
		cout << "\t\t" << i + 1 << endl;
	}

	cout << endl;
}

// function to get total of whole array
int getTotal(int array[3][3]) {

	int total = 0;

	for (int i = 0; i <=2; i++) {
		for (int j = 0; j <= 2; j++)
			total += array[i][j];
	}

	return total;
}

// function to get average of whole array
double getAverage(int array[3][3]) {

	double average = 0.0;
	int counter = 0;
	float total = 0;

	for (int i = 0; i <=2; i++) {
		for (int j = 0; j <= 2; j++) {
			total += array[i][j];
			counter++;
		}
	}

	average = total / counter;

	return average;
}

// function to get a row's total
int getRowTotal(int array[3][3], int row) {

	int rowtotal = 0;

	row -= 1;

	for (int j = 0; j <= 2; j++)
		rowtotal += array[row][j];

	return rowtotal;
}

// function to get a column's total
int getColumnTotal(int array[3][3], int col) {

	int coltotal = 0;

	col -= 1;

	for (int j = 0; j <= 2; j++)
		coltotal += array[j][col];

	return coltotal;
}

// function to get a highest in row
int getHighestInRow(int array[3][3], int row) {

	int highest = 0;

	row -= 1;

	for (int i = 0; i <= 2; i++) {
		if (highest < array[row][i])
			highest = array[row][i];
	}

	return highest;
}

// function to get a lowest in row
int getLowestInRow(int array[3][3], int row) {

	int lowest = 20;

	row -= 1;

	for (int i = 0; i <= 2; i++) {
		if (lowest > array[row][i])
			lowest = array[row][i];
	}

	return lowest;
}
