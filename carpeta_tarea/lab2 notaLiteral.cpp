/*Se lee una nota en formato literal: A, B, C, D, E, indicar como salida un mensaje
que corresponda al estudiante..*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
char primer = 'A';
char segundo = 'B';
char tercero = 'C';
char cuarto = 'D';
char quinto = 'E';
char literal;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa le dara un menu de opciones aritmetico \n");
		printf("Eliga la opción que desee: A, B, C, D, E\n");

		scanf("%c",&literal);
		
		//comparo con cada caracter 
		
		if(literal == primer){
			printf("\nFelcidades");
		} else if(literal == segundo){
			printf("\nExcelente");
		} else if(literal == tercero){
			printf("\nMuy bien");
		} else if(literal == cuarto){
			printf("\nDebe mejorar");
		}else if(literal == quinto){
			printf("\nDebe esforzarse mas");
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
		
	}while(continuar == 's');//si continua dentro del ciclo
	//PARTE 6:FIN DEL CODIGO 
}
