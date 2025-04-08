/*Ejercicio 11:Escribir un programa en lenguaje C que determine si un a�o es 
bisiesto. Un a�o es bisiesto si es m�ltiplo de 4 (por ejemplo 1984). Los a�os
 m�ltiplos de 100 no son bisiestos, salvo si ellos son tambi�n m�ltiplos de 400
 (2000 es bisiesto, pero; 1800 no lo es)*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int anioBi = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
{
	int anioBisiesto = 0; //bandera marca falso
	//PARTE 4: INICIO DEL CODIDO
	
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("\nEste programa devuelve si un a�o es bisiesto \n");
		printf("Ingrese el a�o: \n");
		scanf("%d",&anioBi);
		
		switch (1) { 
		case 1:	
			if ((anioBi % 4 == 0 && anioBi % 100 != 0) || (anioBi % 400 == 0)) {
				anioBisiesto = 1; // mi bandera se activa
			}
			
			break;
		}
		
		if(anioBisiesto){
			printf("\nEs un a�o bisiesto");
		} else {
			printf("\nEl a�o no es bisiesto");
		}
		//si desea volver a meter ecuacion cuadratica
		printf("\nDesea continuar con otro a�o s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
