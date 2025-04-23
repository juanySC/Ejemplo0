#include <stdio.h>
#include <windows.h>
#include <conio.h>

//proptotipo
int gotoxy(int x, int y);

int contadorX;
int contadorY;
int direccion;

int main(){
	
	//sirve para que se repita de  1 a n
	contadorX = 1;
	contadorY = 1;
	//int cod = 176;
	int cod = 219;
	
	gotoxy(1,1); printf("Superior izquierda 1,1");
	gotoxy(1,18); printf("Inferior izquierda1,18");
	gotoxy(70,1); printf("Superior derecha 70,1");
	gotoxy(70,18); printf("Inferior derecha70,18");
	
	gotoxy(1,2);printf("*");//inicia la linea horizontal superior
	gotoxy(70,2); printf("*");//finaliza linea horizontal inferior
	gotoxy(1,17); printf("*"); //inicia horizontal inferior
	gotoxy(70,17); printf("*"); //linea horizontal inferior
	
	//lineas horizontales
	int posx = 2;//inicia en 2, despues del simbolo "*"
	while(posx<= 69){
		gotoxy(posx,2); printf("%c", cod);//ascii = alt +64 = @	
		gotoxy(posx,17); printf("%c", cod);//la linea antes de la 18
		posx++;
	}
	
	//lineas verticales
	//vertical izquierda (1,3) finaliza (1, 16)
	//vertical derecha (70,3) finaliza (70,16)
	int posy = 3;
	while(posy<=16){
		gotoxy(1, posy); printf("%c", cod);
		gotoxy(70, posy); printf("%c", cod);
		posy++;
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
		
		
