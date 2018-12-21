/**
 * 
 */
import java.io.*;
import java.util.Random;
import java.io.FileNotFoundException;


/**
 * @author verel
 *
 */
public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) throws FileNotFoundException {
	if (args.length == 3) {
	    String instanceFileName = args[0];

	    // maximum number of evaluation
	    int maxEval = Integer.parseInt(args[1]);

	    // initialization of the random numbers sequence
	    Random random = new Random(Integer.parseInt(args[2]));
    
	    // Evaluation function
	    //OneMax eval = new OneMax(n);
	    KnapsackEval eval = new KnapsackEval(instanceFileName);

	    // different possible search heuristics
	    Search search = null;

	    // random search
	    search = new RandomSearch(random, eval, maxEval);
	    
	    // perform the search
	    search.run();

	    // print the number of evaluations
	    System.out.println(search.nbEval() + " " + search.solution().fitness());

	} else {
	    System.out.println("3 arguments attendus : ");
	    System.out.println("nom du fichier d'instance du sac a dos, nombre d'evaluation et la graine du generateur de nombres pseudo-aleatoires");
	}
    }


}
