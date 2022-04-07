#pragma once
#include "LinkedList.h"
#include "StuctureOfState.h"
#include "ColorArray.h"

#define WHITE true
#define BLACK false

void goToTownIter(const StuctureOfState& state, int city, ColorArray colorArray, LinkedList& accessibleGroup);
