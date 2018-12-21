#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Solution.hpp"
using namespace std;

class Knapsack{
	public:
        std::vector<int> _profits;
        std::vector<int> _poids;
        int _capacite;
        double _beta;
        int n;

		Knapsack(std::string filename);
		void eval(Solution & s);
		void print();

};
#endif

