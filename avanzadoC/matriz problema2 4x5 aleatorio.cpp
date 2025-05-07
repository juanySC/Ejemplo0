/*Escribir un programa que gestione una matriz de números enteros con 4 filas y
 5 columnas, llenar con valores aleatorios 1 a 100, generar como salida la suma 
todos los valores contenidos en la matriz. Mostrar los datos contenidos en la
 matriz en formato tabla. [Filas] [Columnas].*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define COLUMNA 5
#define FILA 4

int matrix[FILA][COLUMNA];
int filas = 0;
int columnas = 0;

char continuar = 'n';

void valorAleatorio(){
	//asignar valores aleatorios
	srand(unsigned(time(NULL)));
	//reiniciar las variables
	//valores aleatorios
	for(filas = 0; filas<FILA; filas++){
		for(columnas = 0; columnas<COLUMNA; columnas++){
			//genere numeros de 1 a 100, por eso sumo +1
			matrix[filas][columnas] = 1 + rand()%100 ;
		}
	}
}
	
void impresionDatos(){
	printf("\nContenido actual: \n");
	//imprimo el contenido
	for(filas = 0; filas<FILA; filas++){
		for(columnas = 0; columnas<COLUMNA; columnas++){
			//genere de 25 a 30, son 5 valores
			printf("%5d", matrix[filas][columnas]);
		}
		printf("\n");
	}
	
}	
	
int sumaMatrix(){
	//lo declaro aqui para que no acumule la suma anterior y se reinicie cada
	//vez que realize la operacion
	int suma = 0;
	
	for(filas = 0; filas<FILA; filas++){
		for(columnas = 0; columnas<COLUMNA; columnas++){
			//la suma solo la genero una vez porque sino sumaria dos veces si 
			//lo añado al ciclo de filas
			suma += matrix[filas][columnas];
		}
	}
	//tengo que retornar un valor de la suma
	return(suma);
}


int main() {
	do{
		//llamando funciones
		valorAleatorio();
		impresionDatos();
		printf("\nLa suma de total de todas la matriz es: %5d", sumaMatrix());
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}
