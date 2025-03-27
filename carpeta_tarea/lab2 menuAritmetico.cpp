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
int numero1 = 0;
int numero2 = 0;
int resultadoS = 0;
int resultadoR = 0;
int resultadoM = 0;
int resultadoD = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{
		//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa le dara un menu de opciones aritmetico\n ");
		printf("S: Sumar\n");
		printf("R: Restar\n");
		printf("M: multiplicar\n");
		printf("D: dividir\n");
		printf("Ingrese la literal que desee: \n");
		scanf("%c",&literal);
		
		//comparo con cada caracter 
		if(literal == sumar){
			
			printf("Ingrese el primer numero:\n ");
			scanf("%d",&numero1);
			printf("Ingrese el segundo numero:\n ");
			scanf("%d", &numero2);
			
			//operacion
			resultadoS = numero1 + numero2;
			printf("\nEl resultado de la suma es: ");
			printf("\n%d",resultadoS);
		} else if(literal == restar){
			
			printf("Ingrese el primer numero:\n ");
			scanf("%d",&numero1);
			printf("Ingrese el segundo numero:\n ");
			scanf("%d", &numero2);
			
			//operacion
			resultadoR = numero1 - numero2;
			printf("\nEl resultado de la resta es: ");
			printf("\n%d",resultadoR);
		} else if(literal == multiplicar){
			
			printf("Ingrese el primer numero:\n ");
			scanf("%d",&numero1);
			printf("Ingrese el segundo numero:\n ");
			scanf("%d", &numero2);
			
			//operacion
			resultadoM = numero1 * numero2;
			printf("\nEl resultado de la multiplicacion es: ");
			printf("\n%d",resultadoM);
		} else if(literal == dividir){
			
			printf("Ingrese el primer numero:\n ");
			scanf("%d",&numero1);
			printf("Ingrese el segundo numero:\n ");
			scanf("%d", &numero2);
			
			if (numero2 != 0) {
				resultadoD = numero1 / numero2;
				printf("\nEl resultado de la division es: %d\n", resultadoD);
			} else {
				printf("\nError: No se puede dividir entre 0.\n");
			}
			}else {
			printf("\nOpcion no valida, por favor intente de nuevo.\n");
		}
		
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
		
	}while(continuar == 's');//si continua dentro del ciclo
	//PARTE 6:FIN DEL CODIGO 
}
