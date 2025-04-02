/*Ejercicio 2:Leer un número de tres dígitos y mostrar como salida los dígitos
invertidos del número, por ejemplo si la entrada es 725 la salida es 527*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int num1 = 0;
int inverso = 0;
int centena = 0;
int decena = 0;
int unidad = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve los números contrario a como se recibio \n");
		printf("Ingrese el valor de 3 digitos: \n");
		scanf("%d",&num1);
		
		//dejando rango en que se puede trabajar
		if((num1 >= 100)&&(num1 <= 999)){
			centena = num1/100; //obtengo mi primer digito 200/100 = 2
			decena = (num1/10)%10; //obtengo mi decena y luego obtengo el residuo  
			unidad = num1%10; //toma el ultimo numero ya que hace el redifuo
		}
		
		//invierto		centena		decena	unidad
		inverso = (unidad*100)+(decena*10)+centena;
		
		//resultado
		printf("El número inverso es: %d", inverso);
		
		//si desea volver a comparar numeros o se sale
		printf("\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');//si continua dentro del ciclo

	//PARTE 6:FIN DEL CODIGO 
}
