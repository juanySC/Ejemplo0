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
void resaltarJugadaGanadora(char tablero[3][3], char jugador); // 




// Definici�n de colores para "X" y "O"
#define COLOR_X 12  // Rojo para X
#define COLOR_O 9   // Azul para O

// Funci�n para mover el cursor a una posici�n espec�fica en la consola
int gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	return 1;
}

// Funci�n para cambiar el color del texto
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
	
	// Parpadeo del texto lo hace 6 veces, entre azul y rojo luego vuelve a estandar
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
	system("cls"); //borrado de consola
	dibujarMarco();
	gotoxy(18, 14);
	printf("%s", mensaje);
	gotoxy(0, 25);
	Sleep(5000);
}

void dibujarTablero(char tablero[3][3]) {
	// Coordenadas base para dibujar el tablero en la consola
	int baseX = 5, baseY = 6;
	
	// Dibuja las dos l�neas horizontales del tablero
	for (int i = 0; i < 2; i++) {
		int y = baseY + 6 * (i + 1); // Calcula la posici�n Y de la l�nea
		for (int x = 5; x < 40; x++) {
			gotoxy(x, y);            // Mueve el cursor a la posici�n (x, y)
			printf("*");             // Dibuja un asterisco como parte de la l�nea horizontal
		}
	}
	
	// Dibuja las dos l�neas verticales del tablero
	for (int i = 0; i < 2; i++) {
		int x = baseX + 11 * (i + 1); // Calcula la posici�n X de la l�nea
		for (int y = 5; y < 24; y++) {
			gotoxy(x, y);             // Mueve el cursor a la posici�n (x, y)
			printf("*");              // Dibuja un asterisco como parte de la l�nea vertical
		}
	}
	
	// Dibuja el contenido del tablero (X, O o espacio) en cada celda
	for (int i = 0; i < 3; i++) {             // Recorre las filas
		for (int j = 0; j < 3; j++) {         // Recorre las columnas
			int x = baseX + j * 11 + 4;       // Calcula la posici�n X del car�cter
			int y = baseY + i * 6 + 2;        // Calcula la posici�n Y del car�cter
			gotoxy(x, y);                     // Posiciona el cursor en la celda correspondiente
			
			// Cambia el color del texto seg�n el s�mbolo (si es X u O)
			if (tablero[i][j] == 'X') {
				cambiarColor(COLOR_X);        // Aplica el color correspondiente a 'X'
			} else if (tablero[i][j] == 'O') {
				cambiarColor(COLOR_O);        // Aplica el color correspondiente a 'O'
			}
			
			printf("%c", tablero[i][j]);      // Imprime el car�cter de la celda (X, O o espacio)
			
			cambiarColor(7);                  // Restaura el color a blanco
		}
	}
}


int verificarGanador(char tablero[3][3], char jugador) {
	// Recorre cada fila y columna
	for (int i = 0; i < 3; i++) {
		// Verifica si hay una fila completa del mismo jugador
		if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador)
			return 1;
		
		// Verifica si hay una columna completa del mismo jugador
		if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador)
			return 1;
	}
	
	// Verifica si la diagonal principal (de arriba izquierda a abajo derecha) es del mismo jugador
	if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador)
		return 1;
	
	// Verifica si la diagonal secundaria (de arriba derecha a abajo izquierda) es del mismo jugador
	if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador)
		return 1;
	
	// Si no se encontr� ning�n ganador, retorna 0
	return 0;
}


int tableroLleno(char tablero[3][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tablero[i][j] == ' ') return 0;
	return 1;
}// Funci�n que define el movimiento de la CPU en el nivel Medio
// Intenta bloquear al jugador si est� a punto de ganar, si no, hace un movimiento aleatorio
void cpuMovimientoMedio(char tablero[3][3], char jugador, char cpu) {
	// Recorre todas las posiciones del tablero
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Si la celda est� vac�a
			if (tablero[i][j] == ' ') {
				// Simula que el jugador hace un movimiento en esa celda
				tablero[i][j] = jugador;
				
				// Verifica si ese movimiento le dar�a la victoria al jugador
				if (verificarGanador(tablero, jugador)) {
					// Si es as�, bloquea al jugador colocando la ficha de la CPU
					tablero[i][j] = cpu;
					return; // Finaliza el turno de la CPU
				}
				
				// Si no era una jugada ganadora, revierte el movimiento simulado
				tablero[i][j] = ' ';
			}
		}
	}
	
	// Si no hubo necesidad de bloquear, la CPU hace un movimiento aleatorio
	int r, c;
	do {
		// Genera una fila y columna aleatoria
		r = rand() % 3;
		c = rand() % 3;
	} while (tablero[r][c] != ' '); // Repite hasta encontrar una celda vac�a
	
	// Coloca su ficha en la posici�n aleatoria
	tablero[r][c] = cpu;
}


// Funci�n que define el movimiento de la CPU en el nivel Dif�cil
// Primero intenta ganar, si no puede, bloquea al jugador. Si no es necesario, hace un movimiento aleatorio.
void cpuMovimientoDificil(char tablero[3][3], char jugador, char cpu) {
	
	// Primer paso: la CPU intenta ganar
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Verifica si la celda est� vac�a
			if (tablero[i][j] == ' ') {
				// Simula colocar su ficha en esa celda
				tablero[i][j] = cpu;
				
				// Si este movimiento le da la victoria, lo realiza y termina
				if (verificarGanador(tablero, cpu)) {
					return;
				}
				
				// Si no gana, deshace el movimiento
				tablero[i][j] = ' ';
			}
		}
	}
	
	// Segundo paso: bloquear al jugador si est� a punto de ganar
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// Verifica si la celda est� vac�a
			if (tablero[i][j] == ' ') {
				// Simula que el jugador coloca su ficha
				tablero[i][j] = jugador;
				
				// Si el jugador ganar�a, la CPU lo bloquea con su ficha
				if (verificarGanador(tablero, jugador)) {
					tablero[i][j] = cpu;
					return;
				}
				
				// Si no era una jugada ganadora, deshace el movimiento
				tablero[i][j] = ' ';
			}
		}
	}
	
	// Tercer paso: si no hay amenazas ni oportunidades, hace un movimiento aleatorio
	int r, c;
	do {
		r = rand() % 3; // Fila aleatoria
		c = rand() % 3; // Columna aleatoria
	} while (tablero[r][c] != ' '); // Repite hasta encontrar una celda vac�a
	
	// Coloca su ficha en la posici�n aleatoria encontrada
	tablero[r][c] = cpu;
}


// Funci�n para jugar una partida en nivel F�cil (CPU hace movimientos completamente aleatorios)
void jugarFacil() {
	pantallaCarga();  // Muestra una pantalla de carga inicial
	
	// Inicializa el tablero vac�o (3x3)
	char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int fila = 0, col = 0, jugadas = 0;  // Coordenadas del cursor y contador de jugadas
	char jugador, cpu;
	
	// Se asigna aleatoriamente si el jugador ser� 'X' o 'O'
	jugador = rand() % 2 == 0 ? 'X' : 'O';
	cpu = jugador == 'X' ? 'O' : 'X';  // La CPU usar� el s�mbolo opuesto
	
	// Opci�n 1: Posibilidad de que la CPU comience con una jugada aleatoria
	if (rand() % 2 == 1) {
		int r, c;
		do {
			r = rand() % 3;
			c = rand() % 3;
		} while (tablero[r][c] != ' ');  // Repetir hasta encontrar una celda vac�a
		tablero[r][c] = cpu;  // CPU realiza su jugada
		jugadas++;  // Incrementa el n�mero de jugadas
	}
	
	// Bucle principal del juego
	while (1) {
		system("cls");  // Limpia la pantalla
		dibujarMarco();  // Dibuja el marco decorativo
		dibujarTablero(tablero);  // Dibuja el estado actual del tablero
		
		// Calcula las coordenadas del cursor visual seg�n fila y columna
		int x = 5 + col * 11 + 4;
		int y = 6 + fila * 6 + 2;
		gotoxy(x, y);  // Coloca el cursor visual
		
		char tecla = toupper(getch());  // Captura una tecla y la convierte a may�scula
		
		// Movimiento del cursor con WASD
		if (tecla == 'W' && fila > 0) fila--;
		else if (tecla == 'S' && fila < 2) fila++;
		else if (tecla == 'A' && col > 0) col--;
		else if (tecla == 'D' && col < 2) col++;
		
		// Si se presiona ENTER y la celda est� vac�a
		else if (tecla == '\r') {
			if (tablero[fila][col] == ' ') {
				tablero[fila][col] = jugador;  // Jugador hace su jugada
				jugadas++;  // Incrementa el n�mero de jugadas
				
				// Verifica si el jugador gan�
				if (verificarGanador(tablero, jugador)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					resaltarJugadaGanadora(tablero, jugador);  // Resalta las fichas ganadoras
					mostrarMensajeFinal("GANO");  // Muestra mensaje de victoria
					return;
				}
				
				// Verifica si ya se llenaron las 9 celdas (empate)
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");  // Muestra mensaje de empate
					return;
				}
				
				// CPU realiza una jugada aleatoria
				int r, c;
				do {
					r = rand() % 3;
					c = rand() % 3;
				} while (tablero[r][c] != ' ');
				tablero[r][c] = cpu;
				jugadas++;
				
				// Verifica si la CPU gan�
				if (verificarGanador(tablero, cpu)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					resaltarJugadaGanadora(tablero, cpu);  // Resalta las fichas ganadoras
					mostrarMensajeFinal("PERDIO");  // Muestra mensaje de derrota
					return;
				}
				
				// Verifica nuevamente si hay empate tras la jugada de la CPU
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");  // Muestra mensaje de empate
					return;
				}
			}
		}
	}
}


// Funci�n que permite jugar una partida en nivel Medio
void jugarMedio() {
	pantallaCarga();  // Muestra una pantalla de carga inicial
	
	// Se inicializa el tablero vac�o (3x3)
	char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int fila = 0, col = 0, jugadas = 0;  // Posici�n del cursor y n�mero de jugadas realizadas
	char jugador, cpu;
	
	// Se asigna aleatoriamente si el jugador ser� 'X' o 'O'
	jugador = rand() % 2 == 0 ? 'X' : 'O';
	cpu = jugador == 'X' ? 'O' : 'X';  // La CPU toma el s�mbolo contrario
	
	// Posibilidad de que la CPU comience (hace un movimiento aleatorio si se activa)
	if (rand() % 2 == 1) {
		int r, c;
		do {
			r = rand() % 3;
			c = rand() % 3;
		} while (tablero[r][c] != ' ');  // Repite hasta encontrar una celda vac�a
		tablero[r][c] = cpu;  // CPU hace su jugada
		jugadas++;  // Se incrementa el contador de jugadas
	}
	
	// Ciclo principal del juego
	while (1) {
		system("cls");  // Limpia la pantalla
		dibujarMarco();  // Dibuja los bordes del tablero
		dibujarTablero(tablero);  // Dibuja el estado actual del tablero
		
		// Calcula la posici�n del cursor seg�n la fila y columna seleccionadas
		int x = 5 + col * 11 + 4;
		int y = 6 + fila * 6 + 2;
		gotoxy(x, y);  // Posiciona el cursor
		
		// Captura la tecla que presiona el usuario
		char tecla = toupper(getch());
		
		// Control del cursor con teclas W, A, S, D
		if (tecla == 'W' && fila > 0) fila--;
		else if (tecla == 'S' && fila < 2) fila++;
		else if (tecla == 'A' && col > 0) col--;
		else if (tecla == 'D' && col < 2) col++;
		
		// Si se presiona ENTER
		else if (tecla == '\r') {
			// Verifica que la celda est� vac�a
			if (tablero[fila][col] == ' ') {
				tablero[fila][col] = jugador;  // Jugador coloca su ficha
				jugadas++;  // Aumenta el n�mero de jugadas
				
				// Verifica si el jugador ha ganado
				if (verificarGanador(tablero, jugador)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					resaltarJugadaGanadora(tablero, jugador);  // Resalta la l�nea ganadora
					mostrarMensajeFinal("GANO");  // Muestra mensaje de victoria
					return;
				}
				
				// Si el tablero est� lleno, es un empate
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);  // Pausa para mostrar el empate
					mostrarMensajeFinal("EMPATO");
					return;
				}
				
				// CPU realiza su jugada con inteligencia de nivel Medio
				cpuMovimientoMedio(tablero, jugador, cpu);
				jugadas++;
				
				// Verifica si la CPU ha ganado
				if (verificarGanador(tablero, cpu)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					resaltarJugadaGanadora(tablero, cpu);  // Resalta la l�nea ganadora
					mostrarMensajeFinal("PERDIO");  // Muestra mensaje de derrota
					return;
				}
				
				// Verifica nuevamente si hay empate tras la jugada de la CPU
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


// Funci�n para jugar una partida de Totito en nivel Dif�cil
void jugarDificil() {
	pantallaCarga();  // Muestra la animaci�n o pantalla de carga
	
	// Inicializa el tablero vac�o (3 filas x 3 columnas)
	char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int fila = 0, col = 0, jugadas = 0;  // Posiciones actuales del cursor y n�mero total de jugadas
	
	char jugador, cpu;
	// Asigna aleatoriamente 'X' u 'O' al jugador
	jugador = rand() % 2 == 0 ? 'X' : 'O';
	cpu = jugador == 'X' ? 'O' : 'X';  // La CPU toma el s�mbolo contrario
	
	// La CPU podr�a empezar la partida haciendo su primer movimiento
	if (rand() % 2 == 1) {
		int r, c;
		do {
			r = rand() % 3;
			c = rand() % 3;
		} while (tablero[r][c] != ' ');  // Busca una celda libre
		
		// En nivel Dif�cil, no se hace un movimiento aleatorio: se usa la l�gica avanzada
		cpuMovimientoDificil(tablero, jugador, cpu);  // Movimiento inteligente de la CPU
		jugadas++;  // Se incrementa el n�mero de jugadas
	}
	
	// Bucle principal del juego
	while (1) {
		system("cls");  // Limpia la pantalla
		dibujarMarco();  // Dibuja los bordes del �rea de juego
		dibujarTablero(tablero);  // Muestra el estado actual del tablero
		
		// Calcula las coordenadas del cursor gr�fico basado en fila y columna
		int x = 5 + col * 11 + 4;
		int y = 6 + fila * 6 + 2;
		gotoxy(x, y);  // Posiciona el cursor en pantalla
		
		// Captura el movimiento del jugador
		char tecla = toupper(getch());  // Convierte la tecla a may�scula (por si es min�scula)
		if (tecla == 'W' && fila > 0) fila--;  // Mover arriba
		else if (tecla == 'S' && fila < 2) fila++;  // Mover abajo
		else if (tecla == 'A' && col > 0) col--;  // Mover izquierda
		else if (tecla == 'D' && col < 2) col++;  // Mover derecha
		
		// Cuando el jugador presiona ENTER (hace su jugada)
		else if (tecla == '\r') {
			if (tablero[fila][col] == ' ') {  // Si la casilla est� vac�a
				tablero[fila][col] = jugador;  // Se coloca el s�mbolo del jugador
				jugadas++;  // Se incrementa el n�mero de jugadas
				
				// Verifica si el jugador ha ganado
				if (verificarGanador(tablero, jugador)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					resaltarJugadaGanadora(tablero, jugador);  // Resalta l�nea ganadora
					mostrarMensajeFinal("GANO (ERROR)");  // En dif�cil, se supone que el jugador no debe ganar
					return;
				}
				
				// Si se han hecho 9 jugadas y no hay ganador, es empate
				if (jugadas == 9) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					Sleep(5000);
					mostrarMensajeFinal("EMPATO");  // Mensaje de empate
					return;
				}
				
				// Movimiento de la CPU con inteligencia avanzada
				cpuMovimientoDificil(tablero, jugador, cpu);
				jugadas++;  // Aumenta n�mero de jugadas
				
				// Verifica si la CPU ha ganado
				if (verificarGanador(tablero, cpu)) {
					system("cls");
					dibujarMarco();
					dibujarTablero(tablero);
					resaltarJugadaGanadora(tablero, cpu);
					mostrarMensajeFinal("PERDIO");  // Muestra mensaje de derrota del jugador
					return;
				}
				
				// Si ya se llen� el tablero tras el turno de la CPU y no hay ganador
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
	const char* linea1 = "Sergio Alejandro Sagastume Gonzalez Programacion I 202508005";
	const char* linea2 = "Annelis Juany Sacalxot Chojolan Programacion I 202508040";
	int y = 0;
	int alternadorColor = 0;
	
	while (y < 26) {  // L�mite inferior de la pantalla
		// Alterna el color de fondo entre morado y verde oscuro
		if (alternadorColor % 2 == 0)
			system("color 5F");  // Fondo morado
		else
			system("color 2F");  // Fondo verde oscuro
		
		system("cls");  // Limpia la pantalla
		gotoxy(10, y);  // Imprime la primera l�nea en la posici�n actual
		printf("%s", linea1);
		gotoxy(10, y + 2);  // Imprime la segunda l�nea dos l�neas abajo
		printf("%s", linea2);
		
		Sleep(200);  // Controla la velocidad del efecto
		y++;  // Mueve una l�nea hacia abajo
		alternadorColor++;  // Cambia el color en el siguiente ciclo
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

// Resalta en pantalla la l�nea ganadora del jugador
void resaltarJugadaGanadora(char tablero[3][3], char jugador) {
	int baseX = 5, baseY = 6;  // Coordenadas base para posicionar el cursor gr�ficamente
	int i;
	
	// Cambia el color del texto a amarillo (color 14 en la consola de Windows)
	cambiarColor(14);
	
	// Verificaci�n de filas 
	for (i = 0; i < 3; i++) {
		// Si la fila i tiene los 3 s�mbolos iguales al del jugador
		if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) {
			for (int j = 0; j < 3; j++) {
				// Calcula la posici�n X e Y para cada celda de la fila
				gotoxy(baseX + j * 11 + 4, baseY + i * 6 + 2);
				printf("%c", tablero[i][j]);  // Imprime el s�mbolo resaltado
			}
			Sleep(1500);  // Pausa para mostrar el resaltado
			cambiarColor(7);  // Restaura el color por defecto (gris)
			return;
		}
	}
	
	// Verificaci�n de columnas 
	for (i = 0; i < 3; i++) {
		// Si la columna i tiene los 3 s�mbolos del jugador
		if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) {
			for (int j = 0; j < 3; j++) {
				// Calcula la posici�n para cada celda de la columna
				gotoxy(baseX + i * 11 + 4, baseY + j * 6 + 2);
				printf("%c", tablero[j][i]);  // Imprime s�mbolo resaltado
			}
			Sleep(1500);
			cambiarColor(7);
			return;
		}
	}
	
	// Verificaci�n de diagonal principal (de arriba izquierda a abajo derecha) 
	if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) {
		for (i = 0; i < 3; i++) {
			gotoxy(baseX + i * 11 + 4, baseY + i * 6 + 2);
			printf("%c", tablero[i][i]);
		}
		Sleep(1500);
		cambiarColor(7);
		return;
	}
	
	// Verificaci�n de diagonal secundaria (de arriba derecha a abajo izquierda) 
	if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) {
		for (i = 0; i < 3; i++) {
			gotoxy(baseX + (2 - i) * 11 + 4, baseY + i * 6 + 2);
			printf("%c", tablero[i][2 - i]);
		}
		Sleep(1500);
		cambiarColor(7);
		return;
	}
}



int main() {
	srand(time(NULL));
	menuInicio();  // Mostrar el men� inicial
	return 0;
}

