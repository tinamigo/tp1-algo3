#include <vector>
#include <iostream>
#include <algorithm>
#include "auxs.cpp"

using namespace std;

int maxBeneficio_PD(int i, int w, const vector< pair <int,int> > &S);
int maxBeneficio_PDaux(int i, int w, const vector< pair <int,int> > &S, matriz &beneficios);

int maxBeneficio_PD(int i, int w, const vector< pair <int,int> > &S){
	matriz beneficios;
	inicializarMatriz(S.size(), w, beneficios);

	return maxBeneficio_PDaux(i, w, S, beneficios);
}

int maxBeneficio_PDaux(int i, int w, const vector< pair <int,int> > &S, matriz &beneficios){
	if (i==S.size()-1) return ( tam(S[i])<=w? ben(S[i]) : 0 ) ;
	if (w < tam(S[i]) ){
		if (beneficios[i+1][w] == -1){
			beneficios[i+1][w] = maxBeneficio_PDaux(i+1, w, S, beneficios);
		}
		return beneficios[i+1][w];
	}
	if (beneficios[i+1][w-tam(S[i])] == -1){
		beneficios[i+1][w-tam(S[i])] = maxBeneficio_PDaux(i+1, w - tam(S[i]), S, beneficios);
	}
	if (beneficios[i+1][w] == -1){
		beneficios[i+1][w] = maxBeneficio_PDaux(i+1, w, S, beneficios);
	}

	return max( beneficios[i+1][w-tam(S[i])] + ben(S[i]), beneficios[i+1][w] );	
}
