#include "GoToTownIter.h"
#include "Stack.h"

void goToTownIter(const StuctureOfState& state, int firstCity, ColorArray colorArray, LinkedList& accessibleGroup)
{
	Stack s;
	type curr;
	bool returnFromRec = false;

	curr = { firstCity, IS_WHITE };
	s.push({ firstCity, IS_BLACK });
	do
	{
		if (returnFromRec == true)
			curr = s.pop();

		if (curr.colorLabel == IS_WHITE)
		{
			colorArray.GetArray()[curr.city] = BLACK;
			accessibleGroup.Insert(curr.city);
			state.arrayOfCities[curr.city].iter.advanceIterator();
		}

		if (state.arrayOfCities[curr.city].iter != nullptr)
		{
			if (colorArray[state.arrayOfCities[curr.city].iter.getData()] == WHITE)
			{
				curr.colorLabel = IS_BLACK;
				s.push(curr);
				curr = { state.arrayOfCities[curr.city].iter.getData(), IS_WHITE };
			}
			else
			{
				state.arrayOfCities[curr.city].iter.advanceIterator();
				curr.colorLabel = IS_BLACK;
			}
			returnFromRec = false;
		}
		else
		{
			returnFromRec = true;
		}
	} while (s.isEmpty() == false);
}