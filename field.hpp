#pragma once
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <vector>
#include "dot.hpp"
using namespace std;

class Field
{
	unsigned side;
	vector<Dot> dots;
	vector<vector<unsigned> > coords;
public:
	void draw();
	void iterate();
	Field(unsigned, unsigned);
};