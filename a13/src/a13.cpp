//courseID:CIS265
//name: Jacob Yanicak
//Prof. Wang
//Assignment#13
//Due by 8/7/2017

#include <iostream>
#include <string>


using namespace std;

// global string
string montharray[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// class named Date with members
class Date {
  int month;
  int day;
  int year;
  public:
    void setvalues();
    void display1();
    void display2();
    void display3();
};

int main()
{

	// creating Date object in main
    Date dateobject;

    // calling functions to get and display Date members
    dateobject.setvalues();
    dateobject.display1();
    dateobject.display2();
    dateobject.display3();

    return 0;
}

// function prompts for values and stores in Date members
void Date::setvalues() {

	// looping for all three below for input validation
    do {
        cout << "\t\tHello, please enter the month in XX format : ";
        cin >> month;
        if (month < 1|| month > 12)
            cout << "\t\t\tPlease enter valid information." << endl;
    } while (month < 1 || month > 12);

    do {
        cout << "\t\tPlease enter the day in XX format : ";
        cin >> day;
        if (day < 1 || day > 31)
            cout << "\t\t\tPlease enter valid information." << endl;
    } while (day < 1 || day > 31);

    do {
        cout << "\t\tPlease enter the year in XXXX format : ";
        cin >> year;
        if (year < 0)
            cout << "\t\t\tPlease enter a non B.C. year." << endl;
    } while (year < 0);

    // displaying user inputs
    cout << "\n\t\tValues accepted : " << endl;

    cout << "\t\t\tMonth : " << month << endl;
    cout << "\t\t\tDay : " << day << endl;
    cout << "\t\t\tYear : " << year << endl;

}

// function for 1st type of display
void Date::display1() {

    cout << "\n\t\tDisplay 1 - XX/XX/XXXX : \n" << endl;
    cout << "\t\t\t" << month << "/" << day << "/" << year << endl;

}

// function for 2nd type of display
void Date::display2() {

    cout << "\n\t\tDisplay 2 - <Month Name> XX, XXXX : \n" << endl;
    cout << "\t\t\t" << montharray[month - 1] << " " << day << ", " << year << endl;
}

// function for 3rd type of display
void Date::display3() {

    cout << "\n\t\tDisplay 3 - XX <Month Name> XXXX : \n" << endl;
    cout << "\t\t\t" << day << " " << montharray[month - 1] << " " << year << endl;

}
