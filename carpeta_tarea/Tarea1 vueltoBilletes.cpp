/*En la transacción de pago por la compra de un artículo, se genera un cambio
 o “vuelto”, se requiere conocer la cantidad de billetes de circulación 
normal equivalentes a dicha cantidad. */

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES 
int compra = 0;
int efectivoCompra = 0;
int cambioCompra = 0;
int billete100, billete50, billete20, billete10, billete5, billete1;
//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula la transaccion de un articulo \n");
	printf("Ingrese la cantidad total de la compra: \n");
	scanf("%d",&compra);
	printf("Ingrese el efectivo recibido \n");
	scanf("%d",&efectivoCompra);
	
	//formula del vuelto que se desea retornar
	cambioCompra =  efectivoCompra - compra;
	
	printf("\n El vuelto que debe dar es:  Q ");
	printf("%d",cambioCompra);
	
	//Apartado de los valores del billetes Q100, Q50, Q25,Q10, Q5 Y Q1
	printf("\n\nLos valores de los billetes son: ");
	
	billete100 = cambioCompra/100;
	cambioCompra = cambioCompra % 100;
	printf("\nQ 100 = \n");
	printf("%d", billete100);
	
	billete50 = cambioCompra/50;
	cambioCompra = cambioCompra % 50;
	printf("\nQ 50 = \n");
	printf("%d", billete50);
	
	billete20 = cambioCompra/20;
	cambioCompra = cambioCompra % 20;
	printf("\nQ 20 = \n");
	printf("%d", billete20);
	
	billete10 = cambioCompra/10;
	cambioCompra = cambioCompra % 10;
	printf("\nQ 10 = \n");
	printf("%d", billete10);
	
	billete5 = cambioCompra/5;
	cambioCompra = cambioCompra % 5;
	printf("\nQ 5 = \n");
	printf("%d", billete5);
	
	billete1 = cambioCompra/1;
	cambioCompra = cambioCompra % 1;
	printf("\nQ 1 = \n");
	printf("%d", billete1);

	
	//PARTE 6:FIN DEL CODIGO 
}
