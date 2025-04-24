#include <stdio.h>
#include <windows.h>
#include <conio.h>

//proptotipo
int gotoxy(int x, int y);

int contadorX;
int contadorY;
int cod = 205;
void pintarMargen();
void limpiar();

int main(){
	
	//sirve para que se repita de  1 a n
	contadorX = 1;
	contadorY = 1;
	
	//variables locales 
	int salir = 1;
	char aleLetra, letraPresionada;
		
		
	//descripcion
	gotoxy(73,2); printf("Nivel:");
	gotoxy(73,5); printf("Punteo: ");
	gotoxy(73,6); printf("Aciertos:");
	gotoxy(73,7); printf("Fallos: ");
	pintarMargen();
	
	//tomar en cuenta el abecedario de ASCII
	while (salir) {
		aleLetra = (rand() % 52 < 26) ? ('A' + rand() % 26) : ('a' + rand() % 26);
		int posX = 2 + rand() % 67;
		int y;
		
		for (y = 3; y < 17 && !_kbhit(); y++) {
			limpiar();
			gotoxy(posX, y);
			printf("%c", aleLetra);
			Sleep(velocidad);
		}
		
		if (y == 17) {
			errores++;
		} else {
			letraPresionada = _getch();
			if (letraPresionada == aleLetra) {
				aciertos++;
				punteo += 10;
				if (aciertos % 10 == 0) {
					nivel++;
					velocidad = (velocidad > 60) ? velocidad - 40 : velocidad;
				}
			} else {
				errores++;
			}
		}
	
	
}
	
void pintarMargen(){
	/*gotoxy(1,18); printf("Esquina inferior izquierda");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,1); printf("Superior");
	gotoxy(70,18); printf("Inferior");
	*/
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
	
	
	system("cls");
	gotoxy(25,10); printf("F I N  D E L  J U E G O");
	
	getch();	
}	

void limpiar(){
	for
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
		
