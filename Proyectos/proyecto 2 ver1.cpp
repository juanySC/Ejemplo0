#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

// Teclas para moverse
#define ARRIBA 'w'
#define ABAJO  's'
#define IZQUIERDA 'a'
#define DERECHA 'd'
#define ENTER 13

// Prototipos de funciones
int gotoxy(int x, int y);
void dibujarMarco();
void pantallaCarga();
void mostrarMensajeFinal(const char* mensaje);
void dibujarTablero(char tablero[3][3]);
int verificarGanador(char tablero[3][3], char jugador);
void cpuMovimientoMedio(char tablero[3][3], char jugador, char cpu);
void cpuMovimientoDificil(char tablero[3][3], char jugador, char cpu);
void jugarFacil();
void jugarMedio();
void jugarDificil();
void mostrarSalida();
void menuPrincipal();
void menuInicio();

// --- Nuevos prototipos para el "nivel difícil" con Minimax (puedes dejar tus funciones cpuMovimientoDificil para modo medio) ---
// (En este ejemplo no se usa Minimax ya que respetamos tu código base en cpuMovimientoDificil)
// Si deseas reemplazarlo por una IA infalible, debes integrar el algoritmo Minimax y usarlo en jugarDificil().


// Definición de colores para "X" y "O"
#define COLOR_X 12  // Rojo para X
#define COLOR_O 9   // Azul para O

// Función para mover el cursor a una posición específica en la consola
int gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return 1;
}

// Función para cambiar el color del texto
void cambiarColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void dibujarMarco() {
	int posX, posY;
	gotoxy(4, 4);   printf("%c", char(201));
	gotoxy(40, 4);  printf("%c", char(187));
	gotoxy(4, 24);  printf("%c", char(200));
	gotoxy(40, 24); printf("%c", char(188));
	for (posX = 5; posX < 40; posX++) {
		gotoxy(posX, 4);  printf("%c", char(205));
		gotoxy(posX, 24); printf("%c", char(205));
	}
	for (posY = 5; posY < 24; posY++) {
		gotoxy(4, posY);  printf("%c", char(186));
		gotoxy(40, posY); printf("%c", char(186));
	}
}

void pantallaCarga() {
	system("cls");
	dibujarMarco();
	//gotoxy(14, 14);
	
	// Titileo de "cargando totito..."
	for (int i = 0; i < 6; i++) {
		gotoxy(14, 14);
		if (i % 2 == 0) cambiarColor(COLOR_X);  // Rojo
		else cambiarColor(COLOR_O);             // Azul
		printf("CARGANDO TOTITO...");
		Sleep(300);
	}
	cambiarColor(7); // Restaurar color

}

void mostrarMensajeFinal(const char* mensaje) {
	system("cls");
	dibujarMarco();
	gotoxy(18, 14);
	printf("%s", mensaje);
	gotoxy(0, 25);
	Sleep(5000);
}

void dibujarTablero(char tablero[3][3]) {
	int baseX = 5, baseY = 6;
	for (int i = 0; i < 2; i++) {
		int y = baseY + 6 * (i + 1);
		for (int x = 5; x < 40; x++) {
			gotoxy(x, y);
			printf("*");
		}
	}
	for (int i = 0; i < 2; i++) {
		int x = baseX + 11 * (i + 1);
		for (int y = 5; y < 24; y++) {
			gotoxy(x, y);
			printf("*");
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x = baseX + j * 11 + 4;
			int y = baseY + i * 6 + 2;
			gotoxy(x, y);
			if (tablero[i][j] == 'X') {
				cambiarColor(COLOR_X);
			} else if (tablero[i][j] == 'O') {
				cambiarColor(COLOR_O);
			}
			printf("%c", tablero[i][j]);
			cambiarColor(7);
		}
	}
}

int verificarGanador(char tablero[3][3], char jugador) {
	for (int i = 0; i < 3; i++) {
		if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) return 1;
		if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) return 1;
	}
	if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) return 1;
	if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) return 1;
	return 0;
}

int tableroLleno(char tablero[3][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tablero[i][j] == ' ') return 0;
	return 1;
}

void cpuMovimientoMedio(char tablero[3][3], char jugador, char cpu) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tablero[i][j] == ' ') {
				tablero[i][j] = jugador;
				if (verificarGanador(tablero, jugador)) {
					tablero[i][j] = cpu;
					return;
				}
				tablero[i][j] = ' ';
			}
		}
	}
	
	int r, c;
	do {
		r = rand() % 3;
		c = rand() % 3;
	} while (tablero[r][c] != ' ');
	tablero[r][c] = cpu;
}

void cpuMovimientoDificil(char tablero[3][3], char jugador, char cpu) {
	// Para el modo difícil, se usará el algoritmo Minimax en otra solución.
	// Aquí se deja tu implementación base (aunque no es 100% infalible).
	// Si deseas sustituirla por Minimax, reemplaza la función "jugadaDificil" más adelante.
	
	// Primero, intentar ganar
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tablero[i][j] == ' ') {
				tablero[i][j] = cpu;
				if (verificarGanador(tablero, cpu)) {
					return;
				}
				tablero[i][j] = ' ';
			}
		}
	}
	
	// Luego, bloquear al jugador
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tablero[i][j] == ' ') {
				tablero[i][j] = jugador;
				if (verificarGanador(tablero, jugador)) {
					tablero[i][j] = cpu;
					return;
				}
				tablero[i][j] = ' ';
			}
		}
	}
	
	// Movimiento aleatorio
	int r, c;
	do {
		r = rand() % 3;
		c = rand() % 3;
	} while (tablero[r][c] != ' ');
	tablero[r][c] = cpu;
}

void jugarFacil() {
	pantallaCarga();
	char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int fila = 0, col = 0, jugadas = 0;
	char jugador, cpu;
	jugador = rand() % 2 == 0 ? 'X' : 'O';
	cpu = jugador == 'X' ? 'O' : 'X';
	
	// SOLUCIÓN 1: Turno aleatorio (Método 1)
	if (rand() % 2 == 1) {
		int r, c;
		do {
			r = rand() % 3;
			c = rand() % 3;
		} while (tablero[r][c] != ' ');
		tablero[r][c] = cpu;
		jugadas++;
	}
	
	while (1) {
		system("cls");
		dibujarMarco();
		dibujarTablero(tablero);
		int x = 5 + col * 11 + 4;
		int y = 6 + fila * 6 + 2;
		gotoxy(x, y);
		
		char tecla = toupper(getch());
		if (tecla == 'W' && fila > 0) fila--;
		else if (tecla == 'S' && fila < 2) fila++;
		else if (tecla == 'A' && col > 0) col--;
		else if (tecla == 'D' && col < 2) col++;
		else if (tecla == '\r') {
			if (tablero[fila][col] == ' ') {
				tablero[fila][col] = jugador;
				jugadas++;
				
				if (verificarGanador(tablero, jugador)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("GANO");
					return;
				}
				
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");
					return;
				}
				
				int r, c;
				do {
					r = rand() % 3;
					c = rand() % 3;
				} while (tablero[r][c] != ' ');
				tablero[r][c] = cpu;
				jugadas++;
				
				if (verificarGanador(tablero, cpu)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("PERDIO");
					return;
				}
				
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");
					return;
				}
			}
		}
	}
}

void jugarMedio() {
	pantallaCarga();
	char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int fila = 0, col = 0, jugadas = 0;
	char jugador, cpu;
	jugador = rand() % 2 == 0 ? 'X' : 'O';
	cpu = jugador == 'X' ? 'O' : 'X';
	
	// SOLUCIÓN 1: Turno aleatorio (Método 1)
	if (rand() % 2 == 1) {
		int r, c;
		do {
			r = rand() % 3;
			c = rand() % 3;
		} while (tablero[r][c] != ' ');
		tablero[r][c] = cpu;
		jugadas++;
	}
	
	while (1) {
		system("cls");
		dibujarMarco();
		dibujarTablero(tablero);
		int x = 5 + col * 11 + 4;
		int y = 6 + fila * 6 + 2;
		gotoxy(x, y);
		
		char tecla = toupper(getch());
		if (tecla == 'W' && fila > 0) fila--;
		else if (tecla == 'S' && fila < 2) fila++;
		else if (tecla == 'A' && col > 0) col--;
		else if (tecla == 'D' && col < 2) col++;
		else if (tecla == '\r') {
			if (tablero[fila][col] == ' ') {
				tablero[fila][col] = jugador;
				jugadas++;
				
				if (verificarGanador(tablero, jugador)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("GANO");
					return;
				}
				
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");
					return;
				}
				
				cpuMovimientoMedio(tablero, jugador, cpu);
				jugadas++;
				
				if (verificarGanador(tablero, cpu)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("PERDIO");
					return;
				}
				
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");
					return;
				}
			}
		}
	}
}

void jugarDificil() {
	pantallaCarga();
	char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int fila = 0, col = 0, jugadas = 0;
	char jugador, cpu;
	jugador = rand() % 2 == 0 ? 'X' : 'O';
	cpu = jugador == 'X' ? 'O' : 'X';
	
	// SOLUCIÓN 1: Turno aleatorio (Método 1)
	if (rand() % 2 == 1) {
		int r, c;
		do {
			r = rand() % 3;
			c = rand() % 3;
		} while (tablero[r][c] != ' ');
		// En modo difícil, usamos tu función de movimiento difícil
		cpuMovimientoDificil(tablero, jugador, cpu);
		jugadas++;
	}
	
	while (1) {
		system("cls");
		dibujarMarco();
		dibujarTablero(tablero);
		int x = 5 + col * 11 + 4;
		int y = 6 + fila * 6 + 2;
		gotoxy(x, y);
		
		char tecla = toupper(getch());
		if (tecla == 'W' && fila > 0) fila--;
		else if (tecla == 'S' && fila < 2) fila++;
		else if (tecla == 'A' && col > 0) col--;
		else if (tecla == 'D' && col < 2) col++;
		else if (tecla == '\r') {
			if (tablero[fila][col] == ' ') {
				tablero[fila][col] = jugador;
				jugadas++;
				
				if (verificarGanador(tablero, jugador)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("GANO (ERROR)");
					return;
				}
				
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");
					return;
				}
				
				cpuMovimientoDificil(tablero, jugador, cpu);
				jugadas++;
				
				if (verificarGanador(tablero, cpu)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("PERDIO");
					return;
				}
				
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");
					return;
				}
			}
		}
	}
}

void mostrarSalida() {
	system("color 5F");
	system("cls");
	gotoxy(20, 13);
	printf("Sergio Alejandro Sagastume Gonzalez Programacion I 202508005");
	gotoxy(20, 15);
	printf("Annelis Juany Sacalxot Chojolan Programacion I 202508040");
	gotoxy(0, 25);
	while (1) {
		char tecla = getch();
		if (tecla == '\r') {
			exit(0);
		}
	}
}

void menuPrincipal() {
	while (1) {
		system("cls");
		dibujarMarco();
		gotoxy(10, 10); printf("\tJUEGO TOTITO");
		gotoxy(10, 11); printf("1. Jugar Facil");
		gotoxy(10, 12); printf("2. Jugar Medio");
		gotoxy(10, 13); printf("3. Jugar Dificil");
		gotoxy(10, 14); printf("4. Regresar al menu principal"); // CAMBIO
		gotoxy(10, 15); printf("Selecciona una opcion: ");
		
		char opcion = toupper(getch());
		switch (opcion) {
		case '1': jugarFacil(); break;
		case '2': jugarMedio(); break;
		case '3': jugarDificil(); break;
		case '4': menuInicio(); // REGRESA a menuInicio
		}
	}
}


void menuInicio() {
	system("cls");
	dibujarMarco();
	
	// Titileo de "JUEGO DE TOTITO"
	for (int i = 0; i < 6; i++) {
		gotoxy(5, 6);
		if (i % 2 == 0) cambiarColor(COLOR_X);  // Rojo
		else cambiarColor(COLOR_O);             // Azul
		printf("JUEGO DE TOTITO");
		Sleep(300);
	}
	cambiarColor(7); // Restaurar color
	
	gotoxy(5, 10);
	printf("A) ELEGIR DIFICULTAD");
	gotoxy(5, 11);
	printf("B) SALIR");
	
	char opcion;
	do {
		gotoxy(5, 13);
		printf("Seleccione una opcion (A/B): ");
		opcion = toupper(getch());
	} while (opcion != 'A' && opcion != 'B');
	
	if (opcion == 'A') {
		menuPrincipal();
	} else if (opcion == 'B') {
		mostrarSalida();
	}
}


int main() {
	srand(time(NULL));
	menuInicio();  // Mostrar el menú inicial
	return 0;
}
