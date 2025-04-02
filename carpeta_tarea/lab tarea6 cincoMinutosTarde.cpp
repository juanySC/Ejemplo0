/*Ejercicio 6: Leer la hora actual y dar como salida la misma hora pero 
cinco minutos más tarde, tome en cuenta horas, minutos y segundos.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int hora1 = 0;
int minuto1 = 0;
int segundo1 = 0;
int suma = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve la hora 5 minutos despues\n");
		printf("Ingrese en formato hh:mm:ss \n");
		scanf("%d:%d:%d",&hora1,&minuto1,&segundo1);

		
		//suma de 5 minutos
		minuto1 += 5;
		
		// se vuelve a reiniciar si llega a 60
		if (minuto1 >= 60) {
			minuto1 -= 60;
			hora1 += 1;
		}
		//se vuelve a iniciar en formato de 00 a 24 horas
		if (hora1 >= 24) {
			hora1 = 0;
		}
		printf("La hora 5 minutos despues es: %d:%d:%d", hora1, minuto1, segundo1);
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
