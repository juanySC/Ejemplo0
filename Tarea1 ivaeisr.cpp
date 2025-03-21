/*Ejercicio 5: Leer el total de una factura, calcular el IVA (12%) y
 el ISR (5%), luego calcular y mostrar como salida el total de la
factura sin impuestos*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
float montoInicial = 0;
float montoFinalIva = 0;
float montoFinalIsr = 0;
float precioOriginal = 0;
float iva = 0.12;
float totalIva = 0;
float isr = 0.05;
float totalIsr = 0;
float operacion = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el IVA e ISR de una compra \n");
	printf("Ingrese el valor de la compra: \n");
	scanf("%f",&montoInicial);
	
	//formula del iva
	totalIva = montoInicial * iva;
	montoFinalIva = montoInicial - totalIva;
	
	//formula del ISR 
	totalIsr = montoInicial * isr;
	montoFinalIsr = montoInicial - totalIsr;
	
	//Haciendo mi cantidad inicial
	precioOriginal = montoInicial - montoFinalIva - montoFinalIsr ;
	
	printf("\n El precio original sin impuestos es de: Q");
	printf("%f \n",precioOriginal);
	printf("\nPor el IVA se suma: Q ");
	printf("%f",totalIva);
	printf("\nPor el ISR se suma: Q ");
	printf("%f",totalIsr);
	//PARTE 6:FIN DEL CODIGO 
}
