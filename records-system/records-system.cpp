// records-system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Records.h"
#include "Utilities.h"

int mainMenu();


int main()
{
	//Debugging
	/*list.insertRecords("Mark", 85.5, 85.5, 85.5);
	list.insertRecords("Dani", 85.5, 85.5, 85.5);
	list.insertRecords("Elie", 85.5, 85.5, 85.5);
	list.printRecords();*/

	Records list;
	Utilities utils;

	std::string name, temp;
	float g1, g2, g3;
	bool running = true;

	while (running)
	{
		utils.clearScreen();

		switch (mainMenu())
		{
		case 1:
			utils.clearScreen();

			utils.printHeader("NEW RECORD", 50);

			std::cout << "Enter new name: ";
			std::cin.ignore();
			std::getline(std::cin, name);

			std::cout << "\nEnter score 1: "; 
			if (utils.inputFloat(&g1) == false)
			{
				std::cout << "\nInvalid input! Operation aborted";
				utils.pauseScreen(&temp);
				break;
			}

			std::cout << "\nEnter score 2: ";
			if (utils.inputFloat(&g2) == false)
			{
				std::cout << "\nInvalid input! Operation aborted";
				utils.pauseScreen(&temp);
				break;
			}

			std::cout << "\nEnter score 3: ";
			if (utils.inputFloat(&g3) == false)
			{
				std::cout << "\nInvalid input! Operation aborted";
				utils.pauseScreen(&temp);
				break;
			}

			list.insertRecords(name, g1, g2, g3);

			std::cout << "\n\nSuccessfully added student to records!\n";

			utils.pauseScreen(&temp);
			break;

		case 3:
			list.printRecords();
			utils.pauseScreen(&temp);
			break;

		case 7:
			running = false;
			break;

		default:
			break;
		}
	}

	return 0;
}

int mainMenu()
{
	Utilities utils;

	utils.printLine(50);
	std::cout << "\nStudent Records System V 0.0.1\n\n";
	utils.printLine(50);
	std::cout << "Current Account: Mark\n";
	utils.printLine(50);
	std::cout << "[1]. Add new record\n";
	std::cout << "[2]. Display record\n";
	std::cout << "[3]. Update record\n";
	std::cout << "[4]. Delete record\n";
	std::cout << "[5]. Display all record\n";
	std::cout << "[6]. Settings record\n";
	std::cout << "[7]. Exit\n";
	utils.printLine(50);
	std::cout << "Enter input here: ";

	int choice;
	std::cin >> choice;

	return choice;
}