/*El valor de seno de x se puede aproximar utilizando la fórmula senx = x -
(x^3)/3!+(x^5)/5!-(x^7)/7!+(x^9)/9!+...+(x^n)/n!
Escriba el programa que solicite el valor de x y de n (Verifique que n sea impar),
recuerde que para elevar a un exponente debe utilizar ciclos, lo mismo que
para factorial, no se permite para este ejercicio el uso de funciones de la
librería math.h
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define PI 3.14159
char continuar = 'n';

float factorial(int n) {
	float f = 1;
	for (int i = 1; i <= n; i++) f *= i;
	return f;
}

float potencia(float base, int exponente) {
	float resultado = 1;
	for (int i = 0; i < exponente; i++) resultado *= base;
	return resultado;
}

float calcularSeno(float x, int n) {
	float resultado = 0;
	int signo = 1;
	for (int i = 1; i <= n; i += 2) {
		resultado += signo * (potencia(x, i) / factorial(i));
		signo *= -1;
	}
	return resultado;
}

int main() {
	do{
		float grados, x;
		int n;
		do {
			printf("\nIngrese el valor de x (en grados): ");
			scanf("%f", &grados);
			x = grados * (PI / 180);  // Conversión de grados a radianes
		
			printf("\nIngrese un valor impar para n (grados del numerador): ");
			scanf("%d", &n);
		
			if (n % 2 == 0) {
				printf("\nError: El valor de n debe ser impar. Intente de nuevo.\n\n");
			}
		} while (n % 2 == 0);
	
		float resultado = calcularSeno(x, n);
		printf("\nAproximación de sen(%.2f grados) con %d términos: %.6f\n", grados, n, resultado);
	
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');

	return 0;
}
