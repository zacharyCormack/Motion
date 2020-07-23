#pragma once
#include <iostream>
using namespace std;

class Dot
{
	char colour;
	static char* colours[8];
public:
	short direc[5];
	void draw();
	Dot(char, short [5]);
};