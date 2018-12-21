import java.util.Random;

/**************************************************
 * Random Walk
 * perform a random walk:
 *    At each step, a random neighbor is selected
 *
 *************************************************/
public class RandomWalk extends Search 
{
    /** constructor
     *
     * @param _eval evaluation function
     * @param _maxEval maximum number of evaluation
     */
    public RandomWalk(Random random, Eval eval, int maxEval) {
	super(eval);
	this.random = random;
	this.maxNbEval = maxEval; 

	randomInit = new RandomInit(random, eval.size());

	walk = new double[maxEval];
    }

    // the search
    public void run() {
	// initialization
	solution = new Solution();

	randomInit.init(solution);
	eval.apply(solution);
	walk[0] = solution.fitness();
	nbEval = 1;

	// bit to flip
	int i;

	while(nbEval < maxNbEval) {
	    // flip one bit at random
	    i = random.nextInt(eval.size());
	    solution.bitString[i] = ! solution.bitString[i];

	    // evaluation
	    eval.apply(solution);

	    // save
	    walk[nbEval] = solution.fitness();
	    nbEval++;
	}
    }

    
    // print the walk
    public String toString() {
	String r = "";
	for(int i = 0; i < this.maxNbEval; i++)
	    r += walk[i] + "\n" ;
	return r;
    }

    // maximum number of evaluations
    private int maxNbEval ;

    // save the walk
    private double [] walk;

    // random generator
    private Random random;

    // initialization method
    private RandomInit randomInit;
}

