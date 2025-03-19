//Ejercicio 5: Escribir un programa que encuentre el área de un círcuo

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
int radioCirculo = 0;
double pi = M_PI;
float areaCirculo = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el area de un circulo \n");
	printf("Ingrese la magnitud del radio: \n");
	scanf("%d",&radioCirculo);

	//formula del area de un circulo
	areaCirculo = pi * radioCirculo * radioCirculo;
	printf("El área calculada del circulo es: ");
	printf("%f",areaCirculo);
	//PARTE 6:FIN DEL CODIGO 
}
