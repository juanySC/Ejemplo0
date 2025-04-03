/*Ejercicio 1: Se requiere que escriba un programa que permita leer un número 
entre 1 a 100,000 y luego de como salida el equivalente en letras. Deberá 
aplicar instrucciones de selección y operadores aritméticos.
Ejemplo de entrada 1				  Ejemplo de salida uno
Ejemplo de entrada 21                 Ejemplo de salida Veinte y uno*/

// PARTE 1: LIBRERÍAS
#include <stdio.h>
#include <conio.h>

// PARTE 2: DATOS/VARIABLES
int numero = 0;
int millar = 0;
int decena_millar = 0;
int centena = 0;
int decena = 0;
int unidad = 0;
char condicion = 'n';

// PARTE 3: FUNCIÓN PRINCIPAL
int main() {
	do {
		// PARTE 5: INSTRUCCIONES O CÓDIGO
		printf("Este programa devuelve el número en letras del 1 al 100000\n");
		printf("\nIngrese el número que desea evaluar: \n");
		scanf("%d", &numero);
		
		// Verificar si el número está dentro del rango permitido
		if (numero < 1 || numero > 100000) {
			printf("\nEl número está fuera de rango\n");
		}
		
		// Obtener partes del número
		millar = numero / 1000; // Para miles y decenas de mil
		decena_millar = (numero % 100000) / 10000;
		centena = (numero % 1000) / 100;
		decena = (numero % 100) / 10;
		unidad = numero % 10;
		
		printf("\nEl número en letras es: \n");
		
		// Evaluar decenas de millar (20,000 a 90,000)
		if (decena_millar > 0) {
			switch (decena_millar) {
			case 1:
				if (millar == 0) {
					printf("diez mil ");
				} else {
					printf("dieci");
				}
				break;
			case 2: printf("veinte mil "); break;
			case 3: printf("treinta mil "); break;
			case 4: printf("cuarenta mil "); break;
			case 5: printf("cincuenta mil "); break;
			case 6: printf("sesenta mil "); break;
			case 7: printf("setenta mil "); break;
			case 8: printf("ochenta mil "); break;
			case 9: printf("noventa mil "); break;
			}
		}
		
		// Evaluar millares (1,000 a 9,999)
		if (millar > 0 && millar < 10) {
			if (decena_millar == 1) { // 11,000 a 19,999
				switch (millar) {
				case 1: printf("once mil "); break;
				case 2: printf("doce mil "); break;
				case 3: printf("trece mil "); break;
				case 4: printf("catorce mil "); break;
				case 5: printf("quince mil "); break;
				case 6: printf("dieciséis mil "); break;
				case 7: printf("diecisiete mil "); break;
				case 8: printf("dieciocho mil "); break;
				case 9: printf("diecinueve mil "); break;
				}
			} else if (decena_millar == 0) { 1,000 a 9,000
				switch (millar) {
				case 1: printf("mil "); break;
				case 2: printf("dos mil "); break;
				case 3: printf("tres mil "); break;
				case 4: printf("cuatro mil "); break;
				case 5: printf("cinco mil "); break;
				case 6: printf("seis mil "); break;
				case 7: printf("siete mil "); break;
				case 8: printf("ocho mil "); break;
				case 9: printf("nueve mil "); break;
				}
			}
		}
		
		// Evaluar centenas
		if (centena > 0) {
			if (centena == 1 && decena == 0 && unidad == 0) {
				printf("cien");
			} else {
				switch (centena) {
				case 1: printf("ciento "); break;
				case 2: printf("doscientos "); break;
				case 3: printf("trescientos "); break;
				case 4: printf("cuatrocientos "); break;
				case 5: printf("quinientos "); break;
				case 6: printf("seiscientos "); break;
				case 7: printf("setecientos "); break;
				case 8: printf("ochocientos "); break;
				case 9: printf("novecientos "); break;
				}
			}
		}
		
		//Numeros especiales (10-19)
		if (decena == 1) {
			switch (numero % 100) {
			case 10: printf("diez"); break;
			case 11: printf("once"); break;
			case 12: printf("doce"); break;
			case 13: printf("trece"); break;
			case 14: printf("catorce"); break;
			case 15: printf("quince"); break;
			case 16: printf("dieciséis"); break;
			case 17: printf("diecisiete"); break;
			case 18: printf("dieciocho"); break;
			case 19: printf("diecinueve"); break;
			}
		} 
		else { // Evaluar decenas normales (20, 30, ..., 90)
			switch (decena) {
			case 2: printf("veinte"); break;
			case 3: printf("treinta"); break;
			case 4: printf("cuarenta"); break;
			case 5: printf("cincuenta"); break;
			case 6: printf("sesenta"); break;
			case 7: printf("setenta"); break;
			case 8: printf("ochenta"); break;
			case 9: printf("noventa"); break;
			}
			
			// Agregar " y " solo si hay unidades y la decena no es 0
			if (decena > 2 && unidad != 0) {
				printf(" y ");
			}
		}
		
		// Evaluar unidades
		if (decena != 1) { // Solo imprimir si no es un número del 10 al 19
			switch (unidad) {
			case 1: printf("uno"); break;
			case 2: printf("dos"); break;
			case 3: printf("tres"); break;
			case 4: printf("cuatro"); break;
			case 5: printf("cinco"); break;
			case 6: printf("seis"); break;
			case 7: printf("siete"); break;
			case 8: printf("ocho"); break;
			case 9: printf("nueve"); break;
			}
		}
		
		// Caso especial: 100,000
		if (numero == 100000) {
			printf("cien mil");
		}
		
		// Preguntar si desea continuar
		printf("\n\n¿Desea continuar evaluando números? (s/n): ");
		condicion = getch(); // Capturar entrada sin necesidad de presionar Enter
		printf("\n");
		
	} while (condicion == 's');
	
	return 0; // Fin del programa
}
