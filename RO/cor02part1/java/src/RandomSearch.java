import java.util.Random;

/**************************************************
 * Random search
 * perform a random search
 *
 *************************************************/
public class RandomSearch extends Search 
{
  // construction
    public RandomSearch(Random random, Eval eval, int nbEvalMax) {
	super(eval);
	this.random = random;
	this.nbEvalMax = nbEvalMax;
	randomInit = new RandomInit(random, eval.size());
    }

    // the search
    public void run() {
	// initialization
	solution = new Solution();

	randomInit.init(solution);
	eval.apply(solution);
	int nEval = 1;

	Solution best = solution.clone();

	while (nEval < this.nbEvalMax) {
	    randomInit.init(solution);
	    eval.apply(solution);
	    nEval += 1;

	    if (best.fitness() < solution.fitness())
		best.copy(solution);
	}

	this.nbEval += nEval;

	// set the solution to the best one at the end
	solution.copy(best);
    }

    // random generator
    private Random random;

    // initialization method
    private RandomInit randomInit;

    // maximum number of evaluation
    private int nbEvalMax;
}

