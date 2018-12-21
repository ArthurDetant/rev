#ifndef _search_h
#define _search_h

#include <solution.h>
#include <eval.h>

/******************************************************
 * Abstract class which perform a search
 */
class Search {
public:
  // constructor
  Search(Eval & _evalFunc) : _eval(_evalFunc) { }

  // vrtual method to perform the search
  virtual void operator()() = 0 ;

  // the current solution of the search
  Solution & solution() {
    return _solution;
  }

  // the current quality of the solution
  int fitness() {
    return _solution.fitness();
  }

  // number of evaluations
  unsigned int nbEval() {
    return _nbEval;
  }

protected:
  // evaluation function
  Eval & _eval;

  // solution of the search
  Solution _solution;

  // number of evaluation
  unsigned int _nbEval;
};

/**
 *  Initialization to a random bit string
 *
 * @param _n size of the bit string
 * @param _solution the solution to initialize
 */
void randomSolution(int _n, Solution & _solution) {
  _solution.resize(_n);

  for(unsigned int i = 0; i < _n; i++) 
    _solution[i] = (random() % 2 == 1);  // random() % 2 donne 0 ou 1

}

/**
 *  Initialization to the bit string O^N
 *
 * @param _n size of the bit string
 * @param _solution the solution to initialize
 */
void zeroSolution(int _n, Solution & _solution) {
  _solution.resize(_n);

  for(unsigned int i = 0; i < _n; i++) 
    _solution[i] = false;

}

/**************************************************
 * Random search
 * perform a random search
 *
 */
class RandomSearch : public Search 
{
public:
  // construction
  RandomSearch(Eval & _eval, int _nbEvalMax) : Search(_eval), nbEvalMax(_nbEvalMax) { }

  // the search
  void operator()() {
    randomSolution(_eval.size(), _solution);
    _eval(_solution);
    _nbEval = 1;

    Solution bestSol(_solution);

    while(_nbEval < nbEvalMax) {
      randomSolution(_eval.size(), _solution);
      _eval(_solution);
      _nbEval++;

      if (bestSol.fitness() < _solution.fitness()) {
	bestSol = _solution;
      }
    } 

    // set the solution to the best one
    _solution = bestSol;
  }

protected:
  int nbEvalMax;

};

/**************************************************
 * Random walk
 * perform a random walk
 *
 */
class RandomWalk : public Search 
{
public:
  /** constructor
   *
   * @param _eval evaluation function
   * @param _maxEval maximum number of evaluation
   */
  RandomWalk(Eval & _eval, unsigned int _maxEval) : Search(_eval), _maxNbEval(_maxEval) { 
    walk = new int[_maxEval];
  }

  // destructor
  ~RandomWalk() {
    delete [] walk;
  }

  // the search
  void operator()() {
    // initialization
    randomSolution(_eval.size(), _solution);
    _eval(_solution);
    walk[0] = _solution.fitness();
    _nbEval = 1;

    // bit to flip
    unsigned int i;

    while(_nbEval < _maxNbEval) {
      // flip one bit at random
      i = random() % _eval.size();
      _solution[i] = ! _solution[i];

      // evaluation
      _eval(_solution);
      // save
      walk[_nbEval] = _solution.fitness();
      _nbEval++;
    }
  }

  // print the walk
  void print() {
    for(unsigned int i = 0; i < _maxNbEval; i++)
      std::cout << walk[i] << std::endl;
  }

private:
  // maximum number of evaluations
  unsigned int _maxNbEval ;

  // save the walk
  int * walk;
};

/**************************************************
 * Hill-climbing search
 * perform a best improvement search
 *
 */
class HillClimbing : public Search 
{
public:
  /** constructor
   *
   * @param _eval evaluation function
   * @param _maxEval maximum number of evaluation
   * @param _max maximum fitness to reach
   */
  HillClimbing(Eval & _eval, unsigned int _maxEval, int _max) : Search(_eval), _maxNbEval(_maxEval), _maxFitness(_max) { }

  // the search
  void operator()() {
    // initialization
    randomSolution(_eval.size(), _solution);
    _eval(_solution);
    _nbEval = 1;

    // bit to flip
    unsigned int i;

    // current fitness of the solution
    int currentFitness;

    // to compute the best neighbor
    int bestNeighbor;
    int iBest;

    while(_nbEval < _maxNbEval && _solution.fitness() < _maxFitness) {
      // explore all the neighborhood
      iBest = -1;
      currentFitness = _solution.fitness();
      for(i = 0; i < _eval.size(); i++) {
	// flip the bit i
	_solution[i] = ! _solution[i];

	// evaluation
	_eval(_solution);
	_nbEval++;

	// update the current best neighbor
	if (iBest < 0 || bestNeighbor < _solution.fitness()) {
	  bestNeighbor = _solution.fitness();
	  iBest = i;
	}

	// flip back
	_solution[i] = ! _solution[i];
	_solution.fitness(currentFitness);
      } // end of the exploration

      // update the current solution (acceptance criterium)
      if (_solution.fitness() < bestNeighbor) {
	_solution[iBest] = ! _solution[iBest];
	_solution.fitness(bestNeighbor);
      }
    }
  }

private:
  // maximum number of evaluations
  unsigned int _maxNbEval ;

  // maximum fitness to reach
  int _maxFitness;
};

/**************************************************
 * First-improvement Hill-climbing search
 * perform a first improvement search
 *
 */
class FirstImprovement : public Search 
{
public:
  /** constructor
   *
   * @param _eval evaluation function
   * @param _maxEval maximum number of evaluation
   * @param _max maximum fitness to reach
   */
  FirstImprovement(Eval & _eval, unsigned int _maxEval, int _max) : Search(_eval), _maxNbEval(_maxEval), _maxFitness(_max) { }

  // the search
  void operator()() {
    // initialization
    randomSolution(_eval.size(), _solution);
    _eval(_solution);
    _nbEval = 1;

    // bit to flip
    unsigned int i;

    // current fitness of the solution
    int currentFitness;

    while(_nbEval < _maxNbEval && _solution.fitness() < _maxFitness) {
      currentFitness = _solution.fitness();

      // flip one bit at random
      i = random() % _eval.size();
      _solution[i] = ! _solution[i];

      // evaluation
      _eval(_solution);
      _nbEval++;

      // update the current solution:
      // accept if strictly better
      if (_solution.fitness() <= currentFitness) {
	// flip back to the current solution
	_solution[i] = ! _solution[i];
	_solution.fitness(currentFitness);
      }
    }
  }

private:
  // maximum number of evaluations
  unsigned int _maxNbEval ;

  // maximum fitness to reach
  int _maxFitness;
};

/**************************************************
 * First-improvement Hill-climbing search
 * perform a first improvement search
 *
 */
class FirstImprovementWithoutReplacement : public Search 
{
public:
  /** constructor
   *
   * @param _eval evaluation function
   * @param _maxEval maximum number of evaluation
   * @param _max maximum fitness to reach
   */
  FirstImprovementWithoutReplacement(Eval & _eval, unsigned int _maxEval, int _max) : Search(_eval), _maxNbEval(_maxEval), _maxFitness(_max) { 
    neighbors = new int[_eval.size()];
    for(int i = 0; i < _eval.size(); i++)
      neighbors[i] = i;
  }
  
  ~FirstImprovementWithoutReplacement() {
    delete [] neighbors;
  }

  // the search
  void operator()() {
    // initialization
    randomSolution(_eval.size(), _solution);
    _eval(_solution);
    _nbEval = 1;

    // bit to flip
    unsigned int i, j;

    // current fitness of the solution
    int currentFitness;
    int neighborFitness;

    while(_nbEval < _maxNbEval && _solution.fitness() < _maxFitness) {
      currentFitness = _solution.fitness();

      // explore the neighborhood
      int nbNeighbor = 0;
      neighborFitness = currentFitness - 1;
      while (neighborFitness < currentFitness && nbNeighbor < _eval.size()) {
	// flip one bit at random
	j = random() % (_eval.size() - nbNeighbor);
	i = neighbors[j];
	_solution[i] = ! _solution[i];

	// evaluation
	_eval(_solution);
	_nbEval++;
	neighborFitness = _solution.fitness();

	// flip back
	_solution[i] = ! _solution[i];
	_solution.fitness(currentFitness);

	// don't put again the same neighbor
	nbNeighbor++;
	neighbors[j] = neighbors[_eval.size() - nbNeighbor] ;
	neighbors[_eval.size() - nbNeighbor] = i;
      }

      // update the current solution:
      // accept if better (or equal)
      if (currentFitness <= neighborFitness) {
	_solution[i] = ! _solution[i];
	_solution.fitness(neighborFitness);
      }

    }
  }

private:
  // maximum number of evaluations
  unsigned int _maxNbEval ;

  // maximum fitness to reach
  int _maxFitness;

  // list of neighbors
  int * neighbors;
};

#endif
