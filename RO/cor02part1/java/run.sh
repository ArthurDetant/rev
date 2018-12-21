#!/bin/bash

# file name of the knapsack instance
fileName=ks_1000.dat

# nombre d'exécutions
nbRun=100

# number of evaluations
nbEvalList="10 50 100 500 1000 2000 5000 10000 50000 100000"

# Random search
echo random search

echo nbeval fitness > rs.csv
for n in ${nbEvalList}
do
    echo nbEval ${n}
    for((i=0; i < ${nbRun};i++))
    do
	echo -n $i' '
	java -cp bin Main ${fileName} ${n} ${i} >> rs.csv
    done
    echo
done
echo 


# Random walk
echo random walk of 1000 steps

echo fitness > rw.csv
java -cp bin MainRandomWalk ${fileName} 1000 0 >> rw.csv

