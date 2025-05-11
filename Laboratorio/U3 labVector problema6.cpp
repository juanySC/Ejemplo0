/*Problema: 6
Llenar un vector de caracteres de 5X5, el usuario debe seleccionar si se llenar�n
con min�sculas o may�sculas, luego mostrar las siguientes estad�sticas
a) Cantidad de vocales
b) Cantidad de consonantes
c) Cantidad de d�gitos
d) Cantidad de s�mbolos*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
char continuar = 'n';

void llenarMatrizChar(char m[5][5], char tipo) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			m[i][j] = (tipo == 'm') ? rand() % 26 + 'a' : rand() % 26 + 'A';
}

void imprimirMatrizChar(char m[5][5]) {
	printf("\nMatriz generada:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%3c ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void analizarMatrizChar(char m[5][5]) {
	int vocales = 0, consonantes = 0, digitos = 0, simbolos = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char c = tolower(m[i][j]);
			if (isdigit(c)) digitos++;
			else if (isalpha(c)) {
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') vocales++;
				else consonantes++;
			} else simbolos++;
		}
	}
	printf("Vocales: %d\nConsonantes: %d\nDigitos: %d\nSimbolos: %d\n", vocales, consonantes, digitos, simbolos);
}

int main() {
	do{
		char matriz[5][5];
		char tipo;
		printf("Ingrese 'm' para min�sculas o cualquier otra letra para may�sculas: ");
		scanf(" %c", &tipo);
		srand(time(NULL));
		llenarMatrizChar(matriz, tipo);
		imprimirMatrizChar(matriz);
		analizarMatrizChar(matriz);
	
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}
