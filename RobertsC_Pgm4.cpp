/*
* Connor Roberts, CS 2010, 10:30: - 11:20
* Program3_BarGraph, RobertsC_Pgm4.cpp, 10/19/2022
*
* Purpose: 
*
* Input: 
*
* Processing: 
*
* Output: 
*
*/

#include <iostream>
#include <string>
#include <fstream>
#include<stdlib.h>
#include<windows.h>
#include<vector>


using namespace std;

int main() {
	ifstream inFS; // Input file steam

	int choice;
	// Displays menu
	do {
	
		cout << "Select file to process:" << endl;
		cout << "1. mixed.txt" << endl;
		cout << "2. valid.txt" << endl;
		cout << "3. three.txt" << endl;
		cout << "4. missing.txt" << endl;
		cout << endl;
		cout << "Choice: ";
		cin >> choice;
		system("cls");
		

		} while (choice > 4 || choice < 1);

		// Inputs 1-4
		while (choice < 5 && choice > 0) {

			// If input is 1
			if (choice == 1) {
				inFS.open("mixed.txt");
				break;
			}

			// If input is 2
			if (choice == 2) {
				inFS.open("valid.txt");
				break;
			}
			// If input is 3
			if (choice == 3) {
				inFS.open("three.txt");
				break;
			}

			// If input is 4
			if (choice == 4) {
				cout << "ERROR: Data file not found" << endl;
				break;
			}
		}


	return 0;
}