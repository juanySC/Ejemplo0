/*Ejercicio 3: Leer un número N y el programa debe devolver como salida el 
factorial del número ingresado.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero= 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese por favor un valor\n");
		scanf("%d",&numero);
		//facotrial = n! = 1*2*3...(n-1)n
		//5 = 120	5*4*3*2*1
		
		//ciclo descendente
		int contador = numero;
		int factorial = 1;
		
		while(contador >= 1){
			factorial = factorial*contador;			
			contador--;
		}
		
		printf("\nEl factorial número dado es: %d\n",factorial);
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
