#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
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
	
	if (game[x][y] == 1) {
		return (alive == 2 || alive == 3);
	} else {
		return (alive == 3);
	}
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

int main() {
	int display[GAME_WIDTH][GAME_HEIGHT] = {0};
	int swap[GAME_WIDTH][GAME_HEIGHT] = {0};
	
	srand((unsigned int)time(NULL));
	
	// Inicialización aleatoria
	for (int i = 0; i < GAME_WIDTH; ++i) {
		for (int j = 0; j < GAME_HEIGHT; ++j) {
			display[i][j] = (rand() % 6 == 0) ? 1 : 0; // Ajusta densidad inicial
		}
	}
	
	while (1) {
		for (int i = 0; i < GAME_WIDTH; ++i) {
			for (int j = 0; j < GAME_HEIGHT; ++j) {
				swap[i][j] = isAlive(display, i, j) ? 1 : 0;
			}
		}
		
		draw(swap);
		memcpy(display, swap, sizeof(display));
		SLEEP(100);
	}
	
	return 0;
}
