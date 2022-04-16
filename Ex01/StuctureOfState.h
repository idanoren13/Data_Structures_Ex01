#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "PointerLinkedList.h"
using namespace std;
class StuctureOfState
{
	int arraySize;
public:
	PointerLinkedList* arrayOfCities = nullptr;
	bool initStructure(int numberOfCities, int numberOfRoads, string roadsStr);
	void resetStructure();
	~StuctureOfState()
	{
		for (int i = 0; i < arraySize; i++)
		{
			arrayOfCities[i].~PointerLinkedList();
		}
	}
};

