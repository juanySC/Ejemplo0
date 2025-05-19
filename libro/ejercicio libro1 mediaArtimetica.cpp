#include <stdio.h> 
double media(double x1, double x2) //como son numeros reales utitizo double
{
	return(x1 + x2)/2; //evaluo ambos numeros ylos sumpo
}
int main() 
{ 
	double num1, num2, med; 
	printf("Introducir dos números reales:");
	scanf("%lf %lf",&num1,&num2); //obtengo los datos
	med = media(num1, num2); //paso los argumentos para poder devolver los valores
	printf("El valor medio es %.4lf \n", med);
	return 0;
}
