Pour compiler :

g++ -c -O3 main.cpp -I.
g++ -o main main.o

g++ -c -O3 mainRandomWalk.cpp -I.
g++ -o mainRandomWalk mainRandomWalk.o



Pour executer :
./main 
donne le détail des arguments

./main ks_1000.dat 1000 12
exécute une random search sur l'instance "ks_1000.dat" avec un nombre maximum d'évaluations égale à 1000, et une graine aléatoire de 12


run.sh lance les expériences pour mesurer les performances de la recherche aléatoire, et avoir le profil du "paysage" du problème avec une marche aléatoire.
Ensuite, les statistiques peuvent être calculée à l'aide d'un logiciel (tableur, R, etc.) en ouvrant les fichiers csv. Voir le script traitement.R.



Queques informations sur le code :

* solution.h décrit une solution (classe Solution)
Solution est un vecteur de boolean
Le champ fitness correspond à la qualité de la solution calculée par la fonction d'évaluation

* eval.h décrit une fonction d'évaluation (classe Eval)
La méthode qui redéfinit l'operator () exécute le calcul de la fonction d'évaluation pour la solution donnée
pbSize corrspond à la longueur de la chaine de bits du problème

La classe OneMax dérive de la classe Eval et calcule le nombre de bits vrai.
La classe KnapsackEval dérive de la classe Eval et calcule la fonciton d'évaluation pour le problème du sac à dos.

* search.h décrit les heuristiques de recherche
Search est la classe racine qui décrit une méthode de recherche.
Les champs de cette classe sont: la fonction d'évaluation, la solution courante, et le nombre d'évaluations.

La méthode qui redéfinit l'operator () exécute la recherche.

Les RandomSearch, RandomWalk, HillCliming, FirstImprovement et FirstImprovementWithoutReplacement dérivent de cette classe.

* main.cpp contient la fonction principale qui permet d'exécuter l'une des recherches.

* mainRandomWalk.cpp contient la fonction principale qui permet d'exécuter une marche aléatoire


