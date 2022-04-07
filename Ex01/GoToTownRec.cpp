#include "GoToTownRec.h"




void goToTownRec(const StuctureOfState& state, int city, ColorArray colorArray, LinkedList& accessibleGroup)
{
	colorArray.GetArray()[city] = BLACK;
	accessibleGroup.Insert(city);  //insert country index

	for (state.arrayOfCities[city].iter; state.arrayOfCities[city].iter != nullptr; state.arrayOfCities[city].iter.advanceIterator())
	{
		if (colorArray[state.arrayOfCities[city].iter.getData()] == WHITE) {
			goToTownRec(state, state.arrayOfCities[city].iter.getData(), colorArray, accessibleGroup);
		}
	}
}

