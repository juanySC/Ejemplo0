/*Ejercicio 5: Leer los números A y B, mostrar como salida el resultado de 
elevar el número base A al exponente B
A = 5	B=3		5*5*5= 125	*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int base = 0;
int exponente = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese la base\n");
		scanf("%d",&base);
		printf("\nIngrese el exponente\n");
		scanf("%d",&exponente);
		
		//ciclo descendente
		int contador = 1;
		int resultado = 1;
		
		while(contador <= exponente){
			resultado = resultado*base;
			contador++;
		}
		
		printf("\n El resultado es: %d",resultado);
		
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
