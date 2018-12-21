/******************************************************
 * Abstract class which perform a search
 */
abstract public class Search {
  // constructor
  Search(Eval evalFunc) { 
      this.eval = evalFunc;
      this.nbEval = 0;
  }

  // vrtual method to perform the search
  abstract void run() ;

  // the current solution of the search
  Solution solution() {
    return solution;
  }

  // the current quality of the solution
  double fitness() {
    return this.solution.fitness();
  }

  // number of evaluations
  int nbEval() {
    return this.nbEval;
  }

  // evaluation function
  protected Eval eval;

  // solution of the search
  protected Solution solution;

  // number of evaluation
  protected int nbEval;
}
