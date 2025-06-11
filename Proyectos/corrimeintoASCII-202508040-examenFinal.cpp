/*Desarrolle un programa en el que se solicite al usuario escribir una frase, a
 continuación debe codificar el texto escrito usando un corrimiento de codigo 
ascii del número de caracteres del último número de su carné, por ejemplo
 alguien que tenga el carné 202508004, el corrimiento será de 4 caracteres
 mediante una función llamada Codificar() que reciba como parámetro el párrafo y 
muestre en pantalla el texto codificado, luego debe decodificarlo haciendo el 
proceso inverso con una función llamada Decodificar().

Ejemplo: Hola mundo (Codificado sería correr cada letra 4 caracteres ascii 
adelante) mostrando como resultado: Lspe qyrhs y al decodificarlo mostrará
 nuevamente Hola mundo.*/

//IMPORTANTE = se cambiara el 0 por un corrimiento de 9

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

char continuar = 's';

// Función para codificar texto con corrimiento ASCII
// uso un puntero ya que mi cadena es un arreglo de caracteres
void Codificar(char *cadena, int correr) {
	for (int i = 0; cadena[i] != '\0'; i++) { //'\0' lo uso para definir el fin de mi cade
		cadena[i] += correr;
	}
}

// Función para decodificar el texto (corrimiento inverso)
void Decodificar(char *cadena, int correr) {
	for (int i = 0; cadena[i] != '\0'; i++) {
		cadena[i] -= correr; //va para atras o sea que es la inversa
	}
}

// Función que calcula el corrimiento basado en el último dígito del carné
int carnePosicion(int carnet) {
	int ultimoNum = carnet % 10;
	return (ultimoNum == 0) ? 9 : ultimoNum; //tomo la decision que si es 0, entonces toma el valor de 9
}

// Limpia la entrada
void vaciar() {
	while (getchar() != '\n'); //tomo mi cadena hasta que encuentre un salto de linea
}

// Leer frase o párrafo del usuario
void leerCadena(char *cadena, int tamanio) {
	printf("\nIngresa una frase:\n> ");
	fgets(cadena, tamanio, stdin); // lee frases completas e incluye los espacios
	cadena[strcspn(cadena, "\n")] = '\0';  // Eliminar salto de línea
}

// Función que muestra el texto codificado y luego decodificado
void MostrarResultados(char *texto, int corrimiento) {
	Codificar(texto, corrimiento);
	printf("\nTexto codificado  : %s\n", texto);
	
	Decodificar(texto, corrimiento);
	printf("Texto decodificado: %s\n", texto);
}

// Función principal
int main() {
	do{
		char cadena[200];
	
		//mi carnet
		int carnet = 202508040;
		int corrimiento = carnePosicion(carnet);  // como es 0 = 9
	
		printf("\nEste programa recibe una cadena y lo recorre 9 posiciones en ASCII");

		//sizeof para guardar la cadena y el tamaño de la misma
		leerCadena(cadena, sizeof(cadena));
		MostrarResultados(cadena, corrimiento);
		printf("\n\nDesea generar una nueva matriz? s/n: ");
		continuar = getch();
		printf("\n");
		
	} while (continuar == 's');
	return 0;
}
