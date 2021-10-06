#include <Random>
#include <iostream>
#include <string>
#include "Records.h"

Records::Records()
{
	head = NULL;
	current = NULL;
	temp = NULL;
}

/// <summary>
/// Insert new records node to the records list
/// </summary>
/// <param name="name"> - Name of student</param>
/// <param name="score_1"> - First score of student</param>
/// <param name="score_2"> - Second score</param>
/// <param name="score_3"> - Third score</param>
/// <returns> 
/// boolean value - return true if inserted to existing node, 
/// false if a new node was created  
/// </returns>
bool Records::insertRecords(std::string name, float score_1, float score_2, float score_3)
{
	nodePtr newNode = new node;

	//Make newnode next pointer point to nothing
	newNode->next = NULL;

	//Assign data
	newNode->id = generateId();
	newNode->name = name;
	newNode->score_1 = score_1;
	newNode->score_2 = score_2;
	newNode->score_3 = score_3;
	newNode->average = (score_1 + score_2 + score_3) / 3;

	if (head != NULL)
	{
		//Assign current pointer to the head/start of the list
		current = head;

		//Traverse through the list until the tail/end
		while (current->next != NULL)
		{
			current = current->next;
		}

		//Assign new node to the end of the list
		current->next = newNode;

		return true;
	}
	else
	{
		//Assign new node to the head if list is empty
		head = newNode;

		return false;
	}
}

bool Records::deleteRecords(int student_id)
{
	nodePtr previous, current;

	//Linked list is empty
	if (!head)
	{
		return false;
	}

	//First element is the element to delete
	else if (head->id == student_id)
	{
		current = head->next;
		delete	head;
		head = current;
		return true;

	}
	else
	{
		//Initialize current node to the head/start
		current = head;
		previous = NULL;

		//Traverse through the list
		while (current != NULL && current->id != student_id)
		{
			previous = current;
			current = current->next;
		}

		//Traverse through the list
		if (current != NULL)
		{
			previous->next = current->next;
			delete current;
			return true;
		}
	}

	//Default return value
	return false;
}

bool Records::updateRecords(int record_id)
{
	Utilities utils;

	if (!head)
	{
		//Linked list is empty
		return false;
	}

	nodePtr current = head;
	bool exists = false;

	while (current != NULL)
	{
		if (current->id == record_id)
		{
			exists = true;
			int choice;
			float newScore;

			std::cout << "\nStudent record found!\n";

			displayRecord(record_id);
			
			std::cout << "\nEnter score to update [1-3]: ";
			if (!utils.inputInt(&choice))
			{
				exists = false;
				std::cout << "\nInvalid input, operation aborted";
				break;
			}
			
			std::cout << "\nEnter new value for score " << choice << ": ";
			if (!utils.inputFloat(&newScore))
			{
				exists = false;
				std::cout << "\nInvalid input, operation aborted";
				break;
			}

			switch (choice)
			{
			case 1:
				current->score_1 = newScore;
				break;
			case 2:
				current->score_2 = newScore;
				break;
			case 3:
				current->score_3 = newScore;
				break;
			}

			current->average = (current->score_1 + current->score_2 + current->score_3) / 3;

			break;
		}

		current = current->next;
	}
	
	return exists;

}

void Records::printRecords()
{
	nodePtr current;

	current = head;

	while (current != NULL)
	{
		std::cout <<
			current->id << " " <<
			current->name << " " <<
			current->score_1 << " " <<
			current->score_2 << " " <<
			current->score_3 << " " <<
			current->average << " " <<
		std::endl;

		current = current->next;
	}
}

bool Records::displayRecord(int record_id)
{
	nodePtr current = head;

	if (!current)
	{
		return false;
	}
	
	bool exists = false;

	while (current != NULL)
	{
		if (current->id == record_id)
		{
			exists = true;
			std::cout << "\nStudent name: " << current->name << std::endl;
			std::cout << "\nScore 1: " << current->score_1;
			std::cout << "\tScore 2: " << current->score_2;
			std::cout << "\tScore 3: " << current->score_3 << "\n\n";
			break;
		}

		current = current->next;
	}

	return exists;
}

/// <summary>
/// Generates random number between 100 - 999
/// </summary>
/// <returns>Generated number</returns>
int Records::generateId()
{
	//Inititalize seed
	std::random_device seed;
	
	//Set seed to random number generator
	std::mt19937 rng(seed());

	//Distribution in range 100 - 999
	std::uniform_int_distribution<std::mt19937::result_type> dist(100, 999);

	return (dist(rng));
}

int Records::locateId(int id)
{
	nodePtr current = new node;

	if (!head)
	{
		return -1;
	}

	int index = 0;

	while (current != NULL && current->id != id)
	{
		index++;
	}

	return index;
}