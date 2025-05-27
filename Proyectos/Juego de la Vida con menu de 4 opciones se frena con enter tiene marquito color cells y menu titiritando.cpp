#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h> // <- Agregado para usar Sleep
#define CLEAR "cls"
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#define CLEAR "clear"
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#define GAME_WIDTH  40
#define GAME_HEIGHT 20

// Variable global para alternar color
static bool generationColorToggle = false;

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
	system(CLEAR);
	
	// Código ANSI para colores
	// Morado = \x1b[35m, Azul = \x1b[34m, Reset = \x1b[0m
	const char* color = generationColorToggle ? "\x1b[35m" : "\x1b[34m";
	
	// Imprimir esquina superior izquierda y línea superior
	putchar(201); // +
	for (int x = 0; x < GAME_WIDTH; ++x) putchar(205); // -
	putchar(187); // +
	putchar('\n');
	
	// Imprimir filas con bordes laterales
	for (int y = 0; y < GAME_HEIGHT; ++y) {
		putchar(186); // ¦
		for (int x = 0; x < GAME_WIDTH; ++x) {
			if (game[x][y]) {
				printf("%s#\x1b[0m", color);  // Célula viva con color y reset
			} else {
				putchar(' ');
			}
		}
		putchar(186); // ¦
		putchar('\n');
	}
	
	// Imprimir línea inferior con esquinas
	putchar(200); // +
	for (int x = 0; x < GAME_WIDTH; ++x) putchar(205); // -
	putchar(188); // +
	putchar('\n');
	
	// Alternar color para la próxima generación
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

#ifndef _WIN32
#include <sys/select.h>
void setNonBlockingInput(bool enable) {
	struct termios ttystate;
	tcgetattr(STDIN_FILENO, &ttystate);
	if (enable) {
		ttystate.c_lflag &= ~ICANON;
		ttystate.c_lflag &= ~ECHO;
		ttystate.c_cc[VMIN] = 0;
		ttystate.c_cc[VTIME] = 0;
	} else {
		ttystate.c_lflag |= ICANON;
		ttystate.c_lflag |= ECHO;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

int kbhit() {
	struct timeval tv = { 0L, 0L };
	fd_set fds;
	FD_ZERO(&fds);
	FD_SET(0, &fds);
	return select(1, &fds, NULL, NULL, &tv);
}
#endif
void printBlinkingTitle() {
	const char* red = "\x1b[31m";
	const char* blue = "\x1b[34m";
	const char* reset = "\x1b[0m";
	
	for (int i = 0; i < 6; i++) {  // Parpadea 6 veces (~1.2 segundos)
		system(CLEAR);
		if (i % 2 == 0) {
			printf("%sSelecciona un patrón inicial:%s\n\n", red, reset);
		} else {
			printf("%sSelecciona un patrón inicial:%s\n\n", blue, reset);
		}
		SLEEP(200);
	}
}
int main() {
	while (1) {
		int display[GAME_WIDTH][GAME_HEIGHT] = {0};
		int swap[GAME_WIDTH][GAME_HEIGHT] = {0};
		int opcion;
		
		printBlinkingTitle();
		printf("1. Oscillator (solo aleatorio)\n");
		printf("2. Glider (añade un glider al aleatorio)\n");
		printf("3. Blinker (añade un blinker al aleatorio)\n");
		printf("4. Toad (añade un toad al aleatorio)\n");
		printf("Opción: ");
		scanf("%d", &opcion);
		getchar(); // limpiar el buffer del Enter
		
		srand((unsigned int)time(NULL));
		for (int i = 0; i < GAME_WIDTH; ++i) {
			for (int j = 0; j < GAME_HEIGHT; ++j) {
				display[i][j] = (rand() % 6 == 0) ? 1 : 0;
			}
		}
		
		if (opcion == 2) {
			int gx = rand() % (GAME_WIDTH - 3);
			int gy = rand() % (GAME_HEIGHT - 3);
			insertGlider(display, gx, gy);
		} else if (opcion == 3) {
			int bx = rand() % (GAME_WIDTH - 3);
			int by = rand() % GAME_HEIGHT;
			insertBlinker(display, bx, by);
		} else if (opcion == 4) {
			int tx = rand() % (GAME_WIDTH - 4);
			int ty = rand() % (GAME_HEIGHT - 2);
			insertToad(display, tx, ty);
		}
		
#ifndef _WIN32
		setNonBlockingInput(true);
#endif
		
		while (1) {
			for (int i = 0; i < GAME_WIDTH; ++i) {
				for (int j = 0; j < GAME_HEIGHT; ++j) {
					swap[i][j] = isAlive(display, i, j) ? 1 : 0;
				}
			}
			
			draw(swap);
			memcpy(display, swap, sizeof(display));
			SLEEP(100);
			
#ifdef _WIN32
			if (_kbhit()) {
				int c = _getch();
				if (c == 13) break; // Enter
			}
#else
			if (kbhit()) {
				char c = getchar();
				if (c == '\n') break; // Enter
			}
#endif
		}
		
#ifndef _WIN32
		setNonBlockingInput(false);
#endif
		
		char volver;
		printf("\n¿Volver al menú? (s/n): ");
		scanf(" %c", &volver);
		getchar();
		if (volver != 's' && volver != 'S') break;
	}
	
	return 0;
}
