/*Ejercicio 5:Leer dos fechas en formato aaaa/mm/dd, e indicar cuántos días
 hay entre las dos fechas. (asuma que todos los meses tienen 30 días y que 
no hay años bisiestos)*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int anio1 = 0;
int mes1 = 0;
int dia1 = 0;
int anio2 = 0;
int mes2 = 0;
int dia2 = 0;
int diferencia1 = 0;
int diferencia2 = 0;
int fecha1 = 0;
int fecha2 = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve la diferencia de dias de las fechas \n");
		printf("Ingrese en formato aa:mm:dd \n");
		printf("Ingrese la primera fecha : \n");
		scanf("%d:%d:%d",&anio1,&mes1,&dia1);
		printf("Ingrese la segunda fehca: \n");
		scanf("%d:%d:%d",&anio2,&mes2,&dia2);
		
		//fechas por dias
		fecha1 = (anio1*365) + (mes1*30) + dia1;
		fecha2 = (anio2*365) +(mes2*30) + dia2;

		//si mi fecha 2 es mayor a la fecha 1
		if(fecha2>fecha1){
			//diferencia 
			diferencia1 = fecha2 - fecha1;
			printf("Los dias entre ambas fechas es: %d", diferencia1);
		} else if(fecha1>fecha2){
			diferencia2 = fecha1 - fecha2;
			printf("Los resultados de ambas fechas es: %d ",diferencia2);
		} else if(fecha1 == fecha2){
			printf("El dia no se puede restar porque el dia es actual");
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
}
	
	//PARTE 6:FIN DEL CODIGO 
