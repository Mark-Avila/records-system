// records-system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Records.h"

int main()
{
	//Debugging
	Records list;

	list.insertRecords("Mark", 85.5, 85.5, 85.5);
	list.insertRecords("Dani", 85.5, 85.5, 85.5);
	list.insertRecords("Elie", 85.5, 85.5, 85.5);

	list.printRecords();

	return 0;
}