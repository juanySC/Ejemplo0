#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define GAME_WIDTH  40
#define GAME_HEIGHT 20

static bool generationColorToggle = false;
static int generation = 0;

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mostrarSalida() {
	const char* linea1 = "Sergio Alejandro Sagastume Gonzalez Programacion I 202508005";
	const char* linea2 = "Annelis Juany Sacalxot Chojolan Programacion I 202508040";
	int y = 0;
	int alternadorColor = 0;
	
	while (y < 26) {
		if (alternadorColor % 2 == 0)
			system("color 5F");
		else
			system("color 2F");
		
		system("cls");
		gotoxy(10, y);
		printf("%s", linea1);
		gotoxy(10, y + 2);
		printf("%s", linea2);
		
		Sleep(200);
		y++;
		alternadorColor++;
	}
	
	exit(0);  // Termina completamente el programa
}

bool isAlive(int game[GAME_WIDTH][GAME_HEIGHT], int x, int y) {
	int alive = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx;
			int ny = y + dy;
			if (nx >= 0 && nx < GAME_WIDTH && ny >= 0 && ny < GAME_HEIGHT) {
				if (game[nx][ny] == 1) alive++;
			}
		}
	}
	if (game[x][y] == 1) return (alive == 2 || alive == 3);
	else return (alive == 3);
}

void draw(int game[GAME_WIDTH][GAME_HEIGHT]) {
	system("cls");
	
	const char* color = generationColorToggle ? "\x1b[35m" : "\x1b[34m";
	
	int totalAlive = 0;
	
	for (int x = 0; x < GAME_WIDTH; ++x) {
		for (int y = 0; y < GAME_HEIGHT; ++y) {
			if (game[x][y]) totalAlive++;
		}
	}
	
	int totalCells = GAME_WIDTH * GAME_HEIGHT;
	int totalDead = totalCells - totalAlive;
	
	putchar(201);
	for (int x = 0; x < GAME_WIDTH; ++x) putchar(205);
	putchar(187);
	printf("\n");
	
	for (int y = 0; y < GAME_HEIGHT; ++y) {
		putchar(186);
		for (int x = 0; x < GAME_WIDTH; ++x) {
			if (game[x][y])
				printf("%s%c\x1b[0m", color, 254);
			else
				putchar(' ');
		}
		putchar(186);
		putchar('\n');
	}
	
	putchar(200);
	for (int x = 0; x < GAME_WIDTH; ++x) putchar(205);
	putchar(188);
	putchar('\n');
	
	printf("\n\x1b[33mResumen:\x1b[0m\n");
	printf(" C�lulas vivas : %d\n", totalAlive);
	printf(" C�lulas muertas: %d\n", totalDead);
	printf(" Generaci�n     : %d\n", ++generation);
	
	generationColorToggle = !generationColorToggle;
}

void insertGlider(int grid[GAME_WIDTH][GAME_HEIGHT], int x, int y) {
	if (x + 2 < GAME_WIDTH && y + 2 < GAME_HEIGHT) {
		grid[x + 1][y] = 1;
		grid[x + 2][y + 1] = 1;
		grid[x][y + 2] = 1;
		grid[x + 1][y + 2] = 1;
		grid[x + 2][y + 2] = 1;
	}
}

void insertBlinker(int grid[GAME_WIDTH][GAME_HEIGHT], int x, int y) {
	if (x + 2 < GAME_WIDTH && y < GAME_HEIGHT) {
		grid[x][y] = 1;
		grid[x + 1][y] = 1;
		grid[x + 2][y] = 1;
	}
}

void insertToad(int grid[GAME_WIDTH][GAME_HEIGHT], int x, int y) {
	if (x + 3 < GAME_WIDTH && y + 1 < GAME_HEIGHT) {
		grid[x + 1][y] = 1;
		grid[x + 2][y] = 1;
		grid[x + 3][y] = 1;
		grid[x][y + 1] = 1;
		grid[x + 1][y + 1] = 1;
		grid[x + 2][y + 1] = 1;
	}
}

void printBlinkingTitle() {
	const char* red = "\x1b[31m";
	const char* blue = "\x1b[34m";
	const char* reset = "\x1b[0m";
	
	for (int i = 0; i < 6; i++) {
		system("cls");
		if (i % 2 == 0)
			printf("%sSelecciona un patr�n inicial:%s\n\n", red, reset);
		else
			printf("%sSelecciona un patr�n inicial:%s\n\n", blue, reset);
		Sleep(300);
	}
}

int main() {
	while (1) {
		int display[GAME_WIDTH][GAME_HEIGHT] = {0};
		int swap[GAME_WIDTH][GAME_HEIGHT] = {0};
		int opcion;
		
		printBlinkingTitle();
		printf("1. Oscillator (solo aleatorio)\n");
		printf("2. Glider (a�ade un glider al aleatorio)\n");
		printf("3. Blinker (a�ade un blinker al aleatorio)\n");
		printf("4. Toad (a�ade un toad al aleatorio)\n");
		printf("Opci�n: ");
		scanf("%d", &opcion);
		while (getchar() != '\n');
		
		srand((unsigned int)time(NULL));
		for (int i = 0; i < GAME_WIDTH; ++i) {
			for (int j = 0; j < GAME_HEIGHT; ++j) {
				display[i][j] = (rand() % 6 == 0) ? 1 : 0;
			}
		}
		
		if (opcion == 2) {
			insertGlider(display, rand() % (GAME_WIDTH - 3), rand() % (GAME_HEIGHT - 3));
		} else if (opcion == 3) {
			insertBlinker(display, rand() % (GAME_WIDTH - 3), rand() % GAME_HEIGHT);
		} else if (opcion == 4) {
			insertToad(display, rand() % (GAME_WIDTH - 4), rand() % (GAME_HEIGHT - 2));
		}
		
		generation = 0;
		
		while (1) {
			for (int i = 0; i < GAME_WIDTH; ++i) {
				for (int j = 0; j < GAME_HEIGHT; ++j) {
					swap[i][j] = isAlive(display, i, j) ? 1 : 0;
				}
			}
			
			draw(swap);
			memcpy(display, swap, sizeof(display));
			Sleep(500);
			
			if (_kbhit() && _getch() == 13) break; // Enter para salir
		}
		
		char volver;
		printf("\n�Volver al men�? (s/n): ");
		scanf(" %c", &volver);
		while (getchar() != '\n');
		
		if (volver != 's' && volver != 'S') {
			system("cls");
			mostrarSalida();
		}
	}
	return 0;
}
