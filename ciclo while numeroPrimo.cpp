/*Ejercicio 3: Solicitar al usuario un valor num�rico entero positivo N y a 
continuaci�n indicar si el mismo es primo o no, tome en cuenta que un n�mero 
primo  es  el  que  tiene  exactamente  dos divisores siendo la unidad y �l mismo. */

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese por favor un valor\n");
		scanf("%d",&numero);
		
		//comparar si tiene 2 divisores entonces es primo
		int divisores = 0;
		int contador = 1;
		while(contador<=numero ){
			if(numero%contador == 0){
				divisores++;
			}
			contador++;
		}
		
		if(divisores == 2){
			printf("\nEl n�mero es primo");
		}else{
			printf("\nEl n�mero es no primo");
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
