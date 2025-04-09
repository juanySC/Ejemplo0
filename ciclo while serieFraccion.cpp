/*Ejercicio 5: Pedir al usuario un número N, luego mostrar el resultado de 
la siguiente serie:
Resultado = 1/1+1/2+1/3+.....+ 1/(n-1)+1/n
Por ejemplo, si el usuario ingresa el valor N=5, el resultado sería
Resultado<- 1/1+1/2+1/3+1/4+1/5	*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int n;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese un valor para evaluar\n");
		scanf("%d",&n);
		
		//rango de valor 1...n
		int contador = 1;
		float resultado = 0.0;
		
		while(contador <= n){
			float aux = contador; //es como conversion de datos de entero a float
			resultado = resultado+(1/aux);
			printf("\n%s %d"," Termino = 1/",contador);
			printf("= %.2f",1/aux);
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
