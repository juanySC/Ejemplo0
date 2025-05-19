#include <stdio.h>
float area_rectangulo(float b, float a);  
float entrada(void);     
/* declaración */
/* prototipo o declaración */
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
/* devuelve número positivo */
float entrada()
{
	float m; 
	do {
		scanf("%f", &m);
	} while (m <= 0.0);
	return m;
}
/* calcula el area de un rectángulo */
float area_rectangulo(float b, float a)
{
	return (b*a);
}
