/*Se requiere que escriba un programa que permita leer un número entre 1 a 
100,000 y luego de como salida el equivalente en letras. Deberá aplicar 
instrucciones de selección y operadores aritméticos.
Ejemplo de entrada 1
Ejemplo de salida uno
Ejemplo de entrada 21                 Ejemplo de salida Veinte y uno*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero = 0;
int centena = 0;
int decena = 0;
int unidad = 0;
char condicion = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve el número en letras del 1al 100000\n");
		printf("\nIngrese el número que desea evaluar: \n");
		scanf("%d",&numero);
		
		//comparo si entra en rango de 0 a 100, si no tira un mensaje
		if((numero < 1) || (numero  > 100000)){
			printf("\nEl número esta fuera de rango\n");
		}
	
		//numeros para obtener 100 = 1
		centena = (numero%1000)/100;
		//Números compuestos, no exactos o especiales
		/*Analizo la decena de mi numero, obtengo parte entera, 40/10
		decena = 4*/
		decena = (numero%100)/10;
		/*Analizo la unidad de mi numero, la parte restante, 45/10
		unidad = 5*/
		unidad = numero%10;
		
		printf("\nEl número en letras es: \n");
		
		//evaluo mi centena
		if(centena > 0 ){ //ya que si no seria una decena por eso evaluo 0
			switch(centena){
			case 1: printf("cien\n"); break;
			case 2: printf("doscientos\n"); break;
			case 3: printf("trescientos\n"); break;
			case 4: printf("cuatrocientos\n"); break;
			case 5: printf("quiñentos\n"); break;
			case 6: printf("seiscientos\n"); break;
			case 7: printf("setecientos\n"); break;
			case 8: printf("ochocientos\n"); break;
			case 9: printf("novecientos\n"); break;
			}
		}
		
		
		//evaluo decena
		if(decena == 1){
			//nuemros especiales
			switch(unidad){
			case 10: printf("diez\n"); break;
			case 11: printf("once\n"); break;
			case 12: printf("doce\n"); break;
			case 13: printf("trece\n"); break;
			case 14: printf("catorce\n"); break;
			case 15: printf("quince\n"); break;
			case 16: printf("dieci seis\n"); break;
			case 17: printf("sieci siete\n"); break;
			case 18: printf("dieciocho\n"); break;
			case 19: printf("diecinueve\n"); break;
			}
		}else{
			switch(decena){
			case 2: printf("veinte\n"); break;
			case 3: printf("treinta\n"); break;
			case 4: printf("cuarenta\n"); break;
			case 5: printf("cincuenta\n"); break;
			case 6: printf("sesenta\n"); break;
			case 7: printf("setenta\n"); break;
			case 8: printf("ochenta\n"); break;
			case 9: printf("noventa\n"); break;
			}
		}
		
		//evaluo unidades
		if(unidad!=0){
			printf("- y ");
			switch(unidad){
			case 1: printf("uno\n"); break;
			case 2: printf("dos\n"); break;
			case 3: printf("tres\n"); break;
			case 4: printf("cuatro\n"); break;
			case 5: printf("cinco\n"); break;
			case 6: printf("seis\n"); break;
			case 7: printf("siete\n"); break;
			case 8: printf("ocho\n"); break;
			case 9: printf("nueve\n"); break;
			}
		}
		
		//preguntar al usuario si desea seguir evaluando numeros en ingles
		printf("\nDesea continuar evaluando numeros s/n");
		condicion = getch(); //asigna la variable de caracter
		printf("\n");
	}while(condicion == 's');
	
	//PARTE 6:FIN DEL CODIGO 
}	
