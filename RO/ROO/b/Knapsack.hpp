#ifndef DEF_KNAPSACK
#define DEF_KNAPSACK

#include <string>
#include <fstream>
#include "Solution.hpp"

using namespace std;

class Knapsack
{
	public :
	
	Knapsack();
	void eval (Solution &s);
	vector <int> p;
	vector <int> w;
	int capacity;
	int items;

};

#endif
