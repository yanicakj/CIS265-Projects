//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#7
//Due by 6/26/2017

#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;

// prototype
int *getpointer(int array[], int size);

int main() {

	// random seed & variable declaration/initialization
	srand(time(NULL));
	int *mainpointer;
	int *myarray;
	int elements = 0;

	cout << "Please enter a reasonable size for number of elements in your random array : ";
	cin >> elements;

	// dynamically allocate first array
	myarray = new int[elements];

	// fills first array with random numbers
	for (int i = 0; i < elements; i++) {
		myarray[i] = rand() % 10;
	}

	// display first array
	cout << "\nOriginal array : " << endl;
	for (int i = 0; i < elements; i++) {
		cout << myarray[i] << " ";
	}

	// filling mainpointer by calling function getpointer
	mainpointer = getpointer(myarray, elements);

	// displaying returned pointer
	cout << "\n\nReturned pointer : \n"<< mainpointer;

	return 0;
}

// function to create double sized array, fill it correctly, and return pointer
int *getpointer(int array[], int size) {

	int *pointer;

	int sizedoubled = 0;

	sizedoubled = size  * 2;

	pointer = new int[sizedoubled];

	// logic to fill array according to directions
	for (int i = 0; i < sizedoubled; i++) {
		if (i < size)
			pointer[i] = array[i];
		else
			pointer[i] = 0;
	}

	// displaying expanded array
	cout << "\n\nExpanded array : " << endl;
	for (int i = 0; i < sizedoubled; i++)
		cout << pointer[i] << " ";

	return pointer;
}
