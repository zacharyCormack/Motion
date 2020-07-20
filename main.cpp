#include <iostream>
#include <unistd.h>
#include "field.hpp"
using namespace std;

int main()
{
	Field field(8, 16);
	unsigned timer = 0;
	while (timer ++< 200)
	{
		field.iterate();
		field.draw();
		cout << timer;
	}
	return 0;
}