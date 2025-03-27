/*Se requiere implementar un programa que permita realizar conversiones de
longitud, tiempo y masa. Construya un menú que permita resolver lo siguiente
Conversión de longitud
Metros a yardas
Kilómetros a millas
Centímetros a pulgadas
Pies a metros
Conversión de tiempo
Días a segundos
Minutos a horas
Semanas a horas
Meses a minutos
Conversión de masa
Kilogramos a libras
Onzas a gramos
Libras a onzas
Toneladas a kilogramos*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int opcion = 0;
int subOpcion = 0;
char continuar = 'n';
int numero = 0;
float resultado = 0;

//conversiones de longitud
float yarda = 1.09361;
float milla = 0.621371;
float pulgada = 0.393701;
float metro = 0.3048;

//conversiones de tiempo
float segundo = 86400;
float minutoHora = 0.0166667;
float semanaHora = 168;
float minutos = 43800;

//conversion de masa
float libra = 2.20462;
float gramo = 28.3495;
float onza = 16;
float kilogramo = 1000;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		
		printf("Este programa le dara un menu de opciones del tiempo y masa\n ");
		printf("1: Conversion de longitud\n");
		printf("2: Conversion de tiempo\n");
		printf("3: Conversion de masa\n");
		printf("4: Salir\n");
		printf("Ingrese la opcion que desee: \n");
		scanf("%d",&opcion);
		
		//comparo con cada caracter 
		if(opcion == 1){
			printf("1: Metros a yardas\n");
			printf("2: Kilómetros a millas\n");
			printf("3: Centímetros a pulgadas\n");
			printf("4: Pies a metros\n");
			printf("Ingrese la opcion que desee: \n");
			scanf("%d",&subOpcion);
			
			//pidiendo que ingrese numero para la conversion
			printf("\nIngrese el valor a evaluar\n");
			scanf("%d",&numero);
			//empezando con las conversiones
			if(subOpcion == 1){
				resultado = yarda * numero;
				printf("El resultado en yardas es: %f \n", resultado);
			}else if(subOpcion == 2){
				resultado = milla * numero;
				printf("El resultado en millas es: %f \n", resultado);
			}else if(subOpcion == 3){
				resultado = pulgada * numero;
				printf("El resultado en pulgadas es: %f \n", resultado);
			}else if(subOpcion == 4){
				resultado = minutos * numero;
				printf("El resultado en metros es: %f \n", resultado);
			}
			
		} else if(opcion == 2){
			printf("1: Días a segundos\n");
			printf("2: Minutos a horas\n");
			printf("3: Semanas a horas\n");
			printf("4: Meses a minutos\n");
			printf("Ingrese la opcionque desee: \n");
			scanf("%d",&subOpcion);
			
			//pidiendo que ingrese numero para la conversion
			printf("\nIngrese el valor a evaluar\n");
			scanf("%d",&numero);
			//empezando con las conversiones
			if(subOpcion == 1){
				resultado = segundo * numero;
				printf("El resultado en segundos es: %f \n", resultado);
			}else if(subOpcion == 2){
				resultado = minutoHora * numero;
				printf("El resultado en horas es: %f \n", resultado);
			}else if(subOpcion == 3){
				resultado = semanaHora * numero;
				printf("El resultado en horas es: %f \n", resultado);
			}else if(subOpcion == 4){
				resultado = metro * numero;
				printf("El resultado en minutos es: %f \n", resultado);
			}
			
		} else if(opcion == 3){
			printf("1: Kilogramos a libras\n");
			printf("2: Onzas a gramos\n");
			printf("3: Libras a onzas\n");
			printf("4: Toneladas a kilogramos\n");
			printf("Ingrese la opcion que desee: \n");
			scanf("%d",&subOpcion);
			
			//pidiendo que ingrese numero para la conversion
			printf("\nIngrese el valor a evaluar\n");
			scanf("%d",&numero);
			//empezando con las conversiones
			if(subOpcion == 1){
				resultado = libra * numero;
				printf("El resultado en libras es: %f \n", resultado);
			}else if(subOpcion == 2){
				resultado = gramo * numero;
				printf("El resultado en gramos es: %f \n", resultado);
			}else if(subOpcion == 3){
				resultado = onza * numero;
				printf("El resultado en onza es: %f \n", resultado);
			}else if(subOpcion == 4){
				resultado = kilogramo * numero;
				printf("El resultado en kilogramos es: %f \n", resultado);
			}
			
		} 
		
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
		
		
	}while(continuar == 's');//si continua dentro del ciclo
	//PARTE 6:FIN DEL CODIGO 
}
