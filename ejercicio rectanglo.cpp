//Ejercicio 2: Escribir un programa que encuentre el volumen de un cilindro

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
int radio = 0;
int altura = 0;
float area = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el area de un rectangulo \n");
	printf("Ingrese la magnitud de la base: \n");
	scanf("%d",&base);
	printf("Ingrese la magnitud de la altura: \n");
	scanf("%d",&altura);
	//formula del area de un rectangulo
	area = base * altura;
	printf("El área calculada del rectangulo es: ");
	printf("%f",area);
	//PARTE 6:FIN DEL CODIGO 
}
