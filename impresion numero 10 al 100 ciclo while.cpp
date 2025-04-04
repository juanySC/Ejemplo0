/*Problema 2: Se necesita mostrar en pantalla los números de 10 a 100 
[usar ciclo while] */

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero = 10;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
{
	do{
		//PARTE 4: INICIO DEL CODIDO
		printf("Este programa imprime los números del 10 al 100 \n");
		while(numero <= 100){//PARTE 5: INSTRUCCIONES O CODIGO
			printf("\n%d",numero);
			//contador para que se incremente
			numero = numero +10;
		}
		
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
