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

//bool Records::deleteRecords(int student_id)
//{
//	nodePtr previous = new node;
//	current = head;
//
//	while (current != NULL)
//	{
//		if (current->id == student_id)
//		{
//			previous
//		}
//
//		current = current->next;
//	}
//
//	//Default return value
//	return false;
//}

void Records::printRecords()
{
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