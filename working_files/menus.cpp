/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 3
Lab:			A: 0830 - 1030
Description:	Handles the display of menus and actions of the different menus of the program
Last Modified:	23rd September 2013

******/

#include "header.h"
#include "menus.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<cstdlib>

using namespace std;

// function displays the main menu text and available options
void displayMainMenu(){
	
	cout << endl;
	cout << '\t' << '\t' << "/*********************** MAIN MENU ***********************/" << endl;
	cout << endl;
	cout << "     I - Import the data from a data file. Prompt the user for the name of a file for import." << endl;
	cout << "     N - Display the number of molecules imported" << endl;
	cout << "     R - Generate a report to the display. A report contains the following information:" << endl;
	cout << '\t' << "1. total number of molecules" << endl;
	cout << '\t' << "2. number of lonely molecules" << endl;
	cout << '\t' << "3. average speed of the lonely molecules" << endl;
	cout << '\t' << "4. average energy of the lonely molecules" << endl;
	cout << "     q - quit the program" << endl;
	cout << endl;
	cout << "     Please enter your selection: ";
	
	return;
}

// retrieves the user's selection based on the options available in the main menu

bool getUserInput(mptr & head, int & molecules){
	
	char userInput;
	char validVals[4] = { 'I','N','R','q' };
	
	// while the user has not selected the (q)uit option
	while(userInput != 'q'){
		
		displayMainMenu();
		
		// run a function to handle the input and validation of the selection requested from the user
		userInput = validateInput(validVals, 4);
		cin.clear();
		cin.ignore(1000,'\n');
		
		// enter the appropriate statement based on the user's choice
		switch(userInput){
			
			case 'I':
				// function adds a list of molecules to a list and increases the count
				addToList(head, molecules);	
				cout << endl;
				cout << "---------- IMPORT COMPLETE!!!! ----------" << endl;
				cout << endl;
			break;
			
			case 'N':
				// outputs the number of molecules if there is an existing list
				if(molecules == 0){
					cout << endl;
					cout << "---------- There are no imported molecule records. Please upload some first!! ----------" << endl;
					cout << endl;
				}else {
					displayMCount(head, molecules);
				}
			break;
			
			case 'R':
				//outputs a report based on the number of lonely molecules provided that there are any
				if(molecules == 0){
					cout << endl;
					cout << "---------- There are no imported molecule records. Please upload some first!! ----------" << endl;
					cout << endl;
				}else {
					generateReport(head, molecules);
				}
			break;
			
			case 'q':
				// quits the program and deletes the current list
				cout << endl;
				cout << '\t' << '\t' << "/*********************** You Quit the program! ***********************/" << endl;
				cout << endl;
				deleteList(head);
			break;
		}
	}
	return true;
}

// displays the number of imported molecules in the current list
void displayMCount(mptr& head, int molecules){
	
	int count = 1;
	bool outVals = false;
	
	cout << endl;
	cout << "/******************** THE TOTAL NUMBER OF MOLECULES IMPORTED WAS: " << molecules << " ********************/" << endl;
	cout << endl;
	
	mptr temp = new molecule;
	temp = head;
	
	// outputs the data of all nodes in the list
	
	while(outVals == false){
		if(temp->next == NULL){
			outVals = true;
		}
		cout << "--------- MOLECULE #: " << count << " ---------" << endl;
		cout << endl;
		cout << "Position: " << temp->position << " | ";
		cout << "Speed: " << temp->speed << " | ";
		cout << "Energy: " << temp->energy;
		cout << endl;
		cout << endl;
		temp = temp->next;
		count = count + 1;
	}
	
	return;
}

// function outputs the report of value marked as lonely molecules
void outReport(float spdAv, float egyAv, int aCount, int molecules){
	
	// calculates the averages of found for the speed and energy values
	float spdFin = spdAv / aCount;
	float egyFin = egyAv / aCount;
	
	cout << endl;
	cout << "/******************** MOLECULE REPORT ********************/" << endl;
	cout << endl;
	cout << "1. Total Number of molecules: " << molecules << endl;
	
	// if there were lonely molecules, output the values
	if(aCount >0){
		cout << "2. Number of Lonely Molecules: " << aCount << endl;
		cout << "3. Average Speed of lonely Molecules: " << spdFin << endl;
		cout << "4. Average Energy of lonely Molecules: " << egyFin << endl;
		cout << endl;
	// otherwise output a message saying that there were no instances of lonely molecules in the
	// current node list
	}else {
		cout << "There weren't any lonely molecules in the sample you uploaded!" << endl;
	}
	
	return;
}
