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
		int start = rand();
		short step = rand()%4+1;
		short direction[] = {start%5+1, (start+step)%5+1, (start+2*step)%5+1, (start+3*step)%5+1, (start+4*step)%5+1};
		cout << start%5+1 << " " << (start+step)%5+1 << " " << (start+2*step)%5+1 << " " << (start+3*step)%5+1 << " " << (start+4*step)%5+1 << endl;
		Dot new_dot((char)(rand()%8), direction);
		dots.push_back(new_dot);
		vector<unsigned> new_coord;
		new_coord.push_back(rand()%side);
		new_coord.push_back(rand()%side);
		coords.push_back(new_coord);
	}
	cin.ignore();
	cout << "\e[H";
}

void Field::draw()
{
	for (unsigned i = 0; i < side; i++)
	{
		for (unsigned j = 0; j < side; j++)
		{
			for (unsigned k = 0; k < coords.size(); k++)
				if (coords[k][0] == i && coords[k][1] == j)
					dots[k].draw();
			cout << "\e[0m  ";
		}
		cout << "\n  ";
	}
}

void Field::iterate()
{
	usleep(275000);
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
		{
			unsigned dir = dots[i].direc[die];
			unsigned* coord = &(coords[i][dir < 2 ? 1 : 0]);
			*coord += dir%2==0 ? (*coord<side-1 ? 1 : 0) : (*coord>0 ? -1 : 0);
		}
	}
}