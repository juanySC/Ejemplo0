#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//proptotipo
int gotoxy(int x, int y);

int contadorX;
int contadorY;
int cod = 205;

int main(){
	
	//sirve para que se repita de  1 a n
	contadorX = 1;
	contadorY = 1;
	
	gotoxy(1,18); printf("Esquina inferior izquierda");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,18); printf("Inferior");
	
	int tiempo = 300;
	//rabgi 2 a 68 diferencia de rango 66
	//funcion rad
	int aleatorio;
	int ubicacion_x = 2;
	srand(unsigned(time(NULL)));; //inicializar rand
	
	int max = 100;
	aleatorio = rand()%max; //0..max-1
	
	gotoxy(20,2); printf("%d", aleatorio);
	//generar y ubicacion 20,2
	//gotoxy(20,2); printf("u");
	//Sleep(tiempo);
	gotoxy(30,2); printf("m");
	Sleep(tiempo);
	gotoxy(40,2); printf("e");
	Sleep(tiempo);
	gotoxy(50,2); printf("s");
	
	
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
