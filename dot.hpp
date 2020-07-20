#pragma once

class Dot
{
	char colour;
	static char* colours[8];
public:
	char direc;
	void draw(unsigned, unsigned);
	Dot(char, char);
};