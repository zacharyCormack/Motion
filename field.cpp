#include "field.hpp"

Field::Field(unsigned side_length, unsigned num_dots)
{
	side = side_length;
	srand((unsigned)time(NULL));
	while (num_dots-->0)
	{
		Dot new_dot((char)(rand()%8), (char)(rand()%120));
		dots.push_back(new_dot);
		coords.push_back((unsigned [2]){rand()%side, rand()%side});
	}
}

void Field::draw()
{
	for (unsigned i = 0; i < dots.size(); i++)
	{
		dots[i].draw(coords[i][0], coords[i][1]);
	}
}

void Field::iterate()
{
	unsigned die = rand()%6;
	for (unsigned i = 0; i < dots.size(); i++)
	{
		switch(die)
		{
			case 0:
				switch((int)(dots[i].direc)/24)
				{
					case 0:
						coords[i][0]++;
						break;
					default:
						break;
				}
				break;
			case 1:
				/* code */
				break;
			case 2:
				/* code */
				break;
			case 3:
				/* code */
				break;
			case 4:
				/* code */
				break;
			default:
				break;
		}
	}
}