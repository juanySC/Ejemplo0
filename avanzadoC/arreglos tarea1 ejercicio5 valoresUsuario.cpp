/*Escribir un programa que permita generar 10 valores aleatorios para llenar un 
vector, los números de dicho vector deben estar en el rango que el usuario
 indique (se le debe pedir valor inicial y final del rango) y luego mostrar: 
a. Cantidad de números iguales al valor inicial 
b. Cantidad de números iguales al valor final*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define NUM 10

char continuar = 'n';

int main() {
	do{
		int num[NUM];
		int inicioRango;
		int finalRango;
		int compararInicio = 0, compararFin = 0;
		
		printf("\n\nEste programa muestra numeros aleatorios con el rango que proporcione");
		printf("\nIngrese el rango menor (donde inicia): ");
		scanf("%d", &inicioRango);
		printf("\nIngrese el rango mayor (donde termina): ");
		scanf("%d", &finalRango);
		
		//comparo mis rangos
		if(inicioRango>finalRango){
			printf("\nRango invalido");
		}
		
		//generando el rango
		srand(unsigned(time(NULL)));
		
		for (int i = 0; i < NUM; i++) {
			/*final - inicio =  rango restringo 
			inicioRango me sirve para iniciar donde indique el usuario
			agrego +1 para incluir el valor final del rango*/
			num[i] = rand()% (finalRango - inicioRango+1) + inicioRango;
			printf("\n %1s %2d %3s \t","{",i,"}");
			printf("%3d", num[i]);
			
			//comparo si alguno de los valor es igual al de inicio o final
			if(num[i] == inicioRango){
				compararInicio++;
			} else if( num[i] == finalRango){
				compararFin++;
			}
		}
		
		printf("\n\nLos números iguales al número inicial del rango son: %d", compararInicio);
		printf("\nLos números iguales al número final del rango son: %d", compararFin);
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	} while(continuar == 's');
	
	
	return 0;
}
