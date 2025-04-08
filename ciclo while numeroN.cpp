/*Ejercicio 1: Solicitar al usuario un valor numérico
entero positivo N y a continuación muestre
como salida la sumatoria de los números
de 1 hasta N.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int n= 0;
int contador = 1;
int suma = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
//generar una serie de numeros 1...n
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese por favor un valor\n");
		scanf("%d",&n);
		
		while(contador <= n){
			printf("%3d", contador);
			suma = suma+contador;
			contador++;
		}
		
		printf("\nLa suma del número dado es: %d\n",suma);
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
