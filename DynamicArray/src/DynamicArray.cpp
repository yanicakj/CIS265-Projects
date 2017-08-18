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

	// filling with pointer from calling function
	arraypointer = getnumbers(8);

	// display pointer
	cout << arraypointer << " ";

	return 0;
}

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
