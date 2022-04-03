#include <vector>
#include <iostream>
#include <algorithm>
#include "auxs.cpp"
#include <cmath>

using namespace std;

int maxBeneficio_FB(int &w, const vector< pair <int,int> > &S);
int iesimoBeneficio(double n, int &w, const vector< pair <int,int> > &S);

														 // S = < (tam0, ben0), ... , (tam_n,ben_n) >		
int maxBeneficio_FB(int &w, const vector< pair <int,int> > &S){   //resolución del problema de la mochila usando Fuerza Bruta   
	int n = S.size();
	int res = 0;
	double hasta = pow(2.0, n);			//  2^n 
	for (double i = 0; i < hasta; ++i){ 		
		int benef = iesimoBeneficio(i, w, S); 	// si excede w da 0.  w y S se pasan por referencia
		if(benef>res) res = benef;
	}
	return res;
}

int iesimoBeneficio(double n, int &w, const vector< pair <int,int> > &S){
	int benTotal = 0; //beneficio total
	int tamTotal = 0; //tamaño total
	int i = 0;
	while(n>0){
		if (n / 2 - floor(n / 2) != 0){   // n mod 2 == 1 , versión double-friendly
 			benTotal += ben(S[i]);
			tamTotal += tam(S[i]);
			if (tamTotal > w) return 0; 	
		} 
		i++;
		n = floor(n / 2); 
	}
	return benTotal;
}
