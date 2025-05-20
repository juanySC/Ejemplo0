/*Escribir un programa, que gestione un arreglo bidimensional de 5x5, el mismo se
 debe llenar con números aleatorios entre 1 a 100, por medio de la implementación 
de funciones se solicita que se generen las siguientes estadísticas:
Número máximo contenido en la matriz
Número mínimo contenido en la matriz
Sumatoria del contenido en la matriz
Promedio del contenido de la matriz
Cantidad de números pares
Cantidad de números impares
Para cada dato solicitado, debe existir una función implementada, dado que los 
datos son calculados la función debe devolver el tipo de dato correcto para que 
sea invocado desde la función main. */
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define COLUMNA 5
#define FILA 5
#define DIVISOR 25 //para mi primedio ya que siempre sera de 5x5 o sea 25 elementos en total

int matrix[FILA][COLUMNA];
int filas = 0;
int columnas = 0;
int inicioRango = 1, finalRango = 100; // ranfo de mis numeros aleatorios
char continuar = 'n';

//tipo void porque no me devuelve algun valor
void valorAleatorio() {
	srand(unsigned(time(NULL))); //inicializo la semilla
	for (filas = 0; filas < FILA; filas++) {//recorro filas 
		for (columnas = 0; columnas < COLUMNA; columnas++) { //recorro columnas
			// 100 - 1 + 1  o sea comienza en 100 en rango final y el incio en 1
			matrix[filas][columnas] = rand() % (finalRango - inicioRango + 1) + inicioRango;
		}
	}
}

//no me devuelve un valor numerico o alguna operacion matematica
void impresionMatriz() {
	for (filas = 0; filas < FILA; filas++) {
		for (columnas = 0; columnas < COLUMNA; columnas++) {
			printf("%5d", matrix[filas][columnas]);
		}
		printf("\n"); //salto en cada 5 elementos para que baje y forma el cuadrado
	}
}

//int porque necesito que me retorne el valor entero que esoty evaliando
int valorMaximo() {
	int maximo = matrix[0][0]; //inicio para comparar mis numeros en la matriz
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matrix[i][j] > maximo) { 
				//si los datos dados los comparo con maixo y son mayor me devuelve que el maximo es la matriz en una ciera posicio n
				maximo = matrix[i][j];
			}
		}
	}
	return maximo; 
}

int valorMinimo() {
	int minimo = matrix[0][0]; //refernncia para comparar si mi numero es menor
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matrix[i][j] < minimo) {
				minimo = matrix[i][j];
			}
		}
	}
	return minimo;
}


int sumaTotal() {
	int suma = 0;
	//recorro filas y colmnas y cada posicion de estas las sumo
	for (int i = 0; i < FILA; i++) { //recorro todas las filas
		for (int j = 0; j < COLUMNA; j++) {//recorro todas las columnas
			suma += matrix[i][j]; //ira sumando cada numero en posicion [i][j]
		}
	}
	return suma;
}

//es tipo float porque puede que el promedio no se exacto
float promedioMatriz() {
	//hago la suma de toda la matriz
	int suma = 0;
	for (int i = 0; i < FILA; i++) { //recorro todas las filas
		for (int j = 0; j < COLUMNA; j++) {//recorro todas las columnas
			suma += matrix[i][j]; //ira sumando cada numero en posicion [i][j]
		}
	}
	
	//casteo por ser numero entero la suma y lo paso a flotante
	float promedio = (float)suma / (DIVISOR); 
	return promedio;
}

int numerosPares() {
	int pares = 0;
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matrix[i][j] % 2 == 0) { //basicamente verifica si el numero queda con residuo es impar y si es par queda en 0
				pares++; //entonces incremento mis numeros pares
			}
		}
	}
	return pares;
}

int numerosImpares() {
	int impar = 0;
	for (int i = 0; i < FILA; i++) {
		for (int j = 0; j < COLUMNA; j++) {
			if (matrix[i][j] % 2 != 0) { //me examina si su residuo es distinto de 0, es impar
				impar++; //incremento mi cantidad de numero impar encontrado en la matriz
			}
		}
	}
	return impar;
}

int main() {
	do {
		printf("\n\nEste programa genera una matriz de 5x5 con números aleatorios entre 1 y 100");
		printf("\nLa matriz es: \n");
		// llamo a mis funcoines void porque no me devuelven nada
		valorAleatorio();
		impresionMatriz();
		//llamo a mis funcines que retornar algun valor
		printf("\nEl valor maximo de toda la matriz es: %5d", valorMaximo());
		printf("\nEl valor minimo de toda la matriz es: %5d", valorMinimo());
		printf("\nLa suma total de todos los elementos es: %5d", sumaTotal());
		printf("\nEl promedio de todos los elementos es: %.2f", promedioMatriz());
		printf("\nCantidad de numeros pares: %5d", numerosPares());
		printf("\nCantidad de numeros impares: %5d", numerosImpares());
		
		printf("\n\nDesea generar una nueva matriz? s/n: ");
		continuar = getch();
		printf("\n");
		
	} while (continuar == 's');
	
	return 0;
}
