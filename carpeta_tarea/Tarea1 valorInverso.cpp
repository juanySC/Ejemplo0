/*Leer un número entero y generar como salida su valor simétrico y su valor
inverso. El simétrico de -2 es 2 y el simétrico de 5 es -5.
El inverso de 2 es ½*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
float numeroInicial = 0;
float inversoNumero = 0;
float	simetricoNumero = 0;
//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el inverso y simetrico de un numero \n");
	printf("Ingrese el valor del número a evaluar: \n");
	scanf("%f",&numeroInicial);
	
	//formula del inverso del numero
	if(numeroInicial != 0){ //mientras el numero no sea 0 entra a la condicion
		inversoNumero = 1/numeroInicial;
	}
	
	//formula del simetrico de un numero
	simetricoNumero = -numeroInicial;
	
	printf("\n El número inverso es: \n");
	printf("%f \n",inversoNumero);
	printf("El número simetrico es: \n");
	printf("%f \n",simetricoNumero);
	//PARTE 6:FIN DEL CODIGO 
}
