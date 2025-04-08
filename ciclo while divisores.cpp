/*Ejercicio 4: Leer un número N y mostrar como salida la cantidad de divisores
que tiene dicho número, incluya la unidad y el mismo número (N)*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero= 0;
int divisores = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese por favor un valor\n");
		scanf("%d",&numero);
		
		//ciclo descendente
		int contador = 1;
		
		
		while(contador <= numero){
			if(numero %contador == 0){
				divisores++;
			}
			contador++;
		}
		
		printf("\n %s %d ","El factorial número dado es: ",numero);
		printf("\n %s %d  %s","tiene: ",divisores,"divisores");
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
