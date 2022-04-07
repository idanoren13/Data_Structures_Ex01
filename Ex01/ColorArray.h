#pragma once

#define WHITE true
#define BLACK false

class ColorArray
{
	bool* array;
	int size;

public:
	ColorArray(int size);
	void initArrayToWhite();
	bool* GetArray();
	bool operator[](int index);

};

