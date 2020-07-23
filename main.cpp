#include <iostream>
#include "field.hpp"
using namespace std;

int main()
{
	cout << "\e[1;1H\e[2J";
	Field field(32, 16);
	unsigned timer = 0;
	while (timer < 128)
	{
		field.iterate();
		field.draw();
		cout << "\e[40;0H" << ++timer << "\e[H";
	}
	cout << "\e[1;1H\e[2J";
	return 0;
}