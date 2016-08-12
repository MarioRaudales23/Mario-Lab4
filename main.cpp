#include <iostream>
#include "TrianguloPascal.h"
#include <iomanip>
using namespace std;

void impresion(int***,int,int);
void polinomio();
	
int main(){
	int menu,numero;
	char resp;
	do{
		cout<<"Opcion 1:Trinangulo\nOpcion 2: Polinomio\nDigite su eleccion: ";
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
	int*** matriz = new int**[grado+1];
	for(int i = 0;i<grado+1;i++){
		matriz[i] = new int*[3];
		for(int j = 0;j < 3;j++){
			matriz[i][j] = new int[grado+1];
		}
	}
	for(int i = grado;i>=0;i--){
		cout<<"Ingrese el polinomio de grado x^"<<i<<": ";
		cin>>asignar;
		matriz[0][0][cont] = asignar;
		cont++;
	}
	cout<<"Ingrese el divisor: ";
	cin>>numeroevalu;
	for(int i= 0;i<grado;i++){
		cout<<"a";
		for(int j=0;j<3;j++){
			cout<<"b";
			if(j == 0){
				matriz[i][1][0] = matriz[i][0][0];
				matriz[i][2][0] = matriz[i][0][0];
			}else{
				for(int k = 1;k<=grado;k++){
					matriz[i][j][k] = matriz[i][j+1][k-1] * numeroevalu;
					matriz[i][j+1][k] = matriz[i][j-1][k] + matriz[i][j][k];
				}
			}
		}
	}
	for(int i = 0;i<grado;i++){
		for(int j = 0;j < 3;j++){
			delete[] matriz[i][j];
		}
		delete[] matriz[i];
	}
	delete[] matriz;
}

void impresion(int*** matriz,int divisor,int grado){
	for(int i = 0;i< grado;i++){
		for(int j = 0;j<3;j++ ){
			for(int k = 0;k<grado;k++){
				cout<<"["<<matriz[i][j][k]<<"]";
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
