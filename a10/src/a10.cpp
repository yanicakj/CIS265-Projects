//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#10
//Due by 7/17/2017

#include <iostream>
#include <cctype>
#include <cstring>
#include <string>


/*Write a program that uses a structure named MovieData to store the following information about a movie:
Title Director Year Released Running Time (in minutes) The program should create two MovieData variables,
store values in their members, and pass each one, in turn, to a function that displays the information about
the movie in a clearly formatted manner.*/

using namespace std;

// MovieData struct
struct MovieData {
	string title;
	string director;
	int yearreleased;
	int runningtime;
};

// prototypes
void collector(MovieData &object);
void display(MovieData &object);

// global variable for output purposes
int counter = 1;

int main() {

	// creating members
	MovieData var1;
	MovieData var2;

	// calling functions to fill members
	collector(var1);
	collector(var2);

	counter = 1;

	// calling functions to display members
	display(var1);
	display(var2);

	return 0;
}

// function fills struct, accepts struct as argument
void collector(MovieData &object) {

	// prompt and store for 4 values in struct
	cout << "\n\t\tPlease enter information about Movie " << counter << "." << endl;
	cout << "\t\t\tTitle : ";
	cin.ignore();
	getline(cin, object.title);
	cout << "\t\t\tDirector : ";
	getline(cin, object.director);
	cout << "\t\t\tYear Released : ";
	cin >> object.yearreleased;
	cout << "\t\t\tRunning time in minutes : ";
	cin >> object.runningtime;

	// increment global
	counter++;

}

// function displays values in struct, accepts struct as argument
void display(MovieData &object) {

	// display 4 values in each struct
	cout << "\n\t\tMovie data on file for Movie " << counter << " : " << endl;
	cout << "\t\t\tMovie Title : " << object.title << endl;
	cout << "\t\t\tDirector : " << object.director << endl;
	cout << "\t\t\tYear Released : " << object.yearreleased << endl;
	cout << "\t\t\tRunning Time : " << object.runningtime << " min" << endl;

	// increment global
	counter++;

}
