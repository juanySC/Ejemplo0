//Ejercicio 2: Escribir un algoritmo que indique si el n�mero ingresado por el
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
	printf("Este programa calcula si el n�mero es par o impar \n");
	printf("Ingrese el n�mero a evaluar: \n");
	scanf("%d",&numeroEvaluado);
	
	//comparo con if
	if(numeroEvaluado != 0){
		if(numeroEvaluado % 2 == 0){
			printf("El n�mero ingresado es par");
		} else{
			printf("El n�mero ingresado es impar");
		}
	} else{
		printf("El n�mero tiene que ser distinto de cero");
	}
	//PARTE 6:FIN DEL CODIGO 
}
