#pragma once

#include <string>
#include "Utilities.h"

class Records : public Utilities
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
	bool insertRecords(std::string name, float score_1, float score_2, float score_3);
	bool displayRecord(int record_id);
	bool deleteRecords(int record_id);
	bool updateRecords(int record_id);
	void printRecords();
	int locateId(int id);

	//Miscelleneous function
	int generateId();
};

