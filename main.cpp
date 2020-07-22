#include <iostream>
#include "field.hpp"
using namespace std;

int main()
{
	cout << "\e[1;1H\e[2J";
	Field field(16, 8);
	unsigned timer = 0;
	while (timer < 200)
	{
		field.iterate();
		field.draw();
		cout << "\e[0m" << ++timer << "\e[1;1H\e[2J";
	}
	cout << "\e[1;1H\e[2J";
	return 0;
}