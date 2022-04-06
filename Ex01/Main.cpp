#include "LinkedList.h"
#include "StuctureOfState.h"
#include <iostream>
#include "Stack.h"
using namespace std;

#define WHITE true
#define BLACK false

LinkedList createAccessibleGroup(int sizeOfState);
bool* creatColorArray(int arraySize);
void initArrayTo0(bool* array, int size);
void goToTwonRec(const StuctureOfState& state, int city, bool* colorArray, LinkedList& accessibleGroup);
void goToTwonIter(const StuctureOfState& state, int city, bool* colorArray, LinkedList& accessibleGroup);


void main()
{

	StuctureOfState state;
	state.initStructure(5, 5, "1 4 3 2 3 5 2 4 4 5");           //**********get from user
	int country = 1;                                            //**********get from user

	LinkedList accessibleGroup(5);                             // accessible group
	bool* colorArray = creatColorArray(5);                    // color array

	//goToTwonRec(state, country - 1 , colorArray, accessibleGroup);
	goToTwonIter(state, country - 1, colorArray, accessibleGroup);

}

void goToTwonRec(const StuctureOfState& state, int city, bool* colorArray, LinkedList& accessibleGroup)
{
	colorArray[city] = BLACK;
	accessibleGroup.Insert(city);  //insert country index
	
	for (state.arrayOfCities[city].iter; state.arrayOfCities[city].iter != nullptr ; state.arrayOfCities[city].iter.advanceIterator())
	{
		if (colorArray[state.arrayOfCities[city].iter.getData()] == WHITE) {
			goToTwonRec(state, state.arrayOfCities[city].iter.getData(), colorArray, accessibleGroup);
		}
	}
}

bool* creatColorArray(int arraySize)
{
	bool* colorArray = new bool[arraySize];
	initArrayTo0(colorArray, arraySize);

	return colorArray;
}

void initArrayTo0(bool* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = WHITE;
	}
}


/*

void goToTwonRec(const StuctureOfState& state, int city, bool* colorArray, LinkedList& accessibleGroup)
{
	//START method
	colorArray[city] = BLACK;
	accessibleGroup.Insert(city);  //insert country index

	for (state.arrayOfCities[city].iter; state.arrayOfCities[city].iter != nullptr ; state.arrayOfCities[city].iter.advanceIterator())
	{	//NOT FINISHED FOR LOOP
		if (colorArray[state.arrayOfCities[city].iter.getData()] == WHITE) {
			goToTwonRec(state, state.arrayOfCities[city].iter.getData(), colorArray, accessibleGroup);
		}
	}
	//FINISHED LOOP
}

*/

void goToTwonIter(const StuctureOfState& state, int city, bool* colorArray, LinkedList& accessibleGroup)
{
	Stack s;
	type curr;
	bool returnFromRec = false;
	 
	curr = { city, START };

	do
	{
		if (returnFromRec == true)
			curr = s.pop();

		if (curr.line == START)
		{
			colorArray[curr.city] = BLACK;
			accessibleGroup.Insert(curr.city);

			if (state.arrayOfCities[curr.city].iter != nullptr)
			{
				if (colorArray[state.arrayOfCities[curr.city].iter.getData()] == WHITE)
				{
					state.arrayOfCities[curr.city].iter.advanceIterator();
					curr = { state.arrayOfCities[curr.city].iter.getData(), START };
					s.push(curr);
					returnFromRec = true;
				}
			}
			else
			{
				returnFromRec = false;
			}
		}
		
	} while (s.isEmpty() == false);
}