//Ejercicio 4: Solicitar los datos necesarios para mostrar, como salida,
// el área superficial de un cubo.

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
float lado = 0;
float areaSupCubo = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el área superficial de un cubo \n");
	printf("Ingrese el valor de uno de los lados del cubo: \n");
	scanf("%f",&lado);
	
	//formula del area superficial de un cubo
	areaSupCubo = 6 * lado * lado;
	
	printf("\n El área superficial del cubo es: \n");
	printf("%f \n",areaSupCubo);
	//PARTE 6:FIN DEL CODIGO 
}
