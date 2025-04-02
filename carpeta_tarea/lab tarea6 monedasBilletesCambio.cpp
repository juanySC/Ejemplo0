/*Solicitar que el usuario indique una cantidad de venta y el efectivo pagado, 
como salida el programa debe indicar una combinación de billetes de Quetzal 
que se le pueden dar como cambio al comprador, por ejemplo si la venta es de 
Q 17.00 y el efectivo con el que se paga es de Q100, una forma de dar el cambio
 es: 1 billete de Q50.00, 1 billete de Q20.00, 1 billete de Q10.00 y 3 billetes
 de Q1.00, lo cual da un total de Q83.00. Para este ejemplo incluir vuelto con
 decimales, es decir también indicar las monedas y de que denominación se deben
 dar en el cambio así como la cantidad.. */

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES 
float compra = 0;
float efectivoCompra = 0;
float cambioCompra = 0;
int centavos=0;
int billete100, billete50, billete20, billete10, billete5, billete1;
int moneda1, moneda50, moneda25, moneda10, moneda05;
char condicion = 'n';
//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa calcula la transaccion de un articulo \n");
		printf("Ingrese la cantidad total de la compra: \n");
		scanf("%f",&compra);
		printf("Ingrese el efectivo recibido \n");
		scanf("%f",&efectivoCompra);
		
		//formula del vuelto que se desea retornar
		cambioCompra =  efectivoCompra - compra;
		
		//por si el efectivo es menor que la compra
		if(cambioCompra < 0){
			printf("El efectivo recibido es insuficiente");
		}
		
		//cambio
		printf("\n El vuelto que debe dar es:  Q ");
		printf("%.2f",cambioCompra); //solo tomo dos decimales
		
		/*hago cambio de float a int para no generar errores 
		(casting)  conversión de un tipo de dato a otro
		Q1 tinene 100 centavos*/
		centavos = (int)(cambioCompra*100);
		
		//Q1 tinene 100 centavos
		
		billete100 = centavos/10000;
		centavos = centavos % 10000;
		
		billete50 = centavos/5000;
		centavos = centavos % 5000;
		
		billete20 = centavos/2000;
		centavos = centavos % 2000;
		
		billete10 = centavos/1000;
		centavos = centavos % 1000;
		
		billete5 = centavos/500;
		centavos = centavos % 500;
		
		//comienzo con monedas
		moneda1 = centavos/100;
		centavos = centavos % 100;
		
		moneda50 =centavos/50;
		centavos = centavos % 50;
		
		moneda25 = centavos/25;
		centavos = centavos % 25;
		
		moneda10 = centavos/10;
		centavos = centavos % 10;
		
		moneda05 = centavos/5;
		centavos = centavos % 5;
		
		//imprimo lo que se debe de regresar de vuelto
		/*se pone if solo para imprimir lo que se dara de vuelto y no sea tan
		abrumador con todos los billetes y monedas*/
		
		printf("\n\nLos valores de los billetes son: ");
		if (billete100 > 0) printf("\nQ 100: %d\n", billete100);
		if (billete50 > 0) printf("Q 50: %d\n", billete50);
		if (billete20 > 0) printf("Q 20: %d\n", billete20);
		if (billete10 > 0) printf("Q 10: %d\n", billete10);
		if (billete5 > 0) printf("Q 5: %d\n", billete5);
		
		printf("\n\nLos valores de las monedas son: ");
		if (moneda1 > 0) printf("\nQ 1: %d\n", moneda1);
		if (moneda50 > 0) printf("C 0.50: %d\n", moneda50);
		if (moneda25 > 0) printf("C 0.25: %d\n", moneda25);
		if (moneda10 > 0) printf("C 0.10: %d\n", moneda10);
		if (moneda05 > 0) printf("C 0.05: %d\n", moneda05);
		
		//si desea volver a dar vuelto o se sale
		printf("\nDesea continuar con otro monto s/n");
		condicion=getch();//Para asignar a una variable char
		printf("\n");
	}while(condicion == 's');
	
	//PARTE 6:FIN DEL CODIGO 
} 
