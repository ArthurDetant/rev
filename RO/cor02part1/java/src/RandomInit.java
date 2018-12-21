import java.util.Random;

public class RandomInit extends Init {
    public RandomInit(Random random, int n) {
	this.random = random;
	this.size = n;
    }

    public void init(Solution solution) {
	if (solution.size() != this.size) {
	    solution.bitString = new boolean[size];
	}

	for(int i = 0; i < size; i++) {
	    solution.bitString[i] = random.nextBoolean();
	}
    }

    private int size ;
    private Random random;
}
