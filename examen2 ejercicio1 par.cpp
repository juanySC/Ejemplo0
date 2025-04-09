/*Ejercicio 1: 
Finalización par: Leer un número entero positivo y brindar como
salida si el número ingresado es abundante, un número abundante es aquel cuya 
sumatoria de los divisores propios es mayor al número que se está evaluando. */

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
		/*sirve para reiniciar los divisores y que no se acumulen de la vez 
		anterior, cuando se quiere saca un segundo valor en consola*/
		divisores = 0;
		int suma = 0;
		
		//para que no se cometa el error de meter numeros negativos
			if(numero >= 0){
				while(contador <= numero){//recorre de 1 a numero
					if(numero %contador == 0){ //si mi residio es 0 es divisor
						divisores++; //respresenta si un divisor aumenta
						printf("\n%d",contador);
						suma = suma+contador; 
						
					}
					contador++; //va en secuencia de 1 al numero
					
				}
				
				//numero de #divisores
				printf("\n %s %d  %s","\ntiene: ",divisores,"divisores");
				printf("\nLa suma de los divisores es: %d", suma);
				
				//divido si es o no abundante
				if(suma > numero){
					printf("\nEl número es abundante ");
					printf("\nPorque la suma es mayor a %d", numero);
					
				}else if ((suma<numero) || (suma == numero)){
					printf("\nEl número no es abundante");
				}
				
			}else{
				printf("\nIngrese un número mayor o igual a 0");
			}
				
			
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
