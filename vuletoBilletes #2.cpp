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
	
	printf("\n\t Q 100 \t%d", cambioCompra/100);
	cambioCompra = cambioCompra%100;
	
	printf("\n\t Q 50 \t%d", cambioCompra/50);
	cambioCompra = cambioCompra%50;
	
	printf("\n\t Q 20 \t%d", cambioCompra/20);
	cambioCompra = cambioCompra%20;
	
	printf("\n\t Q 10 \t%d", cambioCompra/10);
	cambioCompra = cambioCompra%10;
	
	printf("\n\t Q 5 \t%d", cambioCompra/5);
	cambioCompra = cambioCompra%5;
	
	printf("\n\t Q 1 \t%d", cambioCompra/1);
	cambioCompra = cambioCompra%1;
	//PARTE 6:FIN DEL CODIGO 
}
