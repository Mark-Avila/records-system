#pragma once

#include <string>

class Utilities
{
public:
	/// <summary>
	/// Print a line in the terminal
	/// </summary>
	/// <param name="length"> - length of line output</param>
	void printLine(int length);

	/// <summary>
	/// Prints main header message into the console
	/// </summary>
	/// <param name="title"> - Header title/message </param>
	/// <param name="length"> - Line length</param>
	void printHeader(std::string title, int length);

	/// <summary>
	/// Clears the console screen
	/// </summary>
	void clearScreen();

	/// <summary>
	/// Checks if user input is of type float
	/// </summary>
	/// <param name="number"> - Float number to be checked</param>
	/// <returns> - True if input is a floating point nubmer, otherwise false</returns>
	bool inputFloat(float *number);

	/// <summary>
	/// Checks if user input is of type int
	/// </summary>
	/// <param name="number"> - int number to be checked</param>
	/// <returns> - True if input is of data type int, otherwise false</returns>
	bool inputInt(int* number);

	/// <summary>
	/// Pauses/stops the console screen
	/// </summary>
	/// <param name="temp"> - Pointer for dummy variable for storing input</param>
	void pauseScreen();
};