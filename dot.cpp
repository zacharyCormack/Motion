#include "dot.hpp"

Dot::Dot(char colour_ID, short direction[5])
{
	colour = colour_ID;
	direc[0] = direction[0];
	direc[1] = direction[1];
	direc[2] = direction[2];
	direc[3] = direction[3];
	direc[4] = direction[4];
}

void Dot::draw()
{
	cout << colours[colour];
}

char* Dot::colours[8] =
{
	"\e[40m  ",
	"\e[41m  ",
	"\e[42m  ",
	"\e[43m  ",
	"\e[44m  ",
	"\e[45m  ",
	"\e[46m  ",
	"\e[47m  "
};