//Ejercicio 1: Leer un n�mero, y luego generar como salida el cuadrado y el cubo del mismo.

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
int numeroCC = 0;
float numeroCuadrado = 0;
float numeroCubo = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el cuadrado y cubo de un n�mero \n");
	printf("Ingrese el n�mero que desee: \n");
	scanf("%d",&numeroCC);
	
	//formula del cuadraro de un numero
	numeroCuadrado = numeroCC * numeroCC;
	
	//formula del cubo de un numeroCC
	numeroCubo = numeroCC * numeroCC * numeroCC;
	
	printf("El cuadrado del n�mero es: \n");
	printf("%f \n",numeroCuadrado);
	printf("El cubo del n�mero es: \n");
	printf("%f", numeroCubo);
	//PARTE 6:FIN DEL CODIGO 
}
