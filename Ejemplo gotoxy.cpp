#include <stdio.h>
#include <windows.h>
#include <conio.h>

//proptotipo
int gotoxy(int x, int y);

int main(){
	
	gotoxy(1,1); printf("Esquina superior izquierda");
	gotoxy(1,18); printf("Esquina superior derecha");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,18); printf("Inferior");
	
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
