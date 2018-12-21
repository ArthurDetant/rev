/**
   Classe pour representer une solution
   
   Chaine de bits auquel est ajoutee la valeur de la qualite (fitness)
*/
public class Solution {
    // bit string solution
    public boolean [] bitString;

    // quality of the solution
    double fitness;

    /***********************************
     * Constructor
     ***********************************/
    public Solution() {
	this.bitString = null;
	this.fitness = 0;
    }

    public Solution(Solution _s) {
	if (_s.bitString != null) {
	    this.bitString = new boolean[_s.bitString.length];
	    for(int i = 0; i < this.bitString.length; i++)
		this.bitString[i] = _s.bitString[i];
	} else {
	    this.bitString = null;
	}

	this.fitness = _s.fitness();
    }

    public Solution clone() {
	Solution solution = new Solution(this);
	return solution;
    }

    public void copy(Solution _s) {
	if (_s.bitString != null) {
	    if (this.bitString == null)
		this.bitString = new boolean[_s.bitString.length];
	    for(int i = 0; i < this.bitString.length; i++)
		this.bitString[i] = _s.bitString[i];
	} else {
	    this.bitString = null;
	}

	this.fitness = _s.fitness();
    }

    /**
     * set the fitness
     */
    public void fitness(double _fit) {
	this.fitness = _fit;
    }
    
    /**
     * get the fitness
     */
    public double fitness() { 
	return this.fitness; 
    }


    public int size() {
	if (this.bitString == null) {
	    return 0 ;
	} else {
	    return bitString.length;
	}
    }

    /**
     * print the solution
     */
    public String toString() {
	String s = this.fitness() + " " ;

	if (this.bitString == null) {
	    s += "0" ;
	} else {
	    s += this.bitString.length + " ";
	
	    for(int i = 0; i < this.bitString.length; i++)
		if (this.bitString[i])
		    s += "1" ;
		else
		    s += "0" ;
	}

	return s;
    }
}

