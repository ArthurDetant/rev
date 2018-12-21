/******************************************************
 * Abstract class for the computation of bit string evaluation
 */
abstract public class Eval {
    /** constructor
     * 
     * @param _n problem size, length of the bit string
     */
    Eval(int _n) {
	this.pbSize = _n ; 
    }

    // return the size of the problem
    public int size() {
	return this.pbSize;
    }

    // set the size of the problem
    public void setSize(int _n) {
	this.pbSize = _n;
    }

    // evaluation function to be defined
    abstract public void apply(Solution _solution) ;

    // bit string length
    protected int pbSize;
};

