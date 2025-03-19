//Ejercicio 2: Escribir un programa que encuentre el área de un rectángulo

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
int altura = 0;
int radioR = 0;
double pi = M_PI;
float volumenC = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el area de un cilindro \n");
	printf("Ingrese la magnitud de la altura: \n");
	scanf("%d",&altura);
	printf("Ingrese la magnitud del radioR: \n");
	scanf("%d",&radioR);
	//formula de un cilindro
	volumenC = altura * radioR * radioR * pi;
	printf("El área calculada del cilindro es: ");
	printf("%f",volumenC);
	//PARTE 6:FIN DEL CODIGO 
}
