#include "Solution.hpp"
#include "Knapsack.hpp"
#include <fstream>
#include <vector>
#include <string> 

using namespace std;

int main(int argc, char * argv[]) {
  
  Knapsack k(argv[1]);
  k.print();

  Solution s;
  s._vecbool.resize(k.n);

double moyenne =0;
double moy = 0;
double plus_grand = 0;
for (int m=0 ; m<30; m++){
for (int i=0; i<100 ; i++){
	for (int j=0; j<k.n; j++){
  s._vecbool[j]=rand()%2; 
  k.eval(s); 
}
   moyenne += s.fitness ;

}
moyenne = moyenne / 100;

 cout <<"moyenne fitness n" <<m+1<<": "<< moyenne<<endl;
 moy += moyenne;

}
moy = moy/30;
 cout <<"moyenne des moyennes: "<<moy<<endl;


  return 0;
}
