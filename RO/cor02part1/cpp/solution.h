#ifndef _solution_h
#define _solution_h

#include <iostream>
#include <vector>

/**
   Classe pour représenter une solution
   
   Chaine de bits auquel est ajoutée la valeur de la qualité (fitness)
*/
class Solution : public std::vector<bool> {
public:
  Solution() : std::vector<bool>() {
  }

  Solution(const Solution & _s) : std::vector<bool>(_s) {
    _fitness = _s.fitness();
  }

  Solution& operator=(const Solution & _s) {
    this->resize(_s.size());
    for(unsigned int i = 0; i < _s.size(); i++)
      this->operator[](i) = _s[i];

    _fitness = _s.fitness();

    return *this;
  }

  /**
   * set the fitness
   */
  void fitness(double _fit) {
    _fitness = _fit;
  }

  /**
   * get the fitness
   */
  double fitness() const { 
    return _fitness; 
  }

  /**
   * print the solution
   */
  void print() {
    std::cout << this->fitness() << " " ;

    for(unsigned int i = 0; i < this->size(); i++)
      std::cout << this->operator[](i) ;

    std::cout << std::endl;
  }

private:
  // quality of the solution
  double _fitness;
};

#endif
