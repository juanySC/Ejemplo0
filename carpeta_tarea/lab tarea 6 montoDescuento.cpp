/*Ejercicio 10: Dado el monto de una compra calcular el descuento considerado
 lo siguiente:
c. No hay descuento si el monto es menor Q50.00.
d. Descuento es 10% si el monto es menor a Q 100.00 y mayor o igual a Q50.00.
e. Descuento es 20% si el monto es menor a Q500.00 y mayor o igual a Q100.00
f. Descuento del 30% si el monto es mayor a Q500.00.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int dinero= 0;
float totalDescuento = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa calcula el descuento del monto\n");
		printf("Ingrese el monto \n");
		scanf("%d",&dinero);
		
		//hasta tres minutos
			if(dinero < 50){
				printf("No hay descuento");
			} else if((dinero > 50) && (dinero < 100)){
				//formula
				totalDescuento = dinero * 0.1;
				printf("El descuento total es: Q %.2f", totalDescuento);
			} else if((dinero >= 100)&&(dinero < 500)){
				//formula
				totalDescuento = dinero * 0.2;
				printf("El descuento total es: Q %.2f", totalDescuento);
			}else if(dinero >500){
				//formula
				totalDescuento = dinero * 0.3;
				printf("El descuento total es: Q %.2f", totalDescuento);
			} else if(dinero <= 0){
				printf("No se puede realizar ninguna operacion");
			}
	
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
