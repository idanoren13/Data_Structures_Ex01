#include "StuctureOfState.h"

bool StuctureOfState::initStructure(int numberOfCities, int numberOfRoads, string roadsStr) 
{
	try {
		int start, destination;
		arraySize = numberOfCities;
		arrayOfCities = new PointerLinkedList[numberOfCities];
		stringstream ss(roadsStr);
		for (int i = 0; i < numberOfCities; i++)
		{
			arrayOfCities[i].insertToTail(i);
		}
		for (int i = 0; i < numberOfRoads; i++)
		{
			if (ss.rdbuf()->in_avail() == 0)
				throw 1;
			ss >> start;
			if (ss.rdbuf()->in_avail() == 0)
				throw 2;
			ss >> destination;
			if (start > numberOfCities || start <= 0 || destination > numberOfCities || destination <= 0)
			{
				throw 3;
			}
			arrayOfCities[start - 1].insertToTail(destination - 1);
		}
		if (ss >> start)
			throw 4;

		for (int i = 0; i < numberOfCities; i++)	//initate the iterators
		{
			arrayOfCities[i].beginIterator();
		}
	}
	catch (const int n) {
		std::cout << "invalid input";
		return false;
	}
	return true;
}

void StuctureOfState::resetStructure()
{
	for (int i = 0; i < arraySize; i++)
	{
		arrayOfCities[i].beginIterator();
	}
}
