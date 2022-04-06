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
		if (start > numberOfCities || start <= 0 || destination > numberOfCities || destination <= 0)
		{
			throw "invalid input";
		}
		arrayOfCities[start-1].insertToTail(destination-1); 
	}

	for (int i = 0; i < numberOfCities; i++)	//initate the iterators
	{
		arrayOfCities[i].beginIterator();
	}
}