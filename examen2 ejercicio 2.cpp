/*Ejercicio 2: elvacion de 1/2^1 + 2/2^2 + 3/2^3...*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int numero = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nEste programa indica la suma fraccionaria y el divisor elevado al exponente\n");
		printf("\nIngrese un valor para evaluar: \n");
		scanf("%d",&numero);
		
		//ariable local
		//rango de 1 a "numero" para que recorra
		int contador = 1;
		int dividendo = 2;
		float resultado = 0.0;
		int exponente = 1; //elevacion de mi numero fijo "/2"
		
		if(numero >= 0){
			while(contador<= numero){
				int exponente = 1;//cuantoas veces se va arepetir 
				int potencia = 1; //guarda el resultado de lo elevado
				
				while(exponente <= contador){
					potencia = potencia * dividendo;
					exponente++;
				}
				
				float aux = (float)contador/potencia; //es como conversion de datos de entero a float
				//elevando mi numero divisor a 2
				
				resultado = resultado+aux;
				printf("Termino %d: %d/2^%d = %.4f",contador, contador, contador, resultado);
				printf("/%d",dividendo);
				printf("= %.2f",aux/dividendo);
				contador++;
			}
			
			
			
			printf("\n La sumatoria es: %0.2f",resultado);
		} else{
			printf("Ingrese un numero mayor a 0");
		}
	

		
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
