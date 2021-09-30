#pragma once

#include <string>

class Records
{
private:

	//Main node struct
	struct node {
		int id;
		std::string name;
		float score_1, score_2, score_3, average;
		node* next;
	};
		
	typedef struct node* nodePtr;

	nodePtr head, current, temp;

public:
	//Constructor
	Records();
	void insertRecords(std::string name, float score_1, float score_2, float score_3);
	void deleteRecords();
	void updateRecords();
	void printRecords();

	//Miscelleneous function
	int generateId();
};

