//usamos para los comentarios
//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>

//PARTE 2: DATOS/VARIABLES
int base = 0;
int altura = 0;
float area = 0;

//PARTE 3: FUNCION PRINCIPAL

	int main()
//PARTE 4: INICIO DEL CODIDO
	{

//PARTE 5: INSTRUCCIONES O CODIGO
		printf("Este programa calcula el area de un triangulo \n");
		printf("Ingrese la magnitud de la base: \n");
		scanf("%d",&base);
		printf("Ingrese la magnitud de la altura: \n");
		scanf("%d",&altura);
		area = base * altura * 0.5;
		printf("El area calculada es: ");
		printf("%f",area);
//PARTE 6:FIN DEL CODIGO 
	}
