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
#include <iomanip>

using namespace std;

int main() {
	ifstream inFS; // Input file stream

	int choice;
	int num;
	int i = 1;
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
				break;
			}
		// If input is 2, open valid.txt
		case 2: 
			inFS.open("valid.txt");
			if (inFS.is_open()) {
				break;
			}
	
		// If input is 3, open valid.txt
		case 3:
			inFS.open("three.txt");
			if (inFS.is_open()) {
				break;
			}

		// If input is 4, display error
		case 4:
			cout << "ERROR: Data file not found.";
			break;
	}


	// 
	while (inFS >> num) {
		if (num >= 9999) {
			break;
		}
		cout << i << setw(4) << " | " << num << '\n';
		i++;
	}

	inFS.close();


	return 0;
}