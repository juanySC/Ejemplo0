/*Un programa que permita sumar el número de elementos positivos y el de
 negativos de un vector de 50 elementos, los números deben ser aleatorios. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 50
//declaro mis variables globales
int numero, suma = 0;

int main() {
	//inicializo que los numeros sean aleatorios
	srand(unsigned(time(NULL)));
	
	
	printf("Este programa muestra 50 numeros aleatorios entre -25 y 25\n");
	printf("así también la suma de los mismos: \n");
	for (int i = 0; i < NUM; i++) {
		// 51= me genera un numero del 0 al 50
		// -25 = hace que mi rango este entre [-25,25]
		numero = rand() % 51 - 25;
		printf("\n %1s %2d %3s \t","{",i,"}");
		printf("%d \n", numero);
		
		//suma
		suma = suma + numero;
	}
	
	printf("\nLa suma de los números aleatorios es: %d", suma);
	return 0;
}
