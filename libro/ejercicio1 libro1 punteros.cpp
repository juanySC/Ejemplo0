#include <stdio.h>
#include <math.h> 
void potrat1(double x, double y);
void potrat2(double* x, double* y); 
int main() 
{ 
	double a, b; 
	a = 5.0; b = 1.0e2; 
	potrat1(a, b); 
	printf("\n a = %.1f b = %.1lf",a,b); 
	potrat2(&a, &b); 
	printf("\n a = %.1f b = %.1lf",a,b);
	return 0;
}
void potrat1(double x, double y) 
{ 
	x = x*x; 
	y = sqrt(y); 
} 
void potrat2(double* x, double* y) 
{ 
	*x = (*x)*(*x); 
	*y = sqrt(*y); 
} 
