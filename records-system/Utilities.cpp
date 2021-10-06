#include <Random>
#include <iostream>
#include <string>
#include <typeinfo>
#include "Utilities.h"

void Utilities::printLine(int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "-";
	}

	std::cout << "\n";
}

void Utilities::printHeader(std::string title, int length)
{
	printLine(length);
	std::cout << "\n" << title << "\n\n";
	printLine(length);
}

void Utilities::clearScreen()
{
	//This is a string of special characters that translate to clear the screen command.
	std::cout << "\033[2J\033[1;1H";

	//Q: Why not just use 'system("cls")?'
	//A: Because using system methods are bad practice due to it being dependent on Windows OS
}

bool Utilities::inputFloat(float* number)
{
	if (std::cin >> *number)
	{
		return true;
	}
	else
	{
		std::cin.clear(); // reset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
}

bool Utilities::inputInt(int* number)
{
	if (std::cin >> *number)
	{
		return true;
	}
	else
	{
		std::cin.clear(); // reset failbit
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
}

void Utilities::pauseScreen()
{
	std::string temp;
	std::cout << "\nPress any key to continue: ";
	std::cin.ignore();
	std::getline(std::cin, temp);
}
