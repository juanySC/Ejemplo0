/*Se genera un menú de operaciones aritméticas:
‘S’: Sumar
‘R’: Restar
‘M’: Multiplicar
‘D’: Dividir
Pedir al usuario que seleccione por medio del ingreso de la letra inicial la opción que
desea ejecutar, luego solicitar dos números y mostrar el resultado de la operación. Por
ejemplo si el usuario elige: Sumar, y los dos números ingresados son 5 y 7, el resultado
de salida es 12 (la suma de los dos números).*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
char sumar = 'S';
char restar = 'R';
char multiplicar = 'M';
char dividir = 'D';
char literal;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa le dara un menu de opciones aritmetico ");
		printf("S: Sumar");
		printf("R: Restar");
		
		printf("Ingrese la literal que desee: ");
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
		
	}while(continuar == 's');//si continua dentro del ciclo
	//PARTE 6:FIN DEL CODIGO 
}
