/*Escribir un programa que gestione una matriz de 3 x 3, valores enteros 
aleatorios entre 25 a 30. Mostrar como salida el contenido de la matriz y la 
sumatoria de los valores contenidos en la Diagonal de la matriz */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define FILA 3
#define COLUMA 3


int matrix[3][3];

char continuar = 'n';

int main() {
	do{
	
		//mostrar el contenido de la matriz
		int filas = 0;
		int columnas = 0;
		//poniendo valores en lugares especificos
		matrix[0][2] = 50;
		matrix[1][1] = 25;
		matrix[2][0] = 75;
		while(filas<3){
			columnas = 0;
			while(columnas<3){
				//columna y fila
				printf("%5d", matrix[filas][columnas]);
				columnas++;
			}
			filas++;
			printf("\n");
		}
			
		//asignar valores aleatorios
		srand(unsigned(time(NULL)));
		//reiniciar las variables
		//valores aleatorios
		for(filas = 0; filas<3; filas++){
			for(columnas = 0; columnas<3; columnas++){
				//genere de 25 a 30, son 5 valores
				matrix[filas][columnas] = 25 + rand()%6 ;
			}
		}
		
		printf("\nContenido actual: \n");
		//imprimo el contenido
				for(filas = 0; filas<3; filas++){
		for(columnas = 0; columnas<3; columnas++){
		//genere de 25 a 30, son 5 valores
		printf("%5d", matrix[filas][columnas]);
		
		}
		printf("\n");
		}
				
		//sumatoria de la diagonal
		/*matrix[0][2] = 50;
			matrix[1][1] = 25;
				matrix[2][0] = 75;	*/
		
		//Forma 1: usarlo de manera directa
		int suma = 0;
					
		/*suma = matrix[0][2] + matrix[1][1] + matrix[2][0];
					printf("\nLa suma de las diagonales es = %5d", suma);
					
					//Forma 2: usar ciclos
					for(filas = 0; filas<3; filas++){
					for(columnas = 2; columnas>= 0; columnas--){
					//genere de 25 a 30, 
					suma += matrix[filas][columnas];
				}
				}
					printf("\nLa suma de las diagonales es = %5d", suma);*/			
	
		
		//Forma 3: 
		for(filas = 0; filas<3; filas++){ 
				suma += matrix[filas][2-filas];
		}
		printf("\nLa suma de las diagonales es = %5d", suma);
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}
