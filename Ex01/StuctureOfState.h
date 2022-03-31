#pragma once
#include <vector>
#include <string>
#include <sstream>

#include "PointerLinkedList.h"
using namespace std;
class StuctureOfState
{
public:
	
	PointerLinkedList* arrayOfCities = nullptr;
	void initStructure(int numberOfCities, int numberOfRoads, string roadsStr);
	
};

