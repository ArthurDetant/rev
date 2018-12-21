#include "Knapsack.hpp"

Knapsack::Knapsack()
{
	string mon_fichier = "../ks_5.dat";
	ifstream fichier(mon_fichier.c_str(), ios::in);
		
	if(fichier) {
        fichier >> items;
		
		int w[items]; // poids des objets
		int p[items]; // valeur des objets
		for(int i=0; i<items; i++) {
			fichier >> w[i];
		}
		for(int i=0; i<items; i++) {
			fichier >> p[i];
		}
		
		fichier >> capacity;
		
		fichier.close();
	}
}

void Knapsack::eval(Solution &s) {
	int sommeW = 0;
	int sommeP = 0;
	for (int i=0; i<items; i++) {
			sommeW = sommeW + w[i] * s.x[i];
			sommeP = sommeP + p[i] * s.x[i];
	}
	if (sommeW <= capacity) {
		cout << sommeW << endl;
	}
	else {
		int max=0;
		float rap;
		for (int i=0; i<items; i++) {
			if (p[i] * s.x[i){
				rap = p[i] / w[i]
				if 
		}
		sommeW = sommeW - 
		
		
	
}
