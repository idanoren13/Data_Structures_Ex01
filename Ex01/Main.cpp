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
	state.initStructure(10, 16, "10 1 3 5 1 2 6 4 7 6 10 3 6 4 9 6 4 7 4 2 2 10 3 7 2 5 9 4 2 4 10 3");           //**********get from user
	int country = 2;                                            //**********get from user

	LinkedList accessibleGroup(10);                             // accessible group
	bool* colorArray = creatColorArray(10);                    // color array

	//goToTwonRec(state, country - 1 , colorArray, accessibleGroup);
	goToTwonIter(state, country - 1, colorArray, accessibleGroup);
	accessibleGroup.PrintList();
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



void goToTwonIter(const StuctureOfState& state, int firstCity, bool* colorArray, LinkedList& accessibleGroup)
{
	Stack s;
	type curr;
	bool returnFromRec = false;
	 
	curr = { firstCity, IS_WHITE };

	do
	{
		if (returnFromRec == true)
			curr = s.pop();

		if (curr.colorLabel == IS_WHITE)
		{
			colorArray[curr.city] = BLACK;
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