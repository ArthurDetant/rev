Description des données
Date   : 13/11/2018
Auteur : Sébastien Verel
----------------------------

*** hc_3.dat:
Résultat du hill-climber first-improvement pour 1000 exécutions par sous-espace

id      : identifiant du sous-espace [0..59]
run     : identifiant de l'exécution du hill-climber [0..999]
fitness : performance du hill-climber
neval   : nombre d'évaluation pour atteindre fitness (10^6 au maximum)
nstep   : nombre de mouvement (voisin) accepté pour atteindre fitness


*** rnd_3.dat:
Résultat de l'échantillage aléatoire de chaque sous-espace. Taille de l'échantillon : 10^7 solutions aléatoires. Les performances obtenues (fitness) sont comprises entre 3 et 6.

id     : identifiant du sous-espace [0..59]
f3     : fréquence (nombre de solutions) de fitness 3
f4     : fréquence (nombre de solutions) de fitness 4
f5     : fréquence (nombre de solutions) de fitness 5
f6     : fréquence (nombre de solutions) de fitness 6
mu     : moyenne des fitness de l'échantillon
muplus : moyenne des fitness de l'échantillon strictement supérieure à 3