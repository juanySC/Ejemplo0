//Ejercicio 3: Escribir un programa que pase de Quetzales a Dolares

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
float quetzales = 0;
float dolares = 0.13 ;
float conversion = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula la conversion de quetzales a dolares \n");
	printf("Ingrese la cantidad de dinero en quetzales: \n");
	scanf("%f",&quetzales);
	//formula de conversion de quetzales a dolares
	conversion = quetzales * dolares;
	printf("La conversion final es: $ ");
	printf("%f",conversion);
	//PARTE 6:FIN DEL CODIGO 
}
