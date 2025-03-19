//Ejercicio 4: Escribir un programa que encuentre el área superficial de un cubo

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
int base = 0;
int constate = 6;
float areaSup = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el area superficial de un cubo \n");
	printf("Ingrese la base del cubo: \n");
	scanf("%d",&base);
	//formula del area superficial
	areaSup = constate * base * base;
	printf("El área superficial del cubo es: ");
	printf("%f",areaSup);
	//PARTE 6:FIN DEL CODIGO 
}
