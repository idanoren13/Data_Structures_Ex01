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
	int numberOfCities, numberOfRoads, city=3;
	string roadsStr;

	/*cin >> numberOfCities >> numberOfRoads;
	cin >> roadsStr;
	cin >> city;*/

	StuctureOfState state;
	state.initStructure(5, 5, "1 4 3 2 3 5 2 4 4 5");
	                                           
	LinkedList accessibleGroup(5);                             // accessible group
	ColorArray colorArray(5);
	colorArray.initArrayToWhite();

	goToTownRec(state, city - 1 , colorArray, accessibleGroup);
	accessibleGroup.PrintList();

	//reset state iterators 
	colorArray.initArrayToWhite();

	goToTownIter(state, city - 1, colorArray, accessibleGroup);
	accessibleGroup.PrintList();
}



