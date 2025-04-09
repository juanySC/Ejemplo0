/*Ejercicio 4: Solicitar al usuario un valor num�rico entero positivo N y a 
continuaci�n muestre si el n�mero es perfecto, un n�mero perfecto es aquel que 
sus divisores propios son iguales a �l mismo, por ejemplo el n�mero 6: Divisores 
propios: 1,2,3, suma=6*/


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
		int suma = 0;
		
		while(contador < numero){
			if(numero %contador == 0){
				divisores++;
				printf("\n%d",contador);
				suma = suma+contador;
				
			}
			contador++;
			
		}
		
		if(suma == numero){
			printf("\nEl n�mero es perfecto\n");
			printf("\nla suma es: %d",suma);
			printf("\nIgual que el numero ingresado %d", numero);
		}else{
			printf("\nEl numero no es perfecto\n");
			printf("\nla suma es: %d",suma);
			printf("\nIgual que el numero ingresado %d", numero);
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
