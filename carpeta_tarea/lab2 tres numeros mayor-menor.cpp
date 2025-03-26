/*Escribir un programa que permita leer tres números y luego indique cuál es el
mayor, y cuál es el menor de los tres.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int primerNumero = 0;
int segundoNumero = 0;
int tercerNumero = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("\nEste programa calcula el mayor de tres numeros \n");
		printf("Ingrese el primer numero a evaluar: \n");
		scanf("%d",&primerNumero);
		printf("Ingrese el segundo numero a evaluar: \n");
		scanf("%d", &segundoNumero);
		printf("Ingrese el tercer numero a evaluar: \n");
		scanf("%d", &tercerNumero);
		
		//Hago comparacion para hallar el numero mayor
		if((primerNumero > segundoNumero)&&(primerNumero > tercerNumero)){
			printf("\nEl número mayor de los tres es: \n");
			printf("El primer numero es %d  \t mayor que %d y %d \n", primerNumero, segundoNumero, tercerNumero);
		} else if((segundoNumero > tercerNumero)&&(segundoNumero>primerNumero)){
			printf("\nEl número mayor de los tres es: \n");
			printf("El segundo numero es %d  \t mayor que %d y %d \n", segundoNumero, primerNumero, tercerNumero);
		} else{
			printf("\nEl número mayor de los tres es: \n");
			printf("El tercer numero es %d  \t mayor que %d y %d \n",tercerNumero, primerNumero,segundoNumero);
		}
		
		//hago mi comparacion para hallar el numero menor
		if((primerNumero < segundoNumero)&&(primerNumero < tercerNumero)){
			printf("\nEl número menor de los tres es: \n");
			printf("El primer numero es %d  \t menor que %d y %d \n", primerNumero, segundoNumero, tercerNumero);
		} else if((segundoNumero < tercerNumero)&&(segundoNumero < primerNumero)){
			printf("\nEl número menor de los tres es: \n");
			printf("El segundo numero es %d  \t menor que %d y %d \n", segundoNumero, primerNumero, tercerNumero);
		} else{
			printf("\nEl número menor de los tres es: \n");
			printf("El tercer numero es %d  \t menor que %d y %d \n",tercerNumero, primerNumero,segundoNumero);
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
		
	}while(continuar == 's');//si continua dentro del ciclo
	//PARTE 6:FIN DEL CODIGO 
}
