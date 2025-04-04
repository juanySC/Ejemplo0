/*Problema 3:Se requiere mostrar los números de 1 a 25 en pantalla, y 
luego mostrar la sumatoria  de  todos  los  números mostrados en pantalla.  */

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero = 1;
int suma = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
{
	do{
		//PARTE 4: INICIO DEL CODIDO
		printf("Este programa imprime los números del 1al 25 y la sumatoria \n");
		while(numero <= 25){//PARTE 5: INSTRUCCIONES O CODIGO
			printf("\n%d",numero);
			//contador para que se incremente
			suma = suma +numero;
			numero++;
		}
		
		printf("La suma total de 1 a 25 es: %d", suma);
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
