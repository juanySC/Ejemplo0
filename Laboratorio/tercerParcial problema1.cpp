/*Escribir un programa, que gestione un arreglo bidimensional de 5x5, el mismo 
se debe llenar con caracteres aleatorios del abecedario en español, 
tanto mayúsculas como minúsculas, el programa debe brindar como estadísticas de 
salida:

1. Cantidad de vocales minúsculas
2.cCantidad de consonantes minúsculas
3. Cantidad de vocales mayúsculas
4. Cantidad de consonantes mayúsculas*/
#include <stdio.h> //entrada y salida
#include <stdlib.h> //rand
#include <ctype.h> //isupper, isalpha, basicamente es la biblioteca de caracteres
#include <time.h>
#include <conio.h> //getch
char continuar = 'n';

//llenando mi matriz con las letras
void llenarMatriz(char m[5][5]) {
	for (int i = 0; i < 5; i++) //recorro filas
		for (int j = 0; j < 5; j++)	//recorro columnas
			//Lleno con ASCII
			if(rand()% 2 == 0) //si es aleatorio es par
				m[i][j] = rand()%26 + 65; //son letras mayusculas 65 = A
			else
				m[i][j] = rand()%26 + 97;	//son letras minusculas 97 = a
}

void imprimirMatriz(char m[5][5]) {
	printf("\nMatriz generada:\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%3c ", m[i][j]);
		}
		printf("\n"); //para saltar cada 5 elementos
	}
	printf("\n");
}

void examinarMatriz(char m[5][5]) {
	int vocalesMayus = 0, consonantesMayus = 0, vocalesMinus = 0, consonantesMinus = 0;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			char c = m[i][j];
			
			//verifica si la letra es del alfabeto 0= falso otro numero = verdader0
			if (isalpha(c)) {
				// Verifica si es vocal
				if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
					vocalesMayus++; //aumento mi contador en las vocales mayusculas
				else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
					vocalesMinus++; //aumento mi contador en las vocales minusculas
				//verifica si la letra es mayuscula 0 = falso numero = verdadero
				else if (isupper(c))
					consonantesMayus++;
				//verifica si la letra es minuscula 0 = falso y valor distinto verdadero
				else if (islower(c))
					consonantesMinus++;
			}
		}
	}
	
	// Mostramos los resultados
	printf("\nVocales Mayúsculas: %d", vocalesMayus);
	printf("\nConsonantes Mayúsculas: %d", consonantesMayus);
	printf("\nVocales Minúsculas: %d", vocalesMinus);
	printf("\nConsonantes Minúsculas: %d\n", consonantesMinus);
}


int main() {
	do{
		char matriz[5][5];
		srand(unsigned(time(NULL)));
		
		printf("Este programa muestra una matriz de 5x5 formado por el abecedario en mayuscula y minuscula");
		printf("Su matriz es: ");
		llenarMatriz(matriz);
		imprimirMatriz(matriz);
		examinarMatriz(matriz);
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}

