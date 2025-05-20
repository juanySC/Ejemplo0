/*Leer un carácter del teclado y comprobar si es una letra. 
	El programa solicita, y comprueba, que se teclee una letra.  */

#include <stdio.h>
#include <ctype.h>
int main()
{
	char inicial;
	printf("¿Cuál es su primer carácter inicial?: ");
	scanf("%c%*c",&inicial);
	while (!isalpha(inicial))
	{
		puts("Carácter no alfabético "); 
		printf("¿Cuál es su siguiente inicial?: "); 
		scanf("%c%*c",&inicial); 
	}
	puts("¡Terminado!");
	return 0;
}
