//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#8
//Due by 7/10/2017

/* Write a function that returns an integer and accepts a pointer to a C-string as an argument.
The function should count the number of characters in the string and return that number.
Demonstrate the function in a simple program that asks the user to input a string,
passes it to the function, and then displays the function’s return value.*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

// prototype
int countcharacters(char *pointer);

int main() {

	// declaration & initialization
	const int size = 51;
	char newstring[size];

	// grabbing input as array of chars
	cout << "Enter a string up to 50 characters : ";
	cin.getline(newstring, size);

	// displaying number of characters by calling countcharacters function
	cout << "Number of characters in string : " << countcharacters(newstring) << endl;

	return 0;
}

// function accepting pointer as argument and returning number of characters in string
int countcharacters(char *pointer) {

	int count = 0;

	// looping through string/array of chars
	while (*pointer != '\0') {
		count++;
		pointer++;
	}

	return count;
}
