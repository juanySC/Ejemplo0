//Ejercicio 2: Escribir un algoritmo que indique si el número ingresado por el
// usuario es par o impar

//PARTE 1: LIBRERIAS
#include <stdio.h>

//PARTE 2: DATOS/VARIABLES
int numeroEvaluado = 0;


//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula si el número es par o impar \n");
	printf("Ingrese el número a evaluar: \n");
	scanf("%d",&numeroEvaluado);
	
	//comparo con if
	if(numeroEvaluado != 0){
		if(numeroEvaluado % 2 == 0){
			printf("El número ingresado es par");
		} else{
			printf("El número ingresado es impar");
		}
	} else{
		printf("El número tiene que ser distinto de cero");
	}
	//PARTE 6:FIN DEL CODIGO 
}
