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
using namespace std;

int main() {
	ifstream inFS; // Input file steam

	int choice;
	do {
		cout << "Select file to process:" << endl;
		cout << "1. mixed.txt" << endl;
		cout << "2. valid.txt" << endl;
		cout << "3. three.txt" << endl;
		cout << "4. missing.txt" << endl;
		cout << endl;
		cout << "Choice: ";
		cin >> choice;

		// If input is 1, read mixed.txt
		
		// If input is 2, read valid.txt

		// If input is 3, read three.txt
		system("cls");

		} while (choice != 4);

	// 
	if (choice == 4) {
		cout << "ERROR: Data file not found";
	}


	return 0;
}