/*Ejercicio 9: Dada la duración en minutos de una llamada calcular el costo,
 considerando lo siguiente:
a. Hasta tres minutos el costo es Q 0.50
b. Por encima de tres minutos es Q 0.50 más Q 0.1*cada minuto adicional a 
los tres primeros*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int minutoLlamada = 0;
float totalLlamada = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa el costo de la llamada\n");
		printf("Ingrese la duracion de la llamada en minutos \n");
		scanf("%d",&minutoLlamada);
		
		//hasta tres minutos
		if(minutoLlamada <= 3){
			//tarifa
			totalLlamada = minutoLlamada * 0.5;
			printf("El total en Q de llamada es: %.2f", totalLlamada);
		} else if(minutoLlamada > 3){
			//tarifa
			totalLlamada = (minutoLlamada * 0.5)+0.1;
			printf("El total en Q de la llamada es: %.2f", totalLlamada);
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
