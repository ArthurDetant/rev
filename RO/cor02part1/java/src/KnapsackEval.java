/******************************************************
  Knapsack evaluation function:
  sum of profit minus a linear penalty function if necessary

  @param _solution the solution to evaluated
******************************************************/

import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class KnapsackEval extends Eval {
    // data from the problem instance
    protected int nbObject;
    protected int[] profits;
    protected int[] weights;
    protected int capacity;

    // weight of the penalty
    private double beta;

    /* 
       constructor
       becareful : any validation verication during the parsing of the file

       @param fileInstanceName name of the knapsack instance
     */
    KnapsackEval(String fileInstanceName) throws FileNotFoundException { 
      super(0);

      File file = new File(fileInstanceName);
      Scanner sc = new Scanner(file);
      
      // read the number of objects
      nbObject = sc.nextInt();
      this.setSize(nbObject);

      profits = new int[nbObject];
      weights = new int[nbObject];

      // read the profit of objects
      for(int i = 0; i < nbObject; i++)
	  profits[i] = sc.nextInt();

      // read the weight of objects
      for(int i = 0; i < nbObject; i++)
	  weights[i] = sc.nextInt();

      // read the maximum capacity of the sack
      capacity = sc.nextInt();

      // compute the constant beta
      beta = 0;
      for(int i = 0;  i < nbObject; i++)
	  if (weights[i] > 0)
	      if (beta < profits[i] / weights[i])
		  beta = profits[i] / weights[i];

      sc.close();
  }

  // evaluation function 
  public void apply(Solution solution) {
      // sum of profit
      int p = 0;
      // sum of weight
      int w = 0;

      for(int i = 0; i < solution.size(); i++)
	  if (solution.bitString[i]) {
	      p += profits[i];
	      w += weights[i];
	  }

      if (w <= capacity)
	  solution.fitness(p);
      else
	  solution.fitness(p - beta * (w - capacity));
  }
}

