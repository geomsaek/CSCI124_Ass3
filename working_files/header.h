/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 3
Lab:			A: 0830 - 1030
Description:	Contains the prototypes of the functions used in the functions.cpp file
Last Modified:	23rd September 2013

******/

#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<cstdlib>

using namespace std;

struct molecule;
typedef molecule*mptr;

struct molecule{
	float position;
	float speed;
	float energy;
	mptr next;
};

// function receives the file name to import and tests if its valid or not
// repeats input until a valid file is found
void addToList(mptr &, int &);

// function checks whether the extension of the file name is correct
// and returns a boolean depending this
bool fileNameCheck(char [], int, char [], int);

//function checks whether the correct choice has been entered
// and compares it to a selection of valid values
// otherwise returns an error message and repeats input
char validateInput(char [], int);

// function opens the file given the correct name that has been
// entered and populates a list via the read in of the values in the file
void openFileImport(char [], mptr &, int&);

// function adds a new node to the existing or creates a new list
// receives the list pointer and the values to add to the new node of the list
void push(mptr &, float, float, float);

// function finds whether a file name exists or not
bool findExist(char []);

// function generates the report to display to the user based
// on the location of lonely molecules given the current list
void generateReport(mptr &, int &);

// function deletes the members of a list
void deleteList(mptr &);
