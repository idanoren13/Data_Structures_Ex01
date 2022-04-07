#include "ColorArray.h"

ColorArray::ColorArray(int _size)
{
	size = _size;
	array = new bool[size];
}


void ColorArray::initArrayToWhite()
{
	for (int i = 0; i < size; i++)
	{
		array[i] = WHITE;
	}
}

bool* ColorArray::GetArray()
{
	return array;
}
bool ColorArray::operator[](int index)
{
	return array[index];
}