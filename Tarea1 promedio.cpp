//Ejercicio 2: Leer tres n�meros y luego generar como salida el promedio de los mismos

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
float numero1 = 0;
float numero2 = 0;
float numero3 = 0;
double promedio = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el promedio de 3 n�meros \n");
	printf("Ingrese el primer n�mero: \n");
	scanf("%f",&numero1);
	printf("Ingrese el segundo n�mero: \n");
	scanf("%f", &numero2);
	printf("Ingrese el tercer n�mero: \n");
	scanf("%f", &numero3);
	
	//formula del promedio
	promedio = (numero1 + numero2 + numero3)/3 ;

	printf("El promedio total es: \n");
	printf("%lf \n",promedio);
	//PARTE 6:FIN DEL CODIGO 
}
