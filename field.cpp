#include "field.hpp"

inline void pull(short g[6], short n)
{
	while (g[++n])
		g[n-1] = g[n];
}

Field::Field(unsigned side_length, unsigned num_dots)
{
	side = side_length;
	srand((unsigned)time(NULL));
	while (num_dots-->0)
	{
		short direction[5];
		short nums[] = {1, 2, 3, 4, 5, 0};
		for (short i = 0; i < 5; i++)
		{
			short tmp = rand() % 5-i;
			direction[i] = tmp;
			pull(nums, tmp);
		}
		Dot new_dot((char)(rand()%8), direction);
		dots.push_back(new_dot);
		vector<unsigned> new_coord;
		new_coord.push_back(rand()%side);
		new_coord.push_back(rand()%side);
		coords.push_back(new_coord);
	}
}

void Field::draw()
{
	for (unsigned i = 0; i < dots.size(); i++)
		dots[i].draw(coords[i][0], coords[i][1]);
}

void Field::iterate()
{
	unsigned die = rand()%5;
	const int facs[] = {24, 6, 2, 1, 1};
	for (unsigned i = 0; i < dots.size(); i++)
	{
		if (dots[i].direc[die] == 5)
		{
			int swp = dots[i].direc[4];
			dots[i].direc[4] = dots[i].direc[3];
			dots[i].direc[3] = dots[i].direc[2];
			dots[i].direc[2] = dots[i].direc[1];
			dots[i].direc[1] = dots[i].direc[0];
			dots[i].direc[0] = swp;
		}
		else
			coords[i][dots[i].direc[die] < 2 ? 1 : 0] += dots[i].direc[die]%2==0 ? 1 : -1;
		if (coords[i][dots[i].direc[die] < 2 ? 1 : 0] > side)
			coords[i][dots[i].direc[die] < 2 ? 1 : 0] = side;
		else if (coords[i][dots[i].direc[die] < 2 ? 1 : 0] < 0)
			coords[i][dots[i].direc[die] < 2 ? 1 : 0] = 0;
	}
	usleep(1000000);
}