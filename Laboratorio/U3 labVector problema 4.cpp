/*Se   requiere   que   se   llene   un   vector   de   20   espacios,   con  
 caracteres alfanuméricos en minúsculas, luego mostrar las siguientes estadísticas:
a) Cantidad de vocales
b) Cantidad de consonantes
c) Cantidad de dígitos
d) Cantidad de símbolos*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#define NUM 20

char continuar = 'n';

int main() {
	do{
		char caracteres[20];
		int vocales = 0, consonantes = 0, simbolos = 0, digitos = 0;
		
		//generando de manera aleatorio
		srand(unsigned(time(NULL)));
		for (int i = 0; i < NUM; i++) {
			/*genero mis caracteres con codigo ascii y lo hare con opciones 
			ya que no tomo en cuenta las mayusculas*/
			int caracterAleatorio = rand()%3;
			//hago mi comparacion
			if(caracterAleatorio == 0){
				//numeros
				caracteres[i] = rand() % 10 + 48; 
			} else if(caracterAleatorio == 1){
				//abecedario en minusculo
				caracteres[i] = rand() % 26 + 97; 
			} else{
				//incluyo los simbolos pero como quiero incluir mas rango
				//porque los simbolos estan separados en la tabla ascii
				int simboloDistinto = rand()%3;
				
				if(simboloDistinto == 0){
					caracteres[i] = rand() % 15 + 33;
				} else if(simboloDistinto == 1){
					caracteres[i] = rand() % 7 + 58;
				} else{
					caracteres[i] = rand() % 6 + 91;
				}
				 
			}
			
			printf("\n\n %1s %2d %3s \t","{",i,"}");
			printf("%3c ", caracteres[i]); //imprimo mi caracter
			
			//para leer las vocales mayusculas y minusculas por igual "tolower"
			char comparoCaracter = tolower(caracteres[i]);
			
			if ((comparoCaracter >= 'a' && comparoCaracter <= 'z')) {
				if (comparoCaracter == 'a' || comparoCaracter == 'e' || comparoCaracter == 'i' || comparoCaracter == 'o' || comparoCaracter == 'u') vocales++;
				else consonantes++;
			} else if(comparoCaracter == '0' || comparoCaracter == '1' || comparoCaracter == '2' || comparoCaracter == '3' || comparoCaracter == '4' || comparoCaracter == '5' || comparoCaracter == '6' || comparoCaracter == '7' || comparoCaracter == '8' || comparoCaracter == '9'){
				digitos++;
			}else {
				simbolos++;
			}
		}
		
		printf("\n\nVocales: %d", vocales);
		printf("\nConsonantes: %d", consonantes);
		printf("\nSimbolos: %d", simbolos);
		printf("\nDigitos: %d", digitos);
		
		
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	}while(continuar == 's');
	return 0;
}

