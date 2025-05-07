/*Problema 5: Gestionar una matriz de 5X5, de tipo entero, llenarlo de valores 
aleatorios comprendidos entre el valor inicial y valor final indicados por el 
usuario, mostrar como salida lo siguiente:
a) Valor máximo
b) Valor mínimo
c) Sumatoria de valores de la diagonal principal
d) Sumatoria de los valores excepto los de la diagonal principal*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define COLUMNA 5
#define FILA 5

int matrix[FILA][COLUMNA];
int filas = 0;
int columnas = 0;
int inicioRango = 0, finalRango = 0;
char continuar = 'n';

void valorAleatorio(){
	//asignar valores aleatorios
	srand(unsigned(time(NULL)));
	//reiniciar las variables
	//valores aleatorios
	for(filas = 0; filas<FILA; filas++){
		for(columnas = 0; columnas<COLUMNA; columnas++){
			//genere numeros aleatorios que el usuario dice
			matrix[filas][columnas] = rand()% (finalRango - inicioRango+1) + inicioRango;
		}
	}
}
	
	void impresionDatos(){
		printf("\nContenido actual: \n");
		//imprimo el contenido
		for(filas = 0; filas<FILA; filas++){
			for(columnas = 0; columnas<COLUMNA; columnas++){
				//
				printf("%5d", matrix[filas][columnas]);
			}
			printf("\n");
		}
		
	}	
	
	int valorMaximo(){
		int maximo;
		
		return maximo;
	}	
		
	int sumaDiagonal(){
		int suma = 0;
		for (filas = 0; filas < FILA; filas++) {
			suma += matrix[filas][filas];
		}
		return(suma);
	}
	
	int sumaRestante(){
		int sumaRestante = 0;
		return sumaRestante:
	}
			
	int main() {
		do{
			
			//variables par amedir el rango
		
			
			printf("\n\nEste programa grafica una matriz de 5x5");
			printf("\nIngrese el valor minimo del rango: ");
			scanf("%d", &inicioRango);
			printf("Ingrese el valor máximo del rango: ");
			scanf("%d", &finalRango);
			
			//comparo si esto puede ser viable
			if(finalRango < inicioRango){
				printf("\nRango no valido");
			}
			
		//llamando funciones
			valorAleatorio();
			impresionDatos();
			printf("\nEl valor maximo de toda la matriz es: %5d",valorMaximo());
			printf("\n El valor minimo de toda la matriz es: %5d");
			printf("\nLa suma de la diagonal de la matriz es: %5d", sumaDiagonal());
			printf("\nLa suma de total de los numeros que no estan en la matriz es: %5d");
					
			//si desea volver a meter ecuacion cuadratica
			printf("\n\nDesea imprimir de nuevo s/n");
			continuar=getch();//Para asignar a una variable char
			printf("\n");
		}while(continuar == 's');
		return 0;
	}
			
