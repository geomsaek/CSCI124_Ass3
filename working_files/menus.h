/*****

Name:			Matthew Saliba
Subject:		CSCI124
Student Num:	3284165
Title:			Assignment 3
Lab:			A: 0830 - 1030
Description:	Contains the prototypes of the functions contained within the menus.cpp file
Last Modified:	23rd September 2013

******/

#include<iostream>
#include<fstream>
#include<cctype>
#include<cstring>
#include<cstdlib>

using namespace std;

// function displays the main menu text and available options
void displayMainMenu();

// returns a boolean value based on the input from the selection of values from the main menu
bool getUserInput(mptr &, int &);

// displays the number of imported molecules in the list
void displayMCount(mptr &, int);

// outputs the report values of the imported molecules
void outReport(float, float, int, int);
