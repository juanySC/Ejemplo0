/*Escribir  un  programa  que  genere  10  valores aleatorios  para  un  vector
  y  luego  muestre  la sumatoria   y   conteo   de   números   impares   y
 números pares.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <conio.h>
#define NUM 10

char continuar = 'n';

int main() {
	do{
		int numero = 0;
		int numPar = 0;
		int numImpar = 0;
		int suma = 0;
		
		//voy generando los numeros aleatorios
		srand(unsigned(time(NULL)));
		
		printf("\nEste programa muestra 10 numeros aleatorios y quienes son");
		printf("pares e impares");
		
		
		for (int i = 0; i < NUM; i++) {
			//genero numeros del 1 al 10
			numero = rand()% 10+ 1;
			printf("\n\n %1s %2d %3s \t","{",i,"}");
			printf("%5d ", numero);
			suma = suma + numero;
			
			//comparo la salida de los numeros
			if(numero%2 == 0){
				printf("\nEl número es par");
				numPar++;
			}else{
				printf("\nEl número es impar");
				numImpar++;
			}
			
		}
		
		//impresion de la suma, de la cantidad de numeros pares e impares
		printf("\n\nLa suma de los numeros generados es: %d", suma);
		printf("\nLa cantidad de números pares son: %d", numPar);
		printf("\nLa cantidad de números impares son: %d", numImpar);
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	
	return 0;
}
