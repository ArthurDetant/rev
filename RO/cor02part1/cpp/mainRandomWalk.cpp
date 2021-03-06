#include <iostream>
#include <stdlib.h>

#include <solution.h>
#include <eval.h>
#include <search.h>

using namespace std;

/**
 *  Main function
 */
int main(int argc, char **argv) {
  if (argc == 4) {
    // maximum number of evaluation
    int maxEval = atoi(argv[2]);

    // initialization of the random numbers sequence
    srandom(atoi(argv[3]));
    
    // Evaluation function
    //OneMax eval(n);
    Knapsack eval(argv[1]);

    // random search
    RandomWalk search(eval, maxEval);

    // perform the search
    search();

    // print the fitness of all solutions
    search.print();

  } else {
    cout << "3 arguments attendus : " << endl;
    cout << "nom du fichier de l'instance de problème de sac à dos, nombre d'évaluation et la graine du générateur de nombres pseudo-aléatoires" << endl;
  }
  
}
