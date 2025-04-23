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
	
	int cod = 205;
	
	gotoxy(1,1); printf("Superior izquierda 1,1");
	gotoxy(1,18); printf("Inferior izquierda1,18");
	gotoxy(70,1); printf("Superior derecha 70,1");
	gotoxy(70,18); printf("Inferior derecha70,18");
	
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
	
	int tiempo = 300;
	//rabgi 2 a 68 diferencia de rango 66
	//funcion rad
	int aleatorio;
	int ubicacion_x = 2;
	srand(unsigned(time(NULL)));; //inicializar rand
	
	int max = 100;
	//int a= 1;
	getch();
	/*
	while(a<= 10){
	aleatorio = 2+rand()%max; //0..max-1
	gotoxy(20,2); printf("%d", aleatorio);
	Sleep(300);
	a++;
	}
	
	int a = 1, b = 1;
	while(a<= 10){
	aleatorio = 2+rand()%max; //0..max-1
	//generar y ubicacion 20,2
	gotoxy(aleatorio,2); printf("u");
	
	Sleep(tiempo);
	aleatorio = 2+rand()%max; //0..max-1
	gotoxy(aleatorio,2); printf("m");
	
	Sleep(tiempo);
	aleatorio = 2+rand()%max; //0..max-1
	gotoxy(aleatorio,2); printf("e");
	
	Sleep(tiempo);
	aleatorio = 2+rand()%max; //0..max-1
	//generar y ubicacion 20,2
	gotoxy(aleatorio,b); printf("u");
	
	Sleep(tiempo);
	aleatorio = 2+rand()%max; //0..max-1
	gotoxy(aleatorio,b); printf("m");
	
	Sleep(tiempo);
	aleatorio = 2+rand()%max; //0..max-1
	gotoxy(aleatorio,b); printf("e");
	
	Sleep(tiempo);
	aleatorio = 2+rand()%max; //0..max-1
	gotoxy(aleatorio,b); printf("s");
	getch();
	
	a++;
	}
	//pedir ubicacion alatorioa*/
	
	
	//rango 1; 
	int pos_x =0, a = 1;
	char letra;
	
	
	while(a <= 15){
		// x 2 ---68
		letra = 65+rand()%26;
		pos_x = 3+rand()%67;
		gotoxy(pos_x,3);printf("%c", letra);
		a++;
		Sleep(350);
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
		
