/*Es necesario que se pueda generar un traductor de números a inglés, 
el usuario ingresa un número comprendido de 1 a 99 y debe mostrarse en letras 
los números en inglés.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numeroIngles = 0;
int decena = 0;
int unidad = 0;
char condicion = 'n';
	
//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve el número en letras del 1 al 99\n");
		printf("\nIngrese el número que desea evaluar: \n");
		scanf("%d",&numeroIngles);
		
		//comparo si entra en rango de 0 a 100, si no tira un mensaje
		if((numeroIngles < 1) || (numeroIngles  > 99)){
			printf("\nEl número esta fuera de rango\n");
		}

		if((numeroIngles>= 10 )&&(numeroIngles <= 19)){
			//escribo los número que son únicos, unidad, decena y centena
			switch(numeroIngles){
			case 10: printf("ten\n"); break;
			case 11: printf("eleven\n"); break;
			case 12: printf("twelve\n"); break;
			case 13: printf("thirteen\n"); break;
			case 14: printf("fourteen\n"); break;
			case 15: printf("fifteen\n"); break;
			case 16: printf("sixteen\n"); break;
			case 17: printf("seventeen\n"); break;
			case 18: printf("eighteen\n"); break;
			case 19: printf("nineteen\n"); break;
			}
		}

			
			//Números compuestos, no exactos o especiales
				/*Analizo la decena de mi numero, obtengo parte entera, 40/10
				decena = 4*/
				decena = numeroIngles/10;
				/*Analizo la unidad de mi numero, la parte restante, 45/10
				unidad = 5*/
				unidad = numeroIngles%10;
				
				printf("\nEl número en inglés es: \n");
				
				//evaluo decena
				switch(decena){
				case 2: printf("twenty\n"); break;
				case 3: printf("thirty\n"); break;
				case 4: printf("forty\n"); break;
				case 5: printf("fifty\n"); break;
				case 6: printf("sixty\n"); break;
				case 7: printf("seventy\n"); break;
				case 8: printf("eighty\n"); break;
				case 9: printf("ninety\n"); break;
				}
				
				//evaluo unidades
				if(unidad!=0){
					printf("--");
					switch(unidad){
					case 1: printf("one\n"); break;
					case 2: printf("two\n"); break;
					case 3: printf("three\n"); break;
					case 4: printf("four\n"); break;
					case 5: printf("five\n"); break;
					case 6: printf("six\n"); break;
					case 7: printf("seven\n"); break;
					case 8: printf("eight\n"); break;
					case 9: printf("nine\n"); break;
					}
				}
		
		//preguntar al usuario si desea seguir evaluando numeros en ingles
		printf("\nDesea continuar evaluando numeros en ingles s/n");
		condicion = getch(); //asigna la variable de caracter
		printf("\n");
	}while(condicion == 's');
	
	//PARTE 6:FIN DEL CODIGO 
}	
