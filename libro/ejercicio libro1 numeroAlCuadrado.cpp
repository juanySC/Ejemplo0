#include <stdio.h>
/* prototipo de la función cuadrado */
double cuadrado(double n);
int main() 
{ 
	double x = 11.5; 
	printf("%6.2lf al cuadrado = %8.4lf \n",x,cuadrado(x)); 
	return 0; 
}
double cuadrado(double n)
{
	return n*n;
}
