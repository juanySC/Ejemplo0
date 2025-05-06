#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define COLUMA 11
#define FILA 11

int matrix[3][3];
char continuar = 'n';

int main() {
	do {
		int filas, columnas;
		int sumaPrincipal = 0, sumaSecundaria = 0;
		
		// Generar números aleatorios
		srand((unsigned)time(NULL));
		for (filas = 0; filas < FILA; filas++) {
			for (columnas = 0; columnas < COLUMA; columnas++) {
				matrix[filas][columnas] = 25 + rand() % 6;
			}
		}
		
		// Mostrar la matriz
		printf("\nContenido de la matriz:\n");
		for (filas = 0; filas < FILA; filas++) {
			for (columnas = 0; columnas < COLUMA; columnas++) {
				printf("%5d", matrix[filas][columnas]);
			}
			printf("\n");
		}
		
		// Calcular suma de diagonales
		for (filas = 0; filas < FILA; filas++) {
			sumaPrincipal += matrix[filas][filas];
			sumaSecundaria += matrix[filas][2 - filas];
		}
		
		printf("\nSuma de la diagonal principal: %d", sumaPrincipal);
		printf("\nSuma de la diagonal secundaria: %d", sumaSecundaria);
		
		printf("\n\n¿Desea imprimir de nuevo? (s/n): ");
		continuar = getch(); // Espera una tecla sin presionar Enter
		printf("\n");
		
	} while (continuar == 's');
	
	return 0;
}
