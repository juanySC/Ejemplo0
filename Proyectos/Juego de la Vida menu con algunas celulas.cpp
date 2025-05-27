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

void draw(int game[GAME_WIDTH][GAME_HEIGHT]) {
	system(CLEAR);
	for (int y = 0; y < GAME_HEIGHT; ++y) {
		for (int x = 0; x < GAME_WIDTH; ++x) {
			printf(game[x][y] ? "#" : " ");
		}
		printf("\n");
	}
}

bool isAlive(int game[GAME_WIDTH][GAME_HEIGHT], int x, int y) {
	int alive = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (dx == 0 && dy == 0) continue;
			int nx = x + dx, ny = y + dy;
			if (nx >= 0 && nx < GAME_WIDTH && ny >= 0 && ny < GAME_HEIGHT) {
				if (game[nx][ny] == 1) alive++;
			}
		}
	}
	if (game[x][y] == 1) return (alive == 2 || alive == 3);
	else return (alive == 3);
}

void placePattern(int board[GAME_WIDTH][GAME_HEIGHT], int pattern[][2], int patternSize, int baseX, int baseY) {
	for (int i = 0; i < patternSize; ++i) {
		int x = baseX + pattern[i][0];
		int y = baseY + pattern[i][1];
		if (x >= 0 && x < GAME_WIDTH && y >= 0 && y < GAME_HEIGHT) {
			board[x][y] = 1;
		}
	}
}

// Patrones básicos definidos como arreglos de coordenadas relativas
int gliderPattern[5][2] = {
	{1,0}, {2,1}, {0,2}, {1,2}, {2,2}
};

int blinkerPattern[3][2] = {
	{0,0}, {1,0}, {2,0}
};

int toadPattern[6][2] = {
	{0,0}, {1,0}, {2,0}, {1,1}, {2,1}, {3,1}
};

int beaconPattern[6][2] = {
	{0,0}, {1,0}, {0,1}, {3,2}, {2,3}, {3,3}
};

void clearBoard(int board[GAME_WIDTH][GAME_HEIGHT]) {
	memset(board, 0, sizeof(int)*GAME_WIDTH*GAME_HEIGHT);
}

void randomizeBoard(int board[GAME_WIDTH][GAME_HEIGHT], int densityPercent) {
	srand(time(NULL));
	for (int x = 0; x < GAME_WIDTH; ++x) {
		for (int y = 0; y < GAME_HEIGHT; ++y) {
			board[x][y] = (rand() % 100 < densityPercent) ? 1 : 0;
		}
	}
}

// Esta función coloca N grupos del patrón en posiciones aleatorias
void placeMultiplePatterns(int board[GAME_WIDTH][GAME_HEIGHT], int pattern[][2], int patternSize, int count) {
	srand(time(NULL));
	for (int i = 0; i < count; ++i) {
		int baseX = rand() % (GAME_WIDTH - 5);  // margen para que no salga del tablero
		int baseY = rand() % (GAME_HEIGHT - 5);
		placePattern(board, pattern, patternSize, baseX, baseY);
	}
}

int main() {
	int display[GAME_WIDTH][GAME_HEIGHT] = {0};
	int swap[GAME_WIDTH][GAME_HEIGHT] = {0};
	int generations = 0;
	
	// Preguntar número de generaciones
	do {
		printf("¿Cuántas generaciones desea simular? (máx 20): ");
		scanf("%d", &generations);
	} while (generations < 1 || generations > 20);
	
	// Menú de selección de patrón
	int opcion = 0;
	do {
		printf("\nSeleccione un patrón inicial:\n");
		printf("1. Glider\n");
		printf("2. Blinker (Oscilador)\n");
		printf("3. Toad (Oscilador)\n");
		printf("4. Beacon (Oscilador)\n");
		printf("5. Aleatorio (más células)\n");
		printf("Opción: ");
		scanf("%d", &opcion);
	} while (opcion < 1 || opcion > 5);
	
	clearBoard(display);
	
	switch (opcion) {
	case 1:
		// 5 grupos de gliders distribuidos al azar
		placeMultiplePatterns(display, gliderPattern, 5, 5);
		break;
	case 2:
		// 5 grupos de blinkers
		placeMultiplePatterns(display, blinkerPattern, 3, 5);
		break;
	case 3:
		// 4 grupos de toads
		placeMultiplePatterns(display, toadPattern, 6, 4);
		break;
	case 4:
		// 3 grupos de beacons
		placeMultiplePatterns(display, beaconPattern, 6, 3);
		break;
	case 5:
		// Aleatorio con 40% densidad
		randomizeBoard(display, 40);
		break;
	}
	
	for (int gen = 0; gen < generations; ++gen) {
		for (int i = 0; i < GAME_WIDTH; ++i) {
			for (int j = 0; j < GAME_HEIGHT; ++j) {
				swap[i][j] = isAlive(display, i, j) ? 1 : 0;
			}
		}
		
		draw(swap);
		printf("Generación %d de %d\n", gen + 1, generations);
		memcpy(display, swap, sizeof(display));
		SLEEP(400);
	}
	
	printf("\nSimulación finalizada.\n");
	return 0;
}
