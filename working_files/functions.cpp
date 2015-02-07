/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 3
Lab:			A: 0830 - 1030
Description:	Functions handle the importing of data, name of file importing, and list creation and deletion
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

// function receives the file name to import and tests if its valid or not
// repeats input until a valid file is found
void addToList(mptr & head, int & molecules){
	
	char fileName[21] = { '\0' };
	bool validF = false;
	
	char ext[5] = { ".txt" };
	bool getFileName = false;
	
	cout << "Please enter a file to import your data from: ";
	while(getFileName == false){
	
		// retrive the file name to be imported
		cin.getline(fileName, 20, '\n');
		
		// function returns a boolean value given the name of a file to open
		// is of the correct extension
		getFileName = fileNameCheck(fileName, strlen(fileName), ext, strlen(ext));
		
		//function then returns boolean testing if file actually exists
		validF = findExist(fileName);
		
		// if the incorrect file format or the file does not exist 
		// then the user is prompted again for another name
		if(getFileName == false || validF == false){
			cout << "Please enter a valid file name: ";
			cin.clear();
			validF = false;
			getFileName = false;
		}
	}
	
	// function then calls the function to open the file
	openFileImport(fileName, head, molecules);

	return;
}

// function checks whether the extension of the file name is correct
// and returns a boolean depending this
bool fileNameCheck(char userName[], int length, char check[], int vldLen){

	int countMatch = 0;
	
	for(int i = 0; i < length; i++){
		for(int k = 0; k < vldLen; k++){
			if(userName[i] == check[k]){
				countMatch = countMatch + 1;
				k = vldLen + 1;
			}
		}
		
	}
	
	if(countMatch == vldLen){
		return true;
	}else {
		return false;
	}
}

//function checks whether the correct choice has been entered
// and compares it to a selection of valid values
// otherwise returns an error message and repeats input
char validateInput(char validVals[], int vldLen){
	
	bool invalid = false;
	char choice;
	
	while(invalid == false){
		cin >> choice;
		
		for(int i = 0; i <vldLen; i++){
			if(choice == validVals[i]){
				invalid = true;
			}
		}
		if(invalid == false){
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "     " <<  "Please enter a valid value: ";
		}
	}
	
	return choice;
}

// function opens the file given the correct name that has been
// entered and populates a list via the read in of the values in the file
void openFileImport(char fileName[], mptr & head, int& molecules){
	
	ifstream file;
	char line[11];
	int counter = 0;
	bool hold = true;
	float posVal = 0;
	float speedVal = 0;
	int energyVal = 0;
	
	file.open(fileName);
	
	while(!file.eof()){
		file.getline(line, 10,'\n');
		
		if(strcmp(line, "#") != 0){
		
			// switch statement handles the storing
			// of each value in each node of the list
			switch(counter){
				case 0: {
					posVal = atof(line);
					hold = true;
				}
				break;
		
				case 1: {
					speedVal = atof(line);
					}
				break;
		
				case 2:
					energyVal = atof(line);
					
					// function adds the value to the node 
					// of a new or existing list
					push(head, posVal, speedVal, energyVal);
					
					hold = false;
					// counts the number of molecules
					molecules = molecules + 1;
					
					// resets the position, energy and speed values
					// to store for the next value
					posVal = 0;
					speedVal = 0;
					counter = 0;
					
				break;
				
			}
			// boolean increments the count
			// to control the cases of the switch statement
			if(hold){
				counter = counter + 1;	
			}
		}
	}
	
	
	return;
}

// function adds a new node to the existing or creates a new list
// receives the list pointer and the values to add to the new node of the list
void push(mptr & head, float posVal, float speedVal, float energyVal){
	
	// creates a new temporary node
	mptr temp = new molecule;
	temp->position = posVal;
	temp->speed = speedVal;
	temp->energy = energyVal;
	temp->next = NULL;

	// if there are no nodes, make the existing node the new one
	if(head == NULL){
		head = temp;
		
	}else {
		// create a copy of the list
		mptr cur = head;
		
		// move to the end of the list
		while(cur->next != NULL){
			cur = cur->next;
		}
		// set the pointer of the last node to the new one
		cur->next = temp;
		// set the value of the new node
		temp = head;
	}
	
	return;
}

// function finds whether a file name exists or not
bool findExist(char fileName[]){

	ifstream check;
	
	check.open(fileName);
	if(check.good()){
		check.close();
		return true;
	}
	else {
		return false;
	}
}

// function generates the report to display to the user based
// on the location of lonely molecules given the current list
void generateReport(mptr & head, int & molecules){
	
	// creates a main version of the list to 
    mptr outerTemp = head, innerTemp = head;
    float spdAv = 0.0;
    float egyAv = 0.0;
    int aCount = 0, count = 0;
    bool loner = false, flag = false;
    bool outVals = false, outerLoop = false, innerLoop = false, ignore = true;
    int innerCount = 0, outerCount = 0;
    
    // while we havent gone through all of the nodes in the list
	while(outerLoop == false){
		// boolean controls the iteration through the list tree
		if(outerTemp->next == NULL){
			outerLoop = true;
		}
			// set the inner looping of nodes in the list back to the start
			innerTemp = head;
			
			// while we havent gone through all nodes of the list
			while(innerLoop == false){
					
					// control the value keeping the looping of list nodes
					if(innerTemp->next == NULL){
						innerLoop = true;
					}
					
					// if the current position value of the node has another equal to it, dont compare it to anything
					if(ignore){
						// if the value is not equal to the current inner node iteration
						if(innerTemp->position != outerTemp->position){
							
							// if the current value is not within -100 or + 100 of the current position value
							// if it is, set a boolean indicating to ignore the current value
							if(innerTemp->position > outerTemp->position - 100 && innerTemp->position < outerTemp->position +100){
								loner = false;
								ignore= false;
							}else {
								// otherwise set a true boolean so that this value should be included
								loner = true;
							}
						}
						// if the values are equal
						if(innerTemp->position == outerTemp->position){
						
							// check to see that they are not the same node
							if(outerCount != innerCount){
								loner = false;
								ignore = false;
							}
						}
					}
				
				// count the current node that is being iterated through
				innerCount = innerCount + 1;
				
				// move to the next node in the list
				innerTemp = innerTemp->next;
			}
	
		// count the current node that is being iterated through in the outer loop
		outerCount = outerCount + 1;
		// reset the count of the inner iteration so for the next outer node that is to be compared
		innerCount = 0;
		
		// reset the ignore boolean to be true so that the next value will be compared unless indicated otherwise
		ignore = true;
		
		// if the loner boolean is true then we have a loner molecule and as such we need to increase the count and
		// add the current speed and energy values of this molecule as well as reset the lonely boolean indicator
		if(loner){
			aCount = aCount + 1;
			spdAv = spdAv + outerTemp->speed;
			egyAv = egyAv + outerTemp->energy;
			loner = false;
		}
		//reset the inner boolean control value back to false so that it may iterate for the next node of the list
		// controlled by the outer loop
		innerLoop = false;
		
		// move to the next node in the tree to be compared
		outerTemp = outerTemp->next;
	}
	
	outReport(spdAv, egyAv, aCount, molecules);
	
	return;
}

// function deletes the members of a list
void deleteList(mptr & head){
	
	// set a current pointer value to the current head of the list
	mptr temp = head;
	
	// whilst you havent reached the end of the list
	while(head->next != NULL){
		// set the current head of the list to the temporary value
		temp = head;
		// set the current head value to the next item in the list
		head = head->next;
		
		// delete the starting node at the beginning of the tree
		delete temp;
	}
	
	return;
}

