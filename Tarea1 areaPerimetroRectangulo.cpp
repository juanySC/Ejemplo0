
//Ejercicio 3: Pedir como datos de entrada, la magnitud de los lados de
// un rect�ngulo y luego generar como salida el �rea del mismo y su per�metro
	
//PARTE 1: LIBRERIAS
#include <stdio.h>
#include <math.h>
	
//PARTE 2: DATOS/VARIABLES
float baseR = 0;
float alturaR = 0;
float areaRectangulo = 0;
float perimetroRectangulo = 0;

//PARTE 3: FUNCION PRINCIPAL

int main()
	//PARTE 4: INICIO DEL CODIDO
{
	//PARTE 5: INSTRUCCIONES O CODIGO
	printf("Este programa calcula el �rea y per�metro de un rect�ngulo \n");
	printf("Ingrese el valor de la base: \n");
	scanf("%f",&baseR);
	printf("Ingrese el valor de la altura: \n");
	scanf("%f", &alturaR);
	
	//formula del area del rectangulo
	areaRectangulo = baseR * alturaR;
	
	//formula del perimetro del rectangulo
	perimetroRectangulo = (2*baseR) + (2*alturaR);
	
	printf("\n El �rea del rect�ngulo es: \n");
	printf("%f \n",areaRectangulo);
	printf("El perimetro del rect�ngulo es: \n");
	printf("%f \n",perimetroRectangulo);
	//PARTE 6:FIN DEL CODIGO 
}
