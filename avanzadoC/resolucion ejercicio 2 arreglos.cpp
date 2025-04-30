#include <stdio.h>
#include <windows.h>
#include <time.h>
int vector[10];

int main (){
	//para ver los numero mayor y menor
	int numeros[10];
	int i, mayoresIgual = 0, menores = 0;
	float suma = 0, promedio;
	
	//generando numero aleatorio
	srand(unsigned(time(NULL)));
	
	printf("Ingrese los valores\t");
	for(i = 0; i <10; i++){
		numeros[i] = rand()% 100+1;
		printf("\n%d", numeros[i]);
		suma+= numeros[i];
	}
	
	//calculamos el promedio 
	promedio = suma/10.0;
	//contamos mayores, menores o iguales al promedio
	for( i= 0; i <10; i++){
		if(numeros[i] >= promedio)
			mayoresIgual++;
		else 
			menores++;
	}
	
	//mostramos resultados 
	printf("\n \nPromedio %.2f\n", promedio);
	printf("Cantidad de numeros >= al promedio ,mayores : %d\n", mayoresIgual);
	printf("Cantidad de numeros <= promedio,, menores : %d\n", mayoresIgual);
	
}
	
