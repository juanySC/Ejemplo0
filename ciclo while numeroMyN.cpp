/*Ejercicio 2: Leer dos números N y M, asegurarse que N sea mucho menor que M,
 mostrar como salida la suma de los números comprendidos entre N y M así como
 el promedio de dichos números.
Rango abierto : no incluimos N ni M*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int n= 0;
int m = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL
//generar una serie de numeros 1...n
int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		
		//solicitando datos
		printf("\nIngrese el primer valor\n");
		scanf("%d",&n);
		printf("\nIngrese el segundo valor\n");
		scanf("%d",&m);
		
		int contador =n+1;
		int suma = 0;
		
		while(contador < m){
			printf("%3d", contador);
			suma = suma+contador;
			contador++;
		}
		
		//n=10
		//m=25
		float cnt = contador - n-1;
		printf("\nLa suma del número dado es: %d\n",suma);
		printf("\nLa promedio del número dado es: %.2f\n",suma/cnt);
		
		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
