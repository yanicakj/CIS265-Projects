//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#6
//Due by 6/26/2017

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// prototype
int *getnumbers(int size);

int main() {

	// creating pointer in main
	int *arraypointer;
	int elements = 0;

	cout << "\n\t\tHow many elements should be in the dynamically allocated array? Enter an integer : ";
	cin >> elements;

	// filling with pointer from calling function
	arraypointer = getnumbers(elements);

	// display pointer
	cout << "\n\t\tPointer : " << arraypointer << endl;

	return 0;
}

// function to return array pointer
int *getnumbers(int size) {

	// creating local container
	int *pointer;

	// input validation
	if (size <= 0)
		return NULL;

	// dynamically allocating new array
	pointer = new int[size];

	// filling new array with integers
	for (int i = 0; i < size; i++) {
		pointer[i] = i * i;
	}

	// return pointer to  main
	return pointer;
}
