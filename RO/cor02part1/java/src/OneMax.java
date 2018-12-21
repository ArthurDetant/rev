/******************************************************
  OneMax evaluation function:
  count the number of "1" in the bit string
  
  @param _solution the solution to evaluated
 */

class OneMax extends Eval {
  // constructor
  OneMax(int _n) { 
      super(_n);
  }

  // evaluation function 
  public void apply(Solution solution) {
    int value = 0;

    for(int i = 0; i < solution.size(); i++)
      if (solution.bitString[i])
	value++;

    solution.fitness(value);
  }
}

