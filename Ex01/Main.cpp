#include "LinkedList.h"
#include "StuctureOfState.h"
#include <iostream>
using namespace std;

#define WHITE 0
#define BLACK 1

LinkedList createAccessibleGroup(int sizeOfState);
bool* creatColorArray(int arraySize);
void initArrayTo0(bool* array, int size);


void main()
{

	StuctureOfState state;
	state.initStructure(5, 5, "1 4 3 2 3 5 2 4 4 5");           //**********get from user
	int country = 1;                                            //**********get from user

	LinkedList accessibleGroup(5);                             // accessible group
	bool* colorArray = creatColorArray(5);                    // color array

	accessibleGroup = goToTwonRec(state, country, colorArray, accessibleGroup);
}

LinkedList goToTwonRec(StuctureOfState state, int country, bool* colorArray, LinkedList accessibleGroup)
{
	colorArray[country - 1] = BLACK;
	accessibleGroup.Insert(country - 1);  //insert country index

	/* 
	 
	* for (curr = state.arrayOfCities[country-1].getHead(); curr !=nullptr and white; curr=curr.next)
	* {
	*	goTOTOwn(state,curr.getdata,coloarArray,acessibleGroup);
	* }
	*	while (state.arrayOfCities[country-1].getNext()!=null && colorArray[???] == WHITE)
	* {
	*     goToTwonRec(StuctureOfState state, int **neighbor**, bool* colorArray, LinkedList accessibleGroup)
	* }                                       
	
	TODO:
	 how to promote to next neighbor?**  state.arrayOfCities[country-1].getNext().data?

	*/
	
	return accessibleGroup;
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