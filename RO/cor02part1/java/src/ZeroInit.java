public class ZeroInit extends Init {
    public ZeroInit(int n) {
	size = n;
    }

    public void init(Solution solution) {
	if (solution.size() != size) {
	    solution.bitString = new boolean[size];
	}

	for(int i = 0; i < size; i++) 
	    solution.bitString[i] = false ;
    }

    private int size ;
}
