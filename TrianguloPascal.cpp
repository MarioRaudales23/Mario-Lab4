#include "TrianguloPascal.h"
#include <iostream>
#include <iomanip>

using namespace std;

TrianguloPascal::TrianguloPascal(int linea){
	lineas = linea;
}

int TrianguloPascal::factorial(int numero){
	int factorial = 1;
	for(int i = 1;i < numero;i++){
		factorial *= i;
	}
	return factorial;
}

int TrianguloPascal::combinar(int numerosuper,int numeroinfer){
	if(numeroinfer == 1){
		return numerosuper;
	}else{
		if(numerosuper == numeroinfer){
			return 1;
		}else{
			return	factorial(numerosuper)/(factorial(numeroinfer) * factorial((numerosuper - numeroinfer)));
		}	
	}
}

void TrianguloPascal::impresion(){
	for(int i = 0;i <= lineas;i++){
		for(int j = 0;j<= i;j++){
			if(combinar(i,j)%2 != 0){
				cout<<setw(lineas)<<combinar(i,j);
			}else{
				cout<<setw(lineas)<<combinar(i,j);
			}
		}
		cout<<endl;
	}
}
