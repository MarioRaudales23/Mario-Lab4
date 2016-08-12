#include <iostream>
#include "TrianguloPascal.h"
#include <iomanip>
using namespace std;

void impresion(int**,int,int);
void polinomio();
	
int main(){
	int menu,numero;
	char resp;
	do{
		cout<<"Opcion 1:Polinomios\nOpcion 2: Triangulo Pascal\nDigite su eleccion: ";
		cin>>menu;
		switch(menu){
			case 1:{
				cout<<"Ingrese el numero de lineas: ";
				cin>>numero;
				TrianguloPascal forma(numero);
				forma.impresion();
				break;
				}
			case 2:
				polinomio();
				break;
			default:
				cout<<"Opcion no valida";
		}
		cout<<"Desea Continuar[s/n]: ";
		cin>>resp;
	}while(resp == 's'||resp == 'S');
	return 0;
}

void polinomio(){
	int grado,asignar,numeroevalu,cont = 0;
	cout<<"Ingrese el grado del polinomio";
	cin>>grado;
	int** matriz = new int*[3];
	for(int i = 0;i<grado+1;i++){
		matriz[i] = new int[grado+1];
	}
	for(int i = grado;i>=0;i--){
		cout<<"Ingrese el polinomio de grado x^"<<i;
		cin>>asignar;
		matriz[0][cont] = asignar;
		cont++;
	}
	for(int i = 0;i<3;i++){
		if(i == 0){
			matriz[1][0] = matriz[0][0];
			matriz[2][0] = matriz[0][0];
			impresion(matriz,numeroevalu,grado);
		}else{
			for(int j = 1;j<grado+1;i++){
				matriz[1][j] =	matriz[2][j-1] * numeroevalu;
				matriz[2][j] =	matriz[1][j] + matriz[0][j];
				impresion(matriz,numeroevalu,grado);
			}
		}
		
	}
	for(int i = 0;i<3;i++){
		delete[] matriz[i];
	}
	delete[] matriz;
}

void impresion(int** matriz,int divisor,int grado){
	cout<<setfill('-')<<setw(20);
	cout<<endl;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j<grado+1;j++){
			if(i == 0){
				if(j == grado){
					cout<<setw(4)<<matriz[i][j]<<setw(4)<<"|";
				}else{
					cout<<setw(4)<<matriz[i][j];
				}
			}else{
				cout<<setw(4)<<matriz[i][j];
			}	
		}
		cout<<endl;
	}
}
