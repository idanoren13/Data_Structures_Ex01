#include "LinkedList.h"
#include "StuctureOfState.h"
#include "Stack.h"
#include "ColorArray.h"

#include "GoToTownRec.h"
#include "GoToTownIter.h"

#include <iostream>

using namespace std;


void main()
{

	int numberOfCities, numberOfRoads, city = 3;
	string roadsStr;
	try 
	{
		cin >> numberOfCities >> numberOfRoads;
		if (numberOfCities < 1 || numberOfRoads < 1)
			throw 1;
		cin.ignore();
		std::getline(std::cin, roadsStr);
		cin >> city;
		if (city <1 || city >numberOfCities)
			throw 2;
	}
	catch (const int n) 
	{
		cout << "invalid input";
		exit(1);
	}
	StuctureOfState state;
	if (state.initStructure(numberOfCities, numberOfRoads, roadsStr) == true) {
		LinkedList accessibleGroup1(numberOfCities);
		LinkedList accessibleGroup2(numberOfCities);
		ColorArray colorArray(numberOfCities);
		colorArray.initArrayToWhite();

		//Recursive algorithm
		goToTownRec(state, city - 1, colorArray, accessibleGroup1);
		cout << "Cities accessible from source city 1 (recursive algorithm): ";
		accessibleGroup1.PrintList();
		cout << endl;

		//reset
		state.resetStructure();
		colorArray.initArrayToWhite();

		//Iterative algorithm
		goToTownIter(state, city - 1, colorArray, accessibleGroup2);
		cout << "Cities accessible from city source city 1 (iterative algorithm): ";
		accessibleGroup2.PrintList();
		cout << endl;
	}

}



