/*Se tienen tres vectores enteros, se deben llenar de valores aleatorios, el primer
 vector deberá de llenarse con los números comprendidos entre el rango del 1 al 10, 
el segundo vector deberá de llenarse con los números comprendidos entre el rango 
del 20 al 30, el tercer vector tendrá la resta de los números del primer vector
por el segundo vector. Luego mostrará las siguientes estadísticas sobre los números 
contenidos en el tercer vector:
1. Cuantos Positivos
2. Cuantos Negativos
3. Cuantos Pares
4. Cuantos Impares*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#define TAM 10
#define RANGO1_MIN 1
#define RANGO1_MAX 10
#define RANGO2_MIN 20
#define RANGO2_MAX 30
char continuar = 'n';

// va dejando numeros aleatorios en cada uno de los vectores
void llenarVectores(int vector1[], int vector2[], int vector3[], int tamanio) {
	for (int i = 0; i < tamanio; i++) {
		vector1[i] = rand() % (RANGO1_MAX - RANGO1_MIN + 1) + RANGO1_MIN;
		vector2[i] = rand() % (RANGO2_MAX - RANGO2_MIN + 1) + RANGO2_MIN;
		//hago la diferencia entre vectores para el resultado del tercero
		vector3[i] = vector1[i] - vector2[i];
	}
}

// Imprime los vectores
void imprimirVectores(int v1[], int v2[], int v3[], int tam) {
	printf("\n%-10s %-10s %-10s\n", "V1", "V2", "V1 - V2");
	for (int i = 0; i < tam; i++) {
		printf("%-10d %-10d %-10d\n", v1[i], v2[i], v3[i]);
	}
}

// hago comparacion para ver en 	que clasificacion caen
void analizarVector(int vector[], int tam) {
	int positivos = 0, negativos = 0, pares = 0, impares = 0;
	
	for (int i = 0; i < tam; i++) {
		if (vector[i] > 0) positivos++;
		if (vector[i] < 0) negativos++;
		//si son divisibles dentro de 2 son pares
		if (vector[i] % 2 == 0) pares++;
		else impares++;
	}
	
	printf("\nPositivos: %d\n", positivos);
	printf("Negativos: %d\n", negativos);
	printf("Pares:     %d\n", pares);
	printf("Impares:   %d\n", impares);
}

int main() {
	do{		//variables locales
		int vector1[TAM], vector2[TAM], vector3[TAM];
	
		srand((unsigned)time(NULL)); // para que salgan aleatorios los numeros
	
		// Llenarlos vectores
		llenarVectores(vector1, vector2, vector3, TAM);
		imprimirVectores(vector1, vector2, vector3, TAM);
		analizarVector(vector3, TAM);
	
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	
	return 0;
}

