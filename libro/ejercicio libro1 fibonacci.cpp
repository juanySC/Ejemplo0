/*Una aplicación de una variable static en una función es la que permite obtener la serie de números 
de Fibonacci. El ejercicio que se plantea es el siguiente: dado un entero n, obtener los n primeros 
números de la serie de Fibonacci.
La secuencia de números de Fibonacci: 0, 1, 1, 2, 3, 5, 8, 13... (cada número es la suma de los dos 
anteriores en la serie, excepto 0, 1, 1) se obtiene partiendo de los números 0, 1 y a partir de ellos cada 
número se consigue sumando los dos anteriores: 
an
= an-1 
+ an-2 
La función fibonacci( ) que se escribe a continuación, tiene dos variables static, x y y. Se 
inicializan x a 0 e y a 1; a partir de esos valores se calcula el término actual, y, dejando preparado x 
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
