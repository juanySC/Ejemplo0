/*Ejercicio 4:Solicite que el usuario ingrese 2 horas, en formato hh,mm,ss; 
reste los datos ingresados (asegurando que la primera hora es menor a la 
segunda) y devuelva el resultado (de la diferencia entre las dos horas) en 
segundos.*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int hora1 = 0;
int minuto1 = 0;
int segundo1 = 0;
int hora2 = 0;
int minuto2 = 0;
int segundo2 = 0;
int diferencia = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve las resta de las horas \n");
		printf("Ingrese en formato hh:mm:ss \n");
		printf("Ingrese la primera hora : \n");
		scanf("%d:%d:%d",&hora1,&minuto1,&segundo1);
		printf("Ingrese la segunda hora: \n");
		scanf("%d:%d:%d",&hora2,&minuto2,&segundo2);
		
		//pasando todo a segundos 
		hora1 = (hora1*3600) + (minuto1*60)+segundo1;
		hora2 = (hora2*3600) + (minuto2*60)+segundo2;
		
		//asegurando que la primera hora sea menor que la segunda hora
		if(hora2>hora1){
			//formula de diferencia
			diferencia = hora2 - hora1;
			printf("\nLa diferencia de las horas en segundos es: %d s",diferencia);
		}else{
			printf("\nLa resta no puede realizarse");
		}

		//si desea volver a comparar numeros o se sale
		printf("\n\nDesea continuar con otro numero s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
