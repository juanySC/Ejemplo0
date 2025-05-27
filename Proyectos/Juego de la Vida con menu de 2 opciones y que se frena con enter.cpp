#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
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
	for (int y = 0; y < GAME_HEIGHT; ++y) {
		for (int x = 0; x < GAME_WIDTH; ++x) {
			printf(game[x][y] ? "#" : " ");
		}
		printf("\n");
	}
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

#ifndef _WIN32
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

int main() {
	while (1) {
		int display[GAME_WIDTH][GAME_HEIGHT] = {0};
		int swap[GAME_WIDTH][GAME_HEIGHT] = {0};
		int opcion;
		
		// Mostrar menú
		printf("Selecciona un patrón inicial:\n");
		printf("1. Oscillator (solo aleatorio)\n");
		printf("2. Glider (añade un glider al aleatorio)\n");
		printf("Opción: ");
		scanf("%d", &opcion);
		getchar(); // limpiar el buffer del Enter
		
		srand((unsigned int)time(NULL));
		for (int i = 0; i < GAME_WIDTH; ++i)
			for (int j = 0; j < GAME_HEIGHT; ++j)
				display[i][j] = (rand() % 6 == 0) ? 1 : 0;
				
				if (opcion == 2) {
					int gx = rand() % (GAME_WIDTH - 3);
					int gy = rand() % (GAME_HEIGHT - 3);
					insertGlider(display, gx, gy);
				}
				
#ifndef _WIN32
				setNonBlockingInput(true);
#endif
				
				// Ciclo de evolución
				while (1) {
					for (int i = 0; i < GAME_WIDTH; ++i)
						for (int j = 0; j < GAME_HEIGHT; ++j)
							swap[i][j] = isAlive(display, i, j) ? 1 : 0;
							
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
				getchar(); // Limpiar buffer
				if (volver != 's' && volver != 'S') break;
	}
	
	return 0;
}
