/*Problema 1: Se  necesita  mostrar  en pantalla los números de 1 a 10 [Usar ciclo while]*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero = 1;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
{
	do{
	//PARTE 4: INICIO DEL CODIDO
	printf("Este programa imprime los números del 1 al 10 \n");
	while(numero <= 10){//PARTE 5: INSTRUCCIONES O CODIGO
		printf("\n%d",numero);
		//contador para que se incremente
		numero++;
	}
	
		
	//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
