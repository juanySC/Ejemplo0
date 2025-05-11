/*El valor del número de euler (e) puede aproximarse utilizando la formula
e=1+1/1!+1/2!+1/3!+1/4!+...+1/n!
Escriba un programa que pida al usuario el ingreso de n y aproxime el valor de
euler de acuerdo a la fórmula proporcionada. No se pueden utilizar funciones
de la librería Math.h*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
char continuar = 'n';

float factorial(int numero) {
	float f = 1;
	for (int i = 1; i <= numero; i++) f *= i;
	return f;
}

float calcularEuler(int n) {
	float e = 1.0;
	for (int i = 1; i <= n; i++) {
		e += 1.0 / factorial(i);
		printf("\n%f", factorial(i));
	}
	return e;
}

int main() {
	do{	
		int numero;
	
		printf("Ingrese el valor de n: ");
		scanf("%d", &numero);
	
		float e = calcularEuler(numero);
	
		printf("\n El resultado de los %d términos: %.6f\n", numero, e);
	
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}
