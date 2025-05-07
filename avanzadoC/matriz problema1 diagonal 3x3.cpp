/*Escribir un programa que gestione la matriz de números enteros  de 3 filas y 
3 columnas, llenar con valores aleatorios del 21 al 30, generar como salida la
 suma de los valores contenidos en la contradiagonal de la matriz. */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define COLUMNA 3
#define FILA 3

//prototipo de dunciones
void imprimeMatrix();
void asignaAleatorios();
int sumaMatrix();

int filas = 0, columnas = 0;
int matrix[FILA][COLUMNA];
char continuar = 'n';

int main() {
	do {
		
		asignaAleatorios();
		imprimeMatrix();
		//sumaMatrix();
		
		printf("La suma de las diagonal es: %5d", sumaMatrix());
		
		
		printf("\n\n¿Desea imprimir de nuevo? (s/n): ");
		continuar = getch(); // Espera una tecla sin presionar Enter
		printf("\n");
		
	} while (continuar == 's');
	
	return 0;
}

//1. tipo de dato retornado
//2. nombre
//3. Parametro de entrada
// Crear funcion: 1 2 3

void imprimeMatrix(){
	// Mostrar la matriz
	printf("\nContenido de la matriz:\n");
	for (filas = 0; filas < FILA; filas++) {
		for (columnas = 0; columnas < COLUMNA; columnas++) {
			printf("%10d", matrix[filas][columnas]);
		}
		printf("\n");
	}
}
	
	void asignaAleatorios(){
		srand((unsigned)time(NULL));
		for (filas = 0; filas < FILA; filas++) {
			for (columnas = 0; columnas < COLUMNA; columnas++) {
				matrix[filas][columnas] = 21 + rand() % 10;
			}
		}
	}
		
	int sumaMatrix(){
		int suma = 0;
		for (filas = 0; filas < FILA; filas++) {
			suma += matrix[filas][filas];
		}
		return(suma);
	}
