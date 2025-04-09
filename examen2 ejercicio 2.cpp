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
		
		//rango de 1 a "numero" para que recorra
		int contador = 1;
		float resultado = 0.0;
		int exponente = 2; //elevacion de mi numero fijo "/2"
		
		while(contador <= numero){
			float aux = contador; //es como conversion de datos de entero a float
			resultado = resultado+(aux/2);
			printf("%s %d "," Termino ",contador);
			printf("/2");
			printf("= %.2f",aux/2);
			contador++;
		}
		
		printf("\n La sumatoria es: %0.2f",resultado);
		
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
