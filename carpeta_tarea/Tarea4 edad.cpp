//Escribir un algoritmo que indique si la persona es mayor o menor de edad
//	en base a su año de nacimiento y el año actual  
	
	
	//PARTE 1: LIBRERIAS
#include <stdio.h>
	
	//PARTE 2: DATOS/VARIABLES
	int anioActual = 0;
	int anioNacimiento = 0;
	int total = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula si es mayor o menor de edad \n");
	printf("\nIngrese el año actual (ej: 2025): \n");
	scanf("%d",&anioActual);
	printf("\nIngrese el año de nacimiento (ej: 2005): \n");
	scanf("%d",&anioNacimiento);
	
	//comparo con if
	if((anioActual&& anioNacimiento) != 0){
		//sacando el numero de edad a traves de una resta
		total = anioActual - anioNacimiento;
		
		if(total >= 18){
			printf("\nUsted es mayor de edad");
		} else{
			printf("\nUsted es menor de edad");
		}
	} else{
		printf("El número tiene que ser distinto de cero");
	}
	//PARTE 6:FIN DEL CODIGO 
}	
