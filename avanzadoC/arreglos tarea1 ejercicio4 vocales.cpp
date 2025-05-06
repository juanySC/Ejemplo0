/*Llenar  un  vector  de  10  caracteres  aleatorios  y mostrar  el  conteo  de: 
 consonantes,  vocales  y símbolos.*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#define NUM 10

char continuar = 'n';

int main() {
	do{
		char caracteres[10];
		int vocales = 0, consonantes = 0, simbolos = 0;
		
		//generando de manera aleatorio
		srand(unsigned(time(NULL)));
		for (int i = 0; i < NUM; i++) {
			/*genero mis caracteres con codigo ASCII
			(126 - 33 + 1) = 94 caracteres en ese rango y + 33 para que 
			empieze en 33 y no en 0*/
			caracteres[i] = rand() % 94 + 33; 
			printf("\n\n %1s %2d %3s \t","{",i,"}");
			printf("%3c ", caracteres[i]); //imprimo mi caracter
			
			//para leer las vocales mayusculas y minusculas por igual "tolower"
			char comparoCaracter = tolower(caracteres[i]);
			
			if ((comparoCaracter >= 'a' && comparoCaracter <= 'z')) {
				if (comparoCaracter == 'a' || comparoCaracter == 'e' || comparoCaracter == 'i' || comparoCaracter == 'o' || comparoCaracter == 'u') vocales++;
				else consonantes++;
			} else {
				simbolos++;
			}
		}
		
		printf("\n\nVocales: %d", vocales);
		printf("\nConsonantes: %d", consonantes);
		printf("\nSimbolos: %d", simbolos);
		
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}
