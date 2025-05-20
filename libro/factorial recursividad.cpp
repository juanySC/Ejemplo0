#include <stdio.h>

int factorialEntero(int numero);
float factorialFraccion(float numeroF);

int main(){
	int numero;
	//factorial por numeros enteros
	printf("Ingrese el numero que desee sacar el factorial");
	scanf("%d", &numero);
	printf("El resultado es: %d", factorialEntero(numero));
	//factorial por numeros fraccionarios
	printf("El resultado es:; %.5f", factorialFraccion(numero));
	return 0;
}

	//n!
int factorialEntero(int numero){
	//cuando sea el resultado cero lo tomara como 1 y ya devuelve todo el resultado
	if( numero == 0) return 1; 
	//ej. 9 * 9- 1 = 9 * 8
	return numero * factorialEntero(numero-1);
}	
	
//1/n!	
float factorialFraccion(float numeroF){
	
	float factorial = 1.0;
	for (int i = 1; i <= (int)numeroF; i++) {
		factorial *= i;
	}
	return 1.0 / factorial;
	
	/*int entero = (int)numeroF; // Convierte a entero (solo trabaja para valores enteros positivos)
	if (entero == 0) return 1.0;
	return 1.0 / factorialEntero(entero);*/
}	
	
