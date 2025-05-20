#include <stdio.h>

int fibonacci(int numero);
int sumaNaturales(int natural);

int main(){
	int numero;
	printf("El programa de fibonacci y los numero naturales");
	printf("Ingrese el número que desee: ");
	scanf("%d", &numero);
	printf("La suma de fibonacci es:  %d", fibonacci(numero));
	//para la suma de los naturales 
	printf("la suma de los numeros naturales: %d", sumaNaturales(numero));
	return 0;
}

int fibonacci(int numero){
	if(numero ==0) return 0;
	if(numero ==1) return 1;
	return fibonacci(numero-1) + (numero -2);
}

int sumaNaturales(int natural){
	if(natural == 0) return 0;
	return natural + sumaNaturales(natural -1);
}	
	

