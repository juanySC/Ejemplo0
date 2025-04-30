/*Implementar un programa que permita generar
10 números aleatorios comprendidos entre 1 a 10,
luego mostrar lo siguiente:
a) Cantidad de números pares
b) Cantidad de números impares
c) Cantidad de números primos
d) Cantidad de números perfectos*/
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define NUM 10

int main (){
	//para ver los numero mayor y menor
	int nums[NUM];
	int pares = 0, impares = 0, cantPar = 0, cantImpar =0;
	float suma = 0, promedio;
	int primos = 0, perfecto = 0;
	
	//generando numero aleatorio
	srand(unsigned(time(NULL)));
	
	printf("Ingrese los valores\t");
	for(int i= 0; i <10; i++){
		nums[i] = rand()% 10+1;
		//printf("\n%5d", numeros[i]);
	}
	
	//mostrar numero 
	
	for(int i= 0; i <NUM; i++){
		printf("[%d] = %d \n",i,nums[i]);
		//comparo para ver si los numero son pares
		if(nums[i] % 2 == 0 ){
			pares += nums[i];
			cantPar += 1;
		} else if(nums[i] % 2 != 0){
			impares += nums[i];
			cantImpar += 1;
		}
		//resolviendo con case
		switch(nums[i]){
		case 2: primos++; break;
		case 3: primos++; break;
		case 5: primos++; break;
		case 7: primos++; break;
		}
		
		switch(nums[i]){
		case 6: perfecto++; break;	
		}
	}
	
	printf("\nLa sumatoria de los numero pares es: %d", pares);
	printf("\nLa sumatoria de los numero impares es: %d", impares);
	printf("\nLa cantidad de los numero pares es: %d", cantPar);
	printf("\nLa cantidad de los numero impares es: %d", cantImpar);
	printf("\nLa cantidad de los numero primos es: %d", primos);
	printf("\nLa cantidad de los numeros perfecto es: %d", perfecto);
	
	
}
