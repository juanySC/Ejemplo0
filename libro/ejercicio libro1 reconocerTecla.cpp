/*Leer un car�cter del teclado y comprobar si es una letra. 
	El programa solicita, y comprueba, que se teclee una letra.  */

#include <stdio.h>
#include <ctype.h>
int main()
{
	char inicial;
	printf("�Cu�l es su primer car�cter inicial?: ");
	scanf("%c%*c",&inicial);
	while (!isalpha(inicial))
	{
		puts("Car�cter no alfab�tico "); 
		printf("�Cu�l es su siguiente inicial?: "); 
		scanf("%c%*c",&inicial); 
	}
	puts("�Terminado!");
	return 0;
}
