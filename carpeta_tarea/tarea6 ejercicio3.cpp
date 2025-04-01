/*Ejercicio 3:Encontrar las raíces de una ecuación cuadrática, utilizando la fórmula
cuadrática, el usuario ingresa los coeficientes numéricos a, b y c, en la salida debe
indicarse todas las posibles raíces, incluyendo imaginarios.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
double a = 0;
double b = 0;
double c = 0;
double discriminanteReal = 0;
double formulaPositiva = 0;
double formulaNegativa = 0;
double respIgual = 0;
double imaginario = 0;
double primeraParte = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve las raices una ecuacion cuadratica \n");
		printf("De la forma ax^2+bx+c  = 0 \n");
		printf("Ingrese el valor a: \n");
		scanf("%lf",&a);
		printf("Ingrese el valor b: \n");
		scanf("%lf",&b);
		printf("Ingrese el valor c: \n");
		scanf("%lf",&c);
		
		//haciendo formula cuadratica con la discriminante
		discriminanteReal = (b*b) - (4*a*c);
		
		//poniendo que la "a" no sea cero porque se indefine
		if(discriminanteReal > 0){
			
			//completando formula cuadratica}
			formulaPositiva = ((-b) + sqrt(discriminanteReal)) / (2*a);
			formulaNegativa = ((-b) - sqrt(discriminanteReal)) / (2*a);
			
			//resultado con 5 decimales
			printf("\nLa primera raiz es:  %.5lf\n",formulaPositiva);
			printf("\nLa segunda raiz es: %.5lf\n",formulaNegativa);
		} else if(a == 0){
			printf("El numero da error");
		}else{
			//parte1 parte real
			primeraParte = (-b)/(2*a);
			//parte2 parte imaginaria
			imaginario = sqrt(-discriminanteReal) / (2 * a);
			
			printf("La parte real es: %lf",primeraParte);
			printf("La parte imaginaria es: %lf",imaginario);
		}
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');

	//PARTE 6:FIN DEL CODIGO 
}
