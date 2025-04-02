/*El colegio "Superhéroes" lo contrata para desarrollar una aplicación que 
convierta un número ingresado a letras, con la observación que el nombre 
del número debe ser en inglés. (Números de 0 a 100). Por ejemplo:
Número ingresado 5			Salida five
Número ingresado 11			Salida eleven*/

//PARTE 1: LIBRERIAS
#include <stdio.h>

//PARTE 2: DATOS/VARIABLES
int numeroIngles = 0;
int decena = 0;
int unidad = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa devuelve el número en letras del 0 al 100\n");
	printf("\nIngrese el número que desea evaluar: \n");
	scanf("%d",&numeroIngles);
	
	//comparo si entra en rango de 0 a 100, si no tira un mensaje
	if((numeroIngles >= 0) && (numeroIngles <= 100)){
		//escribo los número que son únicos, unidad, decena y centena
		if(numeroIngles == 0){
			printf("zero\n");
		}else if(numeroIngles == 1){
			printf("one\n");
		}else if(numeroIngles == 2){
			printf("two\n");
		}else if(numeroIngles == 3){
			printf("three\n");
		}else if(numeroIngles == 4){
			printf("four\n");
		}else if(numeroIngles == 5){
			printf("five\n");
		}else if(numeroIngles == 6){
			printf("six\n");
		}else if(numeroIngles == 7){
			printf("seven\n");
		}else if(numeroIngles == 8){
			printf("eight\n");
		}else if(numeroIngles == 9){
			printf("nine\n");
		}else if(numeroIngles == 10){
			printf("ten\n");
		}else if(numeroIngles == 11){
			printf("eleven\n");
		}else if(numeroIngles == 12){
			printf("twelve\n");
		}else if(numeroIngles == 13){
			printf("thirteen\n");
		}else if(numeroIngles == 14){
			printf("fourteen\n");
		}else if(numeroIngles == 15){
			printf("fifteen\n");
		}else if(numeroIngles == 16){
			printf("sixnteen\n");
		}else if(numeroIngles == 17){
			printf("seventeen\n");
		}else if(numeroIngles == 18){
			printf("eighteen\n");
		}else if(numeroIngles == 19){
			printf("nineteen\n");
		}else if(numeroIngles == 20){
			printf("twenty\n");
		}else if(numeroIngles == 30){
			printf("thirty\n");
		}else if(numeroIngles == 40){
			printf("forty\n");
		}else if(numeroIngles == 50){
			printf("fifty\n");
		}else if(numeroIngles == 60){
			printf("sixty\n");
		}else if(numeroIngles == 70){
			printf("seventy\n");
		}else if(numeroIngles == 80){
			printf("eighty\n");
		}else if(numeroIngles == 90){
			printf("ninety\n");
		}else if(numeroIngles == 100){
			printf("one hundred\n");
		}
		
		//Números compuestos, no exactos o especiales
		else{
			/*Analizo la decena de mi numero, obtengo parte entera, 40/10
			decena = 4*/
			decena = numeroIngles/10;
			/*Analizo la unidad de mi numero, la parte restante, 45/10
			unidad = 5*/
			unidad = numeroIngles%10;
			
			//evaluo decena
			if(decena == 2){
				printf("twenty\n");
			}else if(decena == 3){
				printf("tirty\n");
			}else if(decena == 4){
				printf("forty\n");
			}else if(decena == 5){
				printf("fifty\n");
			}else if(decena == 6){
				printf("sixty\n");
			}else if(decena == 7){
				printf("seventy\n");
			}else if(decena == 8){
				printf("eighty\n");
			}else if(decena == 9){
				printf("ninety\n");
			}
			
		//evaluo unidades
			printf("--");
			if(unidad == 1){
				printf("one\n");
			}else if(unidad == 2){
				printf("two\n");
			}else if(unidad == 3){
				printf("three\n");
			}else if(unidad == 4){
				printf("four\n");
			}else if(unidad == 5){
				printf("five\n");
			}else if(unidad == 6){
				printf("six\n");
			}else if(unidad == 7){
				printf("seven\n");
			}else if(unidad == 8){
				printf("eight\n");
			}else if(unidad == 9){
				printf("nine\n");
			}
			
			
		}
		
	} else{
		printf("El número esta fuera de rango");
	}
	//PARTE 6:FIN DEL CODIGO 
}	
