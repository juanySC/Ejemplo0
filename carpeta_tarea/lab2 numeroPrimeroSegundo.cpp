/*Escribir un programa que lea dos números, nombrados como primero y
segundo, y luego indique como salida cuál de los dos (primero o segundo) es el
mayor de los dos números ingresados.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numeroPrimero = 0;
int numeroSegundo = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("\nEste programa calcula el mayor de dos numeros \n");
		printf("Ingrese el primer numero a evaluar: \n");
		scanf("%d",&numeroPrimero);
		printf("Ingrese el segundo numero a evaluar: \n");
		scanf("%d", &numeroSegundo);
		
		//hago mi comparacion
		if(numeroPrimero > numeroSegundo ){
			printf("El primer numero es %d mayor que %d \n", numeroPrimero,numeroSegundo);
			return 0;
		} else if(numeroSegundo > numeroPrimero){
			printf("El segundo numero es %d mayor que %d \n",numeroSegundo,numeroPrimero);
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
		
	}while(continuar == 's');//si continua dentro del ciclo
	//PARTE 6:FIN DEL CODIGO 
}
