//Ejercicio 1: Escribir un algoritmo que indique si el n�mero ingresado por el
// usuario es positivo o negativo 

//PARTE 1: LIBRERIAS
#include <stdio.h>

//PARTE 2: DATOS/VARIABLES
float numero = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula si el n�mero es positivo o negativo \n");
	printf("Ingrese el valor a evaluar: \n");
	scanf("%f",&numero);
	
	//comparo con if
	if(numero != 0){
		if(numero > 0){
			printf("El n�mero ingresado es positivo");
		} else{
			printf("El n�mero ingresado es negativo");
		}
	} else{
		printf("El n�mero tiene que ser distinto de cero");
	}
	//PARTE 6:FIN DEL CODIGO 
}
