//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#10
//Due by 7/17/2017

#include <iostream>
#include <cctype>
#include <cstring>


/*Write a program that uses a structure named MovieData to store the following information about a movie:
Title Director Year Released Running Time (in minutes) The program should create two MovieData variables,
store values in their members, and pass each one, in turn, to a function that displays the information about
the movie in a clearly formatted manner.*/

using namespace std;


struct MovieData {
	string title;
	string director;
	int yearreleased;
	int runningtime;
};

void collector(const MovieData &object);
void display(const MovieData &object);

int counter = 1;

int main() {

	MovieData var1;
	MovieData var2;

	collector(var1);
	collector(var2);
	display(var1);
	display(var2);

	return 0;
}

void collector(MovieData &object) {

	string title;
	string director;
	int yearreleased;
	int runningtime;

	cout << "Enter information about Movie " << counter << "." << endl;
	cout << "Title : ";
	getline(cin, title);
	cout << "\nDirector : ";
	getline(cin, director);
	cout << "\nYear Released : ";
	cin >> yearreleased;
	cout << "\nRunning time in minutes : ";
	cin >> runningtime;

	object.title = title;
	object.director = director;
	object.yearreleased = yearreleased;
	object.runningtime = runningtime;

	counter++;

}

void display(MovieData &object) {

	cout << "*Clearly formatted manner*" << endl;
	cout << "Movie Title : " << object.title << endl;
	cout << "Director : " << object.director << endl;
	cout << "Year Released : " << object.yearreleased << endl;
	cout << "Running Time : " << object.runningtime << " min" << endl;

}
