/*
  t-eval.cpp

  Firing Squad Synhronization Problem:
    test/example for evaluation function using Automata

    Create Automata
    Apply evaluation function on a solution


See for reference:
    Manuel Clergue, Sébastien Verel, Enrico Formenti, 
    An Iterated Local Search to find many solutions of the 6-states Firing Squad Synchronization Problem, 
    Applied Soft Computing, Volume 66, May 2018, Pages 449-461.
    http://www-lisic.univ-littoral.fr/~verel/RESEARCH/firing-squad-synchronization-problem/index.html

 Author: 
  Sebastien Verel, 
  Univ. du Littoral Côte d'Opale, France.

*/

#include <iostream>
#include <fstream>

#include <base/solution.h>
#include <base/automata.h>

int main(int argc, char ** argv) {
	//srand(time(NULL));
    // maximum size of the cellular automata
    int maxSize = 30;

    // cellular automata
    Automata ca(maxSize);
    // number of states
    unsigned nbStates = 5;
    // create an empty solution
    Solution x(nbStates);
    // read from file
    //std::fstream filein("../solution/solution_5.dat", std::ios::in);
    //x.readFrom(filein);
	//filein.close();
    // print with no fitness value (I = Invalid fitness)
    x.setRandomRules();
    ca.eval(x,maxSize);
	std::cout << x << std::endl;
	//}
    // evaluation function of the solution
    //ca.eval(x, maxSize);
	ca.hillClimberFirst(x,30,1000000);
	//ca.iteratedLocalSearch(x,30,1000000);
	ca.eval(x,maxSize);
	std::cout << x << std::endl;
	//std::cout<<" finess final : " << x.fitness();

}
