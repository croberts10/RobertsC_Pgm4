/*
* Connor Roberts, CS 2010, 10:30: - 11:20
* Program3_BarGraph, RobertsC_Pgm4.cpp, 10/19/2022
*
* Purpose: The purpose of the program is to practice debugging, using different variables and formatting output. This is done by creating input/output text files
* to create a bar graph within the console.
* 
* Input: The user will be given a menu of text files to choose from. They will enter numbers until they enter a valid number from the menu.
*
* Processing: The program processes various calculations including caluclating number of X's needed for bar graph, 3 min/max values, invalid values, etc.
*
* Output: The output includes various text outputs including but not limited to a menu, a bargraph with an x and y axis, and color-coded invalid values.
*
*/

#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<windows.h>
#include <iomanip>

using namespace std;

int main() {
	ifstream inFS; // Input file stream
	ofstream outFS; // Output file stream for extra credit
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Color variables
	const int WHITE = 7; // Constant white text
	int choice, num, invalid = 0; // Various int
	int i = 1, p = 10, j = 0; // Counter ints
	int small1 = 1000000, small2 = 1000000, small3 = 1000000; // Min ints
	int large1 = -1000000, large2 = -1000000, large3 = -1000000; // Max ints
	// Displays menu
	do {
	
		cout << "Select file to process: \n";
		cout << "1. mixed.txt \n";
		cout << "2. valid.txt \n";
		cout << "3. three.txt \n";
		cout << "4. missing.txt \n";
		cout << "Choice: ";
		cin >> choice;
		system("cls");
		
	} while (choice > 4 || choice < 1);

	// Inputs 1-4
	switch (choice) {
		// If input is 1, open mixed.txt
		case 1:
			inFS.open("mixed.txt");
			if (inFS.is_open()) {
				cout << "Bar graph for data contained in mixed.txt\n\n";
				break;
			}
		// If input is 2, open valid.txt
		case 2: 
			inFS.open("valid.txt");
			if (inFS.is_open()) {
				cout << "Bar graph for data contained in valid.txt\n\n";
				break;
			}
		// If input is 3, open valid.txt
		case 3:
			inFS.open("three.txt");
			if (inFS.is_open()) {
				cout << "Bar graph for data contained in three.txt\n\n";
				break;
			}
		// If input is 4, display error
		case 4:
			cout << "ERROR: Data file not found.";
			return 1;
	}

	while (inFS >> num) {  // Create X axis and bar graph of X's
		if (num >= 9999) {
			break;
		}
		SetConsoleTextAttribute(hConsole, WHITE); 
		cout << setfill(' ') << setw(2) << i;
		cout << " | ";
		if (num < 0) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);  // Sets background to blue if negative
			invalid += 1;
		}
		if (num > 112) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED);  // Sets background to red if number is off screen
			invalid += 1;
		}
		for (j = 1; j <= fabs(num); j++) {
			cout << 'X';
			if (j > 112) {
				break;
			}
		}

		if (num < small1) {  // Find 3 mins
			small3 = small2;
			small2 = small1;
			small1 = num;
		}
		else if (num < small2) {
			small2 = small1;
			small2 = num;
		}
		else if (num < small3) {
			small3 = num;
		}

		if (num > large1) {  // Find 3 maxs
			large3 = large2;
			large2 = large1;
			large1 = num;
		}
		else if (num > large2) {
			large3 = large2;
			large2 = large1;
			large2 = num;
		}
		else if (num > large3) {
			large3 = num;
		}
		cout << '\n';
		i++;	
	}
	for (i = 0; i <= 118; i++) {	// Create Y axis of '-' and sets max value for console screen
		cout << '-';
	}
	cout << '\n';
	cout << "     1";	// Create Y axis of number values
	for (i = 0; i <= 10; i++) {
		cout << "        " << p;
		p = p + 10;
	}
	cout << "\n\n";

	// Create smallest 3 values
	cout << "SMALLEST\n""========\n";
	cout << "The smallest value: " << small1 << '\n';
	cout << "2nd smallest value: " << small2 << '\n';
	cout << "3rd smalelst value: " << small3 << '\n';
	// Create 3 largest values
	cout << "LARGEST\n""========\n";
	cout << "The largest value: " << large1 << '\n';
	cout << "2nd largest value: " << large2 << '\n';
	cout << "3rd largest value: " << large3 << '\n';
	// Shows how many invalid numbers
	cout << "INVALID\n""========\n";
	cout << "There are " << invalid << " values in the data.\n";
	// Close file
	inFS.close();
	return 0;
}