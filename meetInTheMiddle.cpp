#include <vector>
#include <iostream>
#include <algorithm>
#include "auxs.cpp"
#include <cmath>

using namespace std;

int maxBeneficio_MitM(int &w, const vector< pair <int,int> > &S);
pair<int,int> iesimoPar(int n, int &w, const vector< pair <int,int> > &S, int lado);

int maxBeneficio_MitM(int &w, const vector< pair <int,int> > &S){
	if (S.size() == 1) return (tam(S[0]) <= w ? ben(S[0]) : 0 );
	vector<pair <int, int> > s2; //mitad "derecha" de S (los índices más grandes) (la que vota a macri) 
	int n = S.size();
	double hasta = pow(2.0,(n+1)/2);
	for (double i = 0.0; i < hasta ; ++i){            //generamos todos los subconjuntos de los elementos 
		pair<int, int> p = iesimoPar(i, w, S, derecha); //de la mitad derecha del vector O(2^(n/2))
		if (tam(p) <= w) s2.push_back(p);	// si excede la capacidad maxima sabemos que no puede ser solucion
	}										// porque no puede ser matcheado con algo de tam negativo => lo descartamos.

	sort(s2.begin(), s2.end(), comp);		// ordenamos el vector segun si algun par tiene tam menor que el otro, entonces ese es menor

	int ultTam = -1;						// y si tienen mismo tam el de mayor beneficio es el menor
	int ultBen = -1;
	vector< pair<int,int> > mejoresBeneficios;  //Creamos un vector que contiene, para cada intervalo de tamaños, el mejor beneficio. (intervalos cerrado-abierto)
	for (double i = 0.0; i < s2.size(); ++i){
		if(tam(s2[i]) > ultTam){
			if(ben(s2[i]) > ultBen) {
				mejoresBeneficios.push_back(s2[i]);
				ultBen = ben(s2[i]); 
			}
			ultTam = tam(s2[i]);
		}
	}

	pair<int,int> iPar;
	int mejorBeneficio = -1;
	hasta = pow(2.0, n/2);
	for (double i = 0.0; i < hasta /*lavistababy*/ ; ++i){	
		iPar = iesimoPar(i, w, S, izquierda);	// calculamos cada subconj de la primer mitad de nuestro vector de entrada
		int wRestante = w - tam(iPar);			// para cada uno buscamos su mejor beneficio correspondiente es decir... calculamos el maximo tam
		if(wRestante >= 0){
			int benCandidato = busqBinaria(wRestante, mejoresBeneficios) + ben(iPar); // con el cual se lo puede mezclar y obtenemos su beneficio,
			mejorBeneficio = max(mejorBeneficio, benCandidato);						  // luego lo sumamos con el beneficio del subconj actual y
		}
	}																				  // comparamos si es mayor o no con respecto al mayor beneficio ya calculado
	return mejorBeneficio;
}


//					n = subconj codif	lado = de que mitad del vector queremos empezar a armar subconjs; notar que si queremos verlo todo
pair<int,int> iesimoPar(int n, int &w, const vector< pair <int,int> > &S, int lado){ //podemos hacerlo desde la mitad izquierda sin problema
	int benTotal = 0; //beneficio total                                              
	int tamTotal = 0; //tamaño total
	int i = lado * S.size()/2;   // lado = 0 = izquierda / 1 = derecha (definidos arriba)
	while(n>0){					 // => si lado es izq empieza desde el principio del vector y si es der desde la mitad
		if (n % 2 == 1){
			benTotal += ben(S[i]);
			tamTotal += tam(S[i]);
			if (tamTotal > w) n = 0; 	
		} 
		i++;
		n /= 2; 
	}
	pair<int,int> p;
	p.first = tamTotal;			// S = < (tam0, ben0), ... , (tam_n,ben_n) >
	p.second = benTotal;
	return p;
}

