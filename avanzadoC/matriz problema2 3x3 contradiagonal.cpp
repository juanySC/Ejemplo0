/*Problema 2:  Escribir un programa que gestione una matriz de números enteros 
con 3 filas y 3 columnas, llenar con valores aleatorios de 21 a 30, generar como
 salida la suma de los valores contenidos en la contradiagonal de la matriz.*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define FILA 3
#define COLUMNA 3


int matrix[FILA][COLUMNA];
int filas = 0, columnas = 0;
char continuar = 'n';

void valoresAleatorios(){
	//asignar valores aleatorios
	srand(unsigned(time(NULL)));
	//reiniciar las variables
	//valores aleatorios
	for(filas = 0; filas<FILA; filas++){
		for(columnas = 0; columnas<COLUMNA; columnas++){
			//genere de 21 a 30, por eso sumo 21 para no empezar en 0
			matrix[filas][columnas] = 21 + rand()%10 ;
		}
	}
}

void impresionDatos(){
	printf("\nContenido actual: \n");
	//imprimo el contenido
	for(filas = 0; filas<FILA; filas++){
		for(columnas = 0; columnas<COLUMNA; columnas++){
			//imprimo los valores de la matriz
			printf("%5d", matrix[filas][columnas]);
			
		}
		printf("\n");
	}
}	

int sumaContradiagonal(){
	int suma = 0;
	/*matrix[0][0];
	matrix[1][1];
	matrix[2][0];	*/ 
	for(filas = 0; filas<3; filas++){ 
		suma += matrix[filas][2-filas];
	}
	return(suma);
}	


int main() {
	do{
		valoresAleatorios();
		impresionDatos();
		printf("\nLa suma de la contradiagonal es = %5d", sumaContradiagonal());
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}

