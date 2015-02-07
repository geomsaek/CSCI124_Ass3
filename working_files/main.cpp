/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 3
Lab:			A: 0830 - 1030
Description:	Contains the main calling function of the program as well as the declaration of the main pointer file
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

int main(){
	
	// creates a new instance of the molecule structure
	molecule * userList = NULL;
	// holds the total number of molecules
	int totalMolecules = 0;
	
	// controls the while loop
	bool userQuit = false;
	
	// controls the overall function of the program
	// displaying the main menu
	while(userQuit == false){
		// return value determines whether then main menu is to
		// stop of keep going
		// function passes the first instance of the structure to be used in the list
		userQuit = getUserInput(userList, totalMolecules);
	}
	
	
	
	return 0;
}
