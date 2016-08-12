#include "TrianguloPascal.h"
#include <iostream>
#include <iomanip>

using namespace std;

TrianguloPascal::TrianguloPascal(int linea){
	lineas = linea;
}

int TrianguloPascal::factorial(int numero){
	int factorial = 1;
	for(int i = 1;i <=numero;i++){
		factorial *= i;
	}
	return factorial;
}

int TrianguloPascal::combinar(int numerosuper,int numeroinfer){
	int combinar;
			combinar = factorial(numerosuper)/(factorial(numeroinfer) * factorial((numerosuper - numeroinfer)));
	return combinar;
}

void TrianguloPascal::impresion(){
	int x = lineas * 2;
	for(int i = 0;i <= lineas;i++,x-=2){
		for(int s = 0;s<=x;s++){
			cout<<" ";	
		}
		for(int j = 0;j<= i;j++){
			if(combinar(i,j) %2 == 0){
				cout<<setw(4)<<"o";
			}else{
				cout<<setw(4)<<".";
			}
		}
		cout<<endl;
	}
}
