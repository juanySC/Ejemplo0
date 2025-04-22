#include <stdio.h>
#include <windows.h>
#include <conio.h>

//proptotipo
int gotoxy(int x, int y);

int contadorX;
int contadorY;
int opcion;
char caracter;

int main(){
	
	
	printf("Este programa margenes y totito \n");
	printf("Ingrese el caracter con el que desea graficar: \n");
	scanf("%c", &caracter);
	
	
	printf("Eliga la opcion que desea dibujar: \n");
	printf("1. Margen \n");
	printf("2. Margen doble \n");
	printf("3. Totito \n");
	scanf("%d", &opcion);
	
	if(opcion == 1){
		//sirve para que se repita de  1 a n
		contadorX = 1;
		contadorY = 1;
		
		//derecha-abajo
		while(contadorX <= 50){
			gotoxy(contadorX, 50); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <=50){
			gotoxy(50, contadorY); printf("%c", &caracter);
			contadorY++;
		}
		
		//reinicio el contador
		contadorX = 1;
		contadorY = 1;
		//izquierda arriba
		while(contadorX <= 50){
			gotoxy(contadorX, 1); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <= 50){
			gotoxy(1, contadorY), printf("%c", &caracter);
			contadorY++;
		}
		
		getch();
	} else if(opcion == 2){
		//sirve para que se repita de  1 a n
		contadorX = 1;
		contadorY = 1;
		
		//derecha-abajo
		while(contadorX <= 50){
			gotoxy(contadorX, 50); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <=50){
			gotoxy(50, contadorY); printf("%c", &caracter);
			contadorY++;
		}
		
		//reinicio el contador
		contadorX = 1;
		contadorY = 1;
		//izquierda arriba
		while(contadorX <= 50){
			gotoxy(contadorX, 1); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <= 50){
			gotoxy(1, contadorY), printf("%c", &caracter);
			contadorY++;
		}
		//segundo cuadro
		contadorX = 1;
		contadorY = 1;
		//derecha-abajo
		while(contadorX <=48){
			gotoxy(contadorX, 48); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <=48){
			gotoxy(48, contadorY); printf("%c", &caracter);
			contadorY++;
		}
		//izquierda-arriba
		contadorX = 1;
		contadorY = 1;
		
		while(contadorX <=48){
			gotoxy(contadorX, 2); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <=48){
			gotoxy(2, contadorY); printf("%c", &caracter);
			contadorY++;
		}
		
		getch();
	} else if(opcion == 3){
		//sirve para que se repita de  1 a n
		contadorX = 1;
		contadorY = 1;
		
		//derecha-abajo
		while(contadorX <= 50){
			gotoxy(contadorX, 8); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <=25){
			gotoxy(15, contadorY); printf("%c", &caracter);
			contadorY++;
		}
		
		//reinicio el contador
		contadorX = 1;
		contadorY = 1;
		//izquierda arriba
		while(contadorX <= 50){
			gotoxy(contadorX, 16); printf("%c", &caracter);
			contadorX++;
		}
		
		while(contadorY <= 25){
			gotoxy(30, contadorY), printf("%c", &caracter);
			contadorY++;
		}
		
		getch();
		
	}
		

	
}
	
	//desarrollo de la funcion
	int gotoxy(int x, int y){
		COORD coord;
		HANDLE h_stdout;
		
		coord.X = x;
		coord.Y = y;
		
		if((h_stdout = GetStdHandle(STD_OUTPUT_HANDLE))== INVALID_HANDLE_VALUE)
			return 0;
		if(SetConsoleCursorPosition(h_stdout, coord) == 0)
			return 0;
		return 1;
		
	}
