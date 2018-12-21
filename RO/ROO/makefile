all: main.o Solution.o Knapsack.o Solution.o
	g++ main.o Solution.o Knapsack.o Solution.o -o Sac
    
main.o : main.cpp
	g++ main.cpp -o main.o
    
Solution.o: Solution.cpp Solution.hpp
	g++ Solution.cpp -o Solution.o
    
Knapsack.o: Knapsack.cpp Knapsack.hpp
	g++ Knapsack.cpp -o Knapsack.o
    
clean:
	rm -rf *.o Sac
