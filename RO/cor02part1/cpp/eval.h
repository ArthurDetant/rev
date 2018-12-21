#ifndef _eval_h
#define _eval_h

#include <solution.h>
#include <fstream>

/******************************************************
 * Abstract class for the computation of bit string evaluation
 */
class Eval {
public:
  /** constructor
   * 
   * @param _n problem size, length of the bit string
   */
  Eval(unsigned int _n) : _pbSize(_n) { }

  /** Empty constructor
   * 
   * default problem size is 0
   */
  Eval() : _pbSize(0) { }

  // return the size of the problem
  unsigned int size() {
    return _pbSize;
  }

  // Set the size of the problem
  void setSize(unsigned int _n) {
    _pbSize = _n;
  }

  // evaluation function to be defined
  virtual void operator()(Solution & _solution) = 0;

protected:
  // bit string length
  unsigned int _pbSize;
};

/******************************************************
  OneMax evaluation function:
  count the number of "1" in the bit string
  
  @param _solution the solution to evaluated
 */

class OneMax : public Eval {
public:
  // constructor
  OneMax(unsigned int _n) : Eval(_n) { }

  // evaluation function 
  void operator()(Solution & _solution) {
    int value = 0;

    for(unsigned int i = 0; i < _solution.size(); i++)
      if (_solution[i])
	value++;

    _solution.fitness(value);
  }
};

/******************************************************
  Knapsack evaluation function:
    with linear penalty function
  
  @param _solution the solution to evaluated
 */

class Knapsack : public Eval {
public:
  // constructor
  Knapsack(const char * _fileName) : Eval() { 
    std::fstream file(_fileName, std::ios::in);

    if(file) {
      file >> nObject;
      
      profits = new int[nObject];
      weights = new int[nObject];

      for(unsigned int i = 0; i < nObject; i++)
	file >> profits[i];

      for(unsigned int i = 0; i < nObject; i++)
	file >> weights[i];

      beta = 0;
      for(unsigned int i = 0; i < nObject; i++) {
	if (weights[i] > 0 && profits[i] >= 0)
	  if (profits[i] / weights[i] > beta)
	    beta = profits[i] / weights[i];
      }

      file >> C;

      file.close();

      setSize(nObject);
    }
  }

  // evaluation function 
  void operator()(Solution & _solution) {
    int W = 0;
    int P = 0;

    for(unsigned int i = 0; i < _solution.size(); i++)
      if (_solution[i]) {
	W += weights[i];
	P += profits[i];
      }

    if (W <= C)
      _solution.fitness(P);
    else
      _solution.fitness(P - beta * (W - C));
  }

protected:
  // number of objects
  unsigned int nObject;

  // profit of objects
  int * profits;

  // weight of objects
  int * weights;

  // Maximum capacity of the sack
  int C;

  // constant of the linear constraint
  double beta;
};

#endif

