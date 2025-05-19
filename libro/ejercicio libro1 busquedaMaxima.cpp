#include <stdio.h>
#include <stdarg.h>
void maximo(int n,...); 
int main(void) 
{
	puts("\t\tPRIMERA BUSQUEDA DEL MAXIMO\n");
	maximo(6,3.0,4.0,-12.5,1.2,4.5,6.4);
	puts("\n\t\tNUEVA BUSQUEDA DEL MAXIMO\n");
	maximo(4,5.4,17.8,5.9,-17.99);
	return 0;
}
void maximo(int n, ...) 
{
	double mx,actual;
	va_list puntero;
	int i;
	va_start(puntero,n);
	mx = actual = va_arg(puntero,double);
	printf("\t\tArgumento actual: %.2lf\n",actual);
	for (i = 2; i <= n; i++)
	{
		actual = va_arg(puntero,double);
		printf("\t\tArgumento actual: %.2lf\n",actual);
		if (actual > mx)
		{
			mx = actual;
		}
	}
	printf("\t\tMáximo de la lista de %d números: %.2lf\n",n,mx);
	va_end(puntero);
}
