#include "StuctureOfState.h"

void StuctureOfState::initStructure(int numberOfCities, int numberOfRoads, string roadsStr) 
{
	int start, destination;
	arrayOfCities = new PointerLinkedList[numberOfCities];
	stringstream ss(roadsStr);
	for (int i = 0; i < numberOfRoads; i++)
	{
		ss >> start;
		ss >> destination;
		if (start > numberOfCities || destination > numberOfCities)
		{
			throw "wrong input";
		}
		arrayOfCities[start-1].insertToTail(destination-1); 
		//can we insert multiply roads from each city?
	}
}