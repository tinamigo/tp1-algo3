#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "auxs.cpp"
#include "fuerzaBruta.cpp"
#include "meetInTheMiddle.cpp"
#include "backtracking.cpp"
#include "progDinamica.cpp"
#include <random>


using namespace std;

int main(){
	vector< pair<int,int> > S;
	int n;
	cin >> n;
	int w ; cin >> w;

	for (int i = 0; i < n; ++i){
		pair <int,int> p;
		cin >> p.first;
		
		cin >> p.second;
		S.push_back(p);
	}

	int FB, MITM, BT, PD;
	FB = maxBeneficio_FB(w, S);
	MITM = maxBeneficio_MitM(w, S);
	BT = maxBeneficio_BT(0, w, S, sumaTotal(S));
	PD = maxBeneficio_PD(0, w, S);

	if (FB != MITM or FB != BT or FB != PD){
		cout << "error";
		return 1;
	}

	cout << FB;

	return 0;
}


/*
int main(){
	int BT;
	double BTtime = 0.0;

	vector< pair<int,int> > S;

	cout << "N,Tiempo" << endl;

	srand(8);
		for (int i = 1; i < 11; i++){
			BTtime = 0.0;
	  		for (int k = 0; k < 10000; ++k){
	  			int w = 1;
				for (int h = 0; h < i; ++h){     
					pair <int,int> p;
					p.first = 0;
					p.second = rand() % 100 ;
					S.push_back(p);
				}


				auto BTInit = chrono::steady_clock::now();
				BT = maxBeneficio_BT(0, w, S, sumaTotal(S));
				auto BTEnd = chrono::steady_clock::now(); 
				BTtime += chrono::duration<double, milli>(BTEnd - BTInit).count();

				for (int j = 0; j < i; ++j){
					S.pop_back();
				}
				
			}

			BTtime /= 10000;

			cout << i << "," << BTtime << endl;

		}

		for (int i = 11; i < 31; i++){
			BTtime = 0.0;
	  		for (int k = 0; k < 30; ++k){
				int w = 1 ;
				for (int h = 0; h < i; ++h){     
					pair <int,int> p;
					p.first = 0;
					p.second = rand() % 100 ;
					S.push_back(p);
				}

				auto BTInit = chrono::steady_clock::now();
				BT = maxBeneficio_BT(0, w, S, sumaTotal(S));
				auto BTEnd = chrono::steady_clock::now(); 
				BTtime += chrono::duration<double, milli>(BTEnd - BTInit).count();

				for (int j = 0; j < i; ++j){
					S.pop_back();
				}
				
			}

			BTtime /= 30;

			cout << i << "," << BTtime << endl;

		}
	return 0;
}
*/