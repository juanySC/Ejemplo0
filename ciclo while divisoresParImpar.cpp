/*Ejercicio 1: Solicitar  al  usuario  un  valor  numérico entero positivo N y 
a continuación muestre todos  sus  divisores,  para  cada  divisor, 
deberá indicar si es par o impar*/

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
		//sirve para reiniciar los divisores y que no se acumulen de la vez anterior
		divisores = 0;
		
		while(contador <= numero){
			if(numero %contador == 0){
				divisores++;
				if(contador%2 ==0){
					printf("\n %s %d  %s","tiene: ",divisores,"divisores pares");
				}else{
					printf("\n %s %d  %s","tiene: ",divisores,"divisores impares");
				}
			}
			contador++;
			
		}
		
	
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
