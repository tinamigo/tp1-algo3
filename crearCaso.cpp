#include <iostream>

int crearCaso () {
  ofstream myfile;
  myfile.open ("casos.txt");
  int n = rand() % 10000;
  int w = rand() % 200;
  myfile << n << w;  
  for (int i = 0; i < n; ++i){
  		int ben = rand() % 5000;
  		int tam = rand() % 300;
  		myfile << "\n" << ben << tam;
  }
  myfile.close();
  return 0;
}