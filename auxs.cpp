#ifndef AUXS_CPP_
#define AUXS_CPP_

#include <vector>
#include <iostream>
#include <algorithm>

#define derecha 1
#define izquierda 0

using namespace std;

typedef vector< vector<int> >  matriz;

int tam(pair<int, int> p){return p.first;}
int ben(pair<int, int> p){return p.second;}


int sumaTotal(const vector< pair <int,int> > &S);
void inicializarMatriz(int n, int w, matriz &beneficios);
void printVecTup(const vector < pair <int,int> > &v);
bool comp (const pair<int,int> &a, const pair<int,int> &b);
int busqBinaria(const int &n, const vector<pair <int,int> > &v);



int sumaTotal(const vector< pair <int,int> > &S){
	int res = 0;
	for (int i = 0; i < S.size(); ++i){
		res += ben(S[i]);
	}
	return res;
}

void inicializarMatriz(int n, int w, matriz &M){
	for (int i = 0; i < n; ++i){
		vector <int> v;
		for (int j = 0; j <= w; ++j){
			v.push_back(-1);
		}
		M.push_back(v);
	}
}

void printVecTup(const vector < pair <int,int> > &v){ // funcion que recibe un vector de pares por referencia e imprime todos sus pares
	cout << "[ ";
	for (int i = 0; i < v.size(); ++i){
		cout << "(" << tam(v[i]) << "," << ben(v[i]) << ")" << " ";
	}
	cout << "]\n";
}

bool comp (const pair<int,int> &a, const pair<int,int> &b){  //Noción de orden para sortear mejores beneficios.  
	if(tam(a) == tam(b)){ return ben(a) > ben(b); }     	 //De menor a mayor tamaño como orden primario, 
	else{													 //de mayor a menor beneficio como orden secundario.	
		return tam(a) < tam(b);	
	} 	
}

//			t = maximo tam que no sobrepasa w
int busqBinaria(const int &t, const vector<pair <int,int> > &v){    //Busca en un vector v como mejoresBeneficios (pares  
																    //tamaño-beneficio) el beneficio correspondiente a n.
	int low = 0;
	int high = v.size()-1;
	if (tam(v[high]) <= t) return ben(v[high]);	// esta guarda esta para salvar el caso en que el valor buscado es mayor o igual 
	while(low < high-1){						// al mayor elemento del vector; ya que sin esta, como low < high < t => low < t
		int mid = (high + low) / 2;				// entonces siempre entra en el caso low = mid, nunca llega al valor en high y se termina 
		if(tam(v[mid]) < t ){					// devolviendo low (resultado erroneo)
			low = mid;							// solo hace falta fijarse esto en el primer caso... ya que en los siguientes, solo movemos high
		} else if (tam(v[mid]) > t) {			// a mid si mid > t (valor que buscamos) asegurandonos que high nunca tendra un resultado valido
			high = mid;							
		} else {
			return (ben(v[mid]));
		}

	}
	return (ben(v[low])); 
}

#endif