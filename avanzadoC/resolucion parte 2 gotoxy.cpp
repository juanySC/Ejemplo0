#include <stdio.h>
#include <windows.h>
#include <conio.h>

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
	
	gotoxy(1,2);printf("%c",char(201));//inicia la linea horizontal superior
	gotoxy(70,2); printf("%c", char(187));//finaliza linea horizontal inferior
	gotoxy(1,17); printf("%c", char(200)); //inicia horizontal inferior
	gotoxy(70,17); printf("%c", char(188)); //linea horizontal inferior
	
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
	cod = 186;
	while(posy<=16){
		gotoxy(1, posy); printf("%c", cod);
		gotoxy(70, posy); printf("%c", cod);
		posy++;
	}
	
	getch();
	
	int veces = 1, velocidad = 200, juego = 219;
	while(veces<=5){
		gotoxy(25,1); printf("Nivel 1 %3d", veces);
		int px = 2;
		int py =3;
		int direccion = 1;
		//derecha-abajo
		while(px <= 69){
			
			gotoxy(px, py); printf("%c", char(juego));
			Sleep(velocidad);
			px++;
			
			if(direccion == 1) py++;
			else py--;
			if(py== 16) direccion = 0;
			if(py == 3) direccion = 1;
		}
		veces++;
		velocidad = velocidad -30;
		juego++;
	}
	
	system("cls");
	gotoxy(25,10); printf("F I N  D E L  J U E G O");
	
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
