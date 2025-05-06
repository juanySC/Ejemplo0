#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define COLUMA 3
#define FILA 3

//prototipo de dunciones
void imprimeMatrix();
void asignaAleatorios();
int sumaMatrix();

int filas = 0, columnas = 0;
int sumaPrincipal = 0, sumaSecundaria= 0;

int matrix[3][3];
char continuar = 'n';

int main() {
	do {
		
		//lamando funcones
		imprimeMatrix();
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
		for (columnas = 0; columnas < COLUMA; columnas++) {
			printf("%10d", matrix[filas][columnas]);
		}
		printf("\n");
	}
}
	
void asignaAleatorios(){
	srand((unsigned)time(NULL));
	for (filas = 0; filas < FILA; filas++) {
		for (columnas = 0; columnas < COLUMA; columnas++) {
			matrix[filas][columnas] = 25 + rand() % 6;
		}
	}
}

int sumaMatrix(){
	for (filas = 0; filas < FILA; filas++) {
		sumaPrincipal += matrix[filas][filas];
		sumaSecundaria += matrix[filas][2 - filas];
	}
	return(sumaSecundaria);
}
