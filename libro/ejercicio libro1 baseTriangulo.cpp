#include <stdio.h>
float area_rectangulo(float b, float a);  
float entrada(void);     
/* declaraci�n */
/* prototipo o declaraci�n */
int main()
{
	float b, h; 
	printf("\n Base del rectangulo: ");
	b = entrada(); 
	printf("\n Altura del rectangulo: ");
	h = entrada(); 
	printf("\n Area del rectangulo: %.2f",area_rectangulo(b,h));
	return 0;
}
/* devuelve n�mero positivo */
float entrada()
{
	float m; 
	do {
		scanf("%f", &m);
	} while (m <= 0.0);
	return m;
}
/* calcula el area de un rect�ngulo */
float area_rectangulo(float b, float a)
{
	return (b*a);
}
