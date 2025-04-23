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
	
	gotoxy(1,18); printf("Esquina inferior izquierda");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,18); printf("Inferior");
	
	int px = 1;
	int py =2;
	int direccion = 1;
	//derecha-abajo
	while(px <= 70){
		
		gotoxy(px, py); printf("x");
		Sleep(250);
		px++;
		
		if(direccion == 1) py++;
		else py--;
		if(py== 17) direccion = 0;
		if(py == 2) direccion = 1;
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
		
