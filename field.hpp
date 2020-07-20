#pragma once
#include <cstdlib>
#include <ctime>
#include <vector>
#include "dot.hpp"
using namespace std;

class Field
{
	unsigned side;
	vector<Dot> dots;
	vector<unsigned [2]> coords;
public:
	void draw();
	void iterate();
	Field(unsigned, unsigned);
};