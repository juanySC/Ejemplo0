/*Una aplicaci�n de una variable static en una funci�n es la que permite obtener la serie de n�meros 
de Fibonacci. El ejercicio que se plantea es el siguiente: dado un entero n, obtener los n primeros 
n�meros de la serie de Fibonacci.
La secuencia de n�meros de Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13... (cada n�mero es la suma de los dos 
anteriores en la serie, excepto 0, 1, 1) se obtiene partiendo de los n�meros 0, 1 y a partir de ellos cada 
n�mero se consigue sumando los dos anteriores: 
an
= an-1 
+ an-2 
La funci�n fibonacci( ) que se escribe a continuaci�n, tiene dos variables static, x y y. Se 
inicializan x a 0 e y a 1; a partir de esos valores se calcula el t�rmino actual, y, dejando preparado x 
para la siguiente llamada. Al ser variables static mantienen el valor entre llamada y llamada. */

#include <stdio.h> 
long int fibonacci(void); 
int main() 
{ 
	int n,i; 
	printf("\nCuantos numeros de fibonacci ?: "); 
	scanf("%d",&n); 
	printf("\nSecuencia de fibonacci: 0,1"); 
	for (i = 2; i < n; i++) 
		printf(",%ld",fibonacci()); 
	return 0;
}
long int fibonacci(void)
{
	static int x = 0;
	static int y = 1;
	y = y + x;
	x = y - x;
	return y;
}
