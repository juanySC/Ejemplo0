/*Calcular la varianza, la media y desviación estandar
En una matriz de 11x11*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define FILAS 11
#define COLUMNAS 11
char continuar = 'n';

//llenara de numeros aleatorios
void numerosAleatorios(float matriz[FILAS][COLUMNAS]){
	//voy a recorrer la matriz
	for(int i = 0; i<FILAS; i++){ //recorro filas
		for(int j = 0; j <COLUMNAS; j++){ //recorro columnas
			//que me genera de 0 a 100, me ayuda a dividir las fracciones
			matriz[i][j] = (float)(rand() % 10000) / 100.0; 
			//imprimo la matriz con dos decimales
			
			printf("%.2f\t", matriz[i][j]);
		}
		printf("\n"); // Salto de línea por cada fila
	}
}

//funcion que si me retorna un valor
float calcularMedia(float matriz[FILAS][COLUMNAS]){
	float suma = 0;
	int resultado = FILAS * COLUMNAS; //o sea 121 elementos en toda la matriz
	for(int i = 0; i<FILAS; i++){ //recorro filas
		for(int j = 0; j <COLUMNAS; j++){ //recorro columnas
			suma = suma + matriz[i][j];
		}
	}
	return suma/resultado; 
}
	
float calcularVarianza(float matriz[FILAS][COLUMNAS], float devolverMedia){	
	float suma = 0;
	int total = FILAS * COLUMNAS;
	
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			float diferencia = matriz[i][j] - devolverMedia; // (xi - media)
			suma += diferencia * diferencia;         // (xi - media)^2
		}
	}
	return suma / total; // Retorna la varianza	
}		

float calcularDesviacionEstandar(float varianza) {
	return sqrt(varianza);
}

int main(){
	do{
		float matriz[FILAS][COLUMNAS];
		//para generar los numeros aleatorios 
		srand(unsigned(time(NULL)));
	
		printf("\n\nEste programa muestra los valores de la varianza que son:");
		printf("varianza, desviacion estandar y media\n");
		//llamo a mis funciones 
		numerosAleatorios(matriz);
	
		//declaro para llamar a mis funciones que retornar valor
		float devolverMedia = calcularMedia(matriz);
		float devolverVarianza = calcularVarianza(matriz, devolverMedia);
		float devolverDesviacion = calcularDesviacionEstandar(devolverVarianza);
	
		printf("\n\nMedia: %.2f", devolverMedia);
		printf("\n Varianza: %.2f", devolverMedia);
		printf("\nDesviación estandar: %.2f", devolverMedia);
	
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');

	
	return  0; 
}
