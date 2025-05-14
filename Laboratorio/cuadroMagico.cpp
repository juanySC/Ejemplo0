#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define NUM 11 //generando hasta mi numero limite 
char continuar = 'n';

void generarCuadroMagico(int n, int cuadrado[NUM][NUM]) {
	// para recorrer 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cuadrado[i][j] = 0;
			
			int fila = n - 1;           // Empieza en la última fila
			int columna = n / 2;        // Columna central
			int valor = 1;
			
			while (valor <= n * n) {
				if (cuadrado[fila][columna] == 0) {
					cuadrado[fila][columna] = valor;  // Asignar número
				} else {
					// Si está ocupado, sube dos filas y una columna a la izquierda
					fila = (fila - 2 + n) % n;
					columna = (columna - 1 + n) % n;
					continue;  // Reintenta con mismo valor
				}
				
				// Avanza una fila y una columna a la derecha (regla normal)
				fila = (fila + 1) % n;
				columna = (columna + 1) % n;
				valor++;
			}
}

void imprimirCuadro(int n, int cuadrado[NUM][NUM]) {
	printf("\nCuadrado mágico de orden %d:\n\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d", cuadrado[i][j]);
		}
		printf("\n");
	}
}

int main() {
	do{
		int n;
		int cuadrado[NUM][NUM];
		
		printf("\n\nEste programa muestra una matriz llamado cubo mágico");
		printf("\nIngrese un número impar entre 3,5, 7, 9 y 11: ");
		scanf("%d", &n);
	
		if (n < 3 || n > 11 || n % 2 == 0) {
			printf("Error: El número debe ser impar y estar entre 3 y 11.\n");
			return 1;
		}
	
		generarCuadroMagico(n, cuadrado);
		imprimirCuadro(n, cuadrado);
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	return 0;
}

