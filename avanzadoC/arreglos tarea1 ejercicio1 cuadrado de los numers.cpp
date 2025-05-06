/*Un programa que tenga 100 espacios y en los mismos ubicar el cuadrado de los
 cien primeros números  enteros  y  a  continuación  escribir  la sumatoria del 
contenido del vector*/
#include <stdio.h>
#include <conio.h>
#define NUM 100

char continuar = 'n';

int main() {
	do{
		int cuadrados[NUM];
		int suma = 0;
		
		printf("Este programa muestra el cuadrado del 1 al 100");
		for (int i = 0; i < NUM; i++) {
			//para que no comienze de 0 le sumo +1
			cuadrados[i] = (i + 1) * (i + 1);
			printf("\n %1s %2d %3s \t","{",i,"}");
			printf("%5d ", cuadrados[i]);
			suma = suma + cuadrados[i];
		}
		
		//muestro la sumatoria
		printf("\n \nLa suma del 1 al 100 es: %d", suma);
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	} while(continuar == 's');

	
	return 0;
}
