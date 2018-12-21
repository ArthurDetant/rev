#include "Knapsack.hpp"

using namespace std;

Knapsack::Knapsack(std::string filename){
	std::ifstream is(filename);
	int tmp=0;
	n=0;
    is >> n;

	for(int i=0;i<n;i++){
		if(is>>tmp){
			_profits.push_back(tmp);
		}
	}
	for(int i=0;i<n;i++){
		if(is>>tmp){
			_poids.push_back(tmp);
		}
	}
	if(is>>tmp){
		_capacite=tmp;
	}


	double max = 0;

        for(int i=0; i<n ; i++)
        {
            if ( ((double)_profits[i] / (double)_poids[i]) > max )
            {
                max = (double)_profits[i] / (double)_poids[i];
            }
        }

	_beta = max;
}



void Knapsack::eval(Solution & s)
{
int profi =0;
int poi =0;
    for (int i = 0; i < n; i++)
    {
        if(s._vecbool[i] == 1)
        {
        profi = profi + _profits[i];
        poi = poi + _poids[i];
        }
    }
    if(poi <= _capacite)
    {
        s.fitness =  profi;
    }
    else
    {
        s.fitness =  (profi - (_beta*(poi-_capacite)));
    }


}



void Knapsack::print(){ 

for(int i=0;i<_profits.size();i++)
{
cout<<_profits[i]<<" ";
}
cout<<endl;
for(int i=0;i<_poids.size();i++)
{
cout<<_poids[i]<<" ";
}
cout<<endl;
cout<<"capacite :"<<_capacite<<endl;
cout<<"beta :"<<_beta<<endl;

	}

