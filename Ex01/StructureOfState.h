#pragma once
#include "LinkedList.h"
#include "ItemType.h"
class StructureOfState
{
public:
	LinkedList<ItemType> arrayOfList[];
	StructureOfState();
	~StructureOfState();

};

