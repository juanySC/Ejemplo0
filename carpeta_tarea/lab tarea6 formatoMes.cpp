/*Ejercicio 12:ngresar el día, mes y año en el formato numérico (2-11-2022), 
para luego mostrarlo el formato: (2 /noviembre /2022)*/

//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
#include <conio.h>

//PARTE 2: DATOS/VARIABLES
int dia = 0;
int mes =0;
int anio = 0;
char continuar = 'n';

//PARTE 3: FUNCION PRINCIPAL

int main()
{
	//PARTE 4: INICIO DEL CODIDO
	
	do{	//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa devuelve la fecha escrita del mes \n");
		printf("Ingrese el año del formato dd:mm:aaaa \n");
		scanf("%d:%d:%d",&dia,&mes,&anio);
		
		
		// Imprimir el día
		printf("\n%d / ", dia);
		
		// Determinar el mes con switch
		switch (mes) {
			case 1:  printf("enero"); break;
			case 2:  printf("febrero"); break;
			case 3:  printf("marzo"); break;
			case 4:  printf("abril"); break;
			case 5:  printf("mayo"); break;
			case 6:  printf("junio"); break;
			case 7:  printf("julio"); break;
			case 8:  printf("agosto"); break;
			case 9:  printf("septiembre"); break;
			case 10: printf("octubre"); break;
			case 11: printf("noviembre"); break;
			case 12: printf("diciembre"); break;
			default: printf("Mes invalido"); return 1;
		}
		
		// Imprimir el año
		printf(" / %d\n", anio);
		//si desea volver a meter ecuacion cuadratica
		printf("\nDesea continuar con otra fecha s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar = 's');
	
	//PARTE 6:FIN DEL CODIGO 
}
