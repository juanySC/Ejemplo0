#include <stdio.h>
#include <windows.h>
#include <conio.h>

//proptotipo
int gotoxy(int x, int y);

int contadorX;
int contadorY;

int main(){
	
	//sirve para que se repita de  1 a n
	contadorX = 1;
	contadorY = 1;
	
	//derecha-abajo
	while(contadorX <= 50){
		gotoxy(contadorX, 50); printf("x");
		contadorX++;
	}
	
	while(contadorY <=50){
		gotoxy(50, contadorY); printf("x");
		contadorY++;
	}
	
	//reinicio el contador
	contadorX = 1;
	contadorY = 1;
	//izquierda arriba
	while(contadorX <= 50){
		gotoxy(contadorX, 1); printf("x");
		contadorX++;
	}
	
	while(contadorY <= 50){
		gotoxy(1, contadorY), printf("x");
		contadorY++;
	}
	//segundo cuadro
	contadorX = 1;
	contadorY = 1;
	//derecha-abajo
	while(contadorX <=48){
		gotoxy(contadorX, 48); printf("x");
		contadorX++;
	}
	
	while(contadorY <=48){
		gotoxy(48, contadorY); printf("x");
		contadorY++;
	}
	//izquierda-arriba
	contadorX = 1;
	contadorY = 1;
	
	while(contadorX <=48){
		gotoxy(contadorX, 2); printf("x");
		contadorX++;
	}
	
	while(contadorY <=48){
		gotoxy(2, contadorY); printf("x");
		contadorY++;
	}
	
	getch();
	
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
