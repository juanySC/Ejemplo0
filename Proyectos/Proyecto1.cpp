#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h> // para capturar teclas sin enter

#define MAX_LETRAS 100 // numero máximo de letras activas al mismo tiempo

// estructura para representar cada letra en pantalla facilmente
typedef struct {
	int x;         
	int y;         
	char letra;    
	int activa;    // si es 1 esta cayendo, si es 0 es poque ya cayo o esta inactiva
} Letra;

//prototipos de funciones
int gotoxy(int x, int y);
int dibujoRecuadro();
void esperarEnter();
void actualizarLetras(int* punteo, int* fallos);
void generarNuevaLetra();
void detectarTecla(int* punteo, int* aciertos, int* errores);
void mostrarResumenFinal(int punteo, int aciertos, int errores, int nivel);
char continuar = 'n';


//variables globales
Letra letras[MAX_LETRAS];        // arreglo de letras activas
int limiteInferiorY = 28;        // limite inferior del area de juego

int main() {
	
	do{
	int tiempoCaida = 500;
	int tiempoGenerar = 1500;
	int contadorTiempo = 0;
	
	int punteo = 0;
	int aciertos = 0;
	int errores = 0;
	int nivel = 1;
	int aciertosParaNivel = 25;
	
	char colores[] = { '1', '2', '3', '4', '5', '6', '9', 'A', 'B', 'C', 'D', 'E' }; // sin 0 ni 7
	int colorActual = 0;
	
	
	system("cls");
	srand(time(NULL));
	
	dibujoRecuadro();
	esperarEnter();
	
	while (errores < 10) {
		if (_kbhit()) {
			detectarTecla(&punteo, &aciertos, &errores);
		}
		
		actualizarLetras(&punteo, &errores);
		
		if (contadorTiempo >= tiempoGenerar) {
			generarNuevaLetra();
			contadorTiempo = 0;
		}
		
		Sleep(tiempoCaida);
		contadorTiempo += tiempoCaida;
		
		// Mostrar datos en pantalla
		gotoxy(95, 1); printf("%i ", punteo);
		gotoxy(97, 2); printf("%i ", aciertos);
		gotoxy(95, 3); printf("%i ", errores);
		gotoxy(8, 1); printf("%i ", nivel); // Nivel visible
		
		// Subir nivel cada 10 aciertos
		if (aciertos >= aciertosParaNivel) {
			nivel++;
			aciertosParaNivel += 10;
			
			// Ajustar velocidad
			if (tiempoCaida > 50) tiempoCaida -= 25;
			if (tiempoGenerar > 100) tiempoGenerar -= 25;
			
			// Sonido de beep al subir nivel
			Beep(1000, 300);
			
			// Cambiar color de fondo y texto de forma inteligente
			colorActual = (colorActual + 1) % (sizeof(colores) / sizeof(colores[0]));
			char fondo = colores[colorActual];
			char texto = (fondo >= 'A') ? '0' : 'F'; // negro si fondo claro, blanco si fondo oscuro
			
			char comandoColor[10];
			sprintf(comandoColor, "color %c%c", fondo, texto);
			system(comandoColor);
			
			// Si llegó al nivel 21, termina el juego y muestra resumen
			if (nivel > 20) {
				mostrarResumenFinal(punteo, aciertos, errores, nivel);
				return 0;
			}
		}
	}
	
	mostrarResumenFinal(punteo, aciertos, errores, nivel);
	
	gotoxy(30, 22); printf("¿Deseas jugar otra vez? (s/n): ");
	continuar = _getch(); // <<<<<< capturas la opción
	}while (continuar == 's' || continuar == 'S');
	return 0;
}


// espera a que el usuario presione enter antes de iniciar el juego
void esperarEnter() {

	gotoxy(1, 2); printf("Presiona Enter para comenzar el juego...\n");
	while (getchar() != '\n'); // limpia el buffer si es necesario
	getchar(); // espera Enter
	gotoxy(1, 3); printf("¡El juego ha comenzado!\n");

}

// dibuja el marco del área de juego en la consola
int dibujoRecuadro() {
	int posX = 5;
	int posY = 5;
	
	//int punteo=0;
	//int aciertos=0;
	//int fallos=0;
	
	// esquinas del recuadro
	gotoxy(4, 4);  printf("%c", char(201)); // Esquina superior izquierda
	gotoxy(88, 4); printf("%c", char(187)); // Esquina superior derecha
	gotoxy(4, 28); printf("%c", char(200)); // Esquina inferior izquierda
	gotoxy(88, 28);printf("%c", char(188)); // Esquina inferior derecha
	
	// bordes de X
	while (posX <= 87) {
		gotoxy(posX, 4);  printf("%c", char(205)); // Línea superior
		gotoxy(posX, 28); printf("%c", char(205)); // Línea inferior
		posX += 1;
	}
	
	// bordes de Y
	while (posY <= 27) {
		gotoxy(4, posY);  printf("%c", char(186)); // Lado izquierdo
		gotoxy(88, posY); printf("%c", char(186)); // Lado derecho
		posY += 1;
	}
	
	// titulos
	gotoxy(1, 1);   printf("NIVEL: ");
	gotoxy(88, 1);  printf("PUNTEO:");
	gotoxy(88, 2);  printf("ACIERTOS:");
	gotoxy(88, 3);  printf("FALLOS:");
	
	return 1;
}

// genera una nueva letra aleatoria
void generarNuevaLetra() {
	for (int i = 0; i < MAX_LETRAS; i++) {
		if (!letras[i].activa) {
			letras[i].x = 5 + rand() % 83; // X aleatoria dentro del recuadro
			letras[i].y = 5;              
			letras[i].letra = (rand() % 2 == 0) ? (65 + rand() % 26) : (97 + rand() % 26); // letra aleatoria
			letras[i].activa = 1;          // activa la letra para que comience a caer
			
			gotoxy(letras[i].x, letras[i].y);
			printf("%c", letras[i].letra);
			break;
		}
	}
}

// actualiza la posición de todas las letras activas, osea la caida pues
void actualizarLetras(int* punteo, int* fallos) {
	for (int i = 0; i < MAX_LETRAS; i++) {
		if (letras[i].activa) {
			// borrado
			gotoxy(letras[i].x, letras[i].y);
			printf(" ");
			
			// mover hacia abajo
			letras[i].y++;
			
			// si llega al fondo se desactiva
			if (letras[i].y >= limiteInferiorY) {
				letras[i].activa = 0;
				*punteo -= 2;     // penalización por no eliminar letra
				(*fallos)++;
			} else {
				//permite continuar la caida
				gotoxy(letras[i].x, letras[i].y);
				printf("%c", letras[i].letra);
			}
		}
	}
}

// verifica si la tecla presionada coincide con una letra activa en pantalla
void detectarTecla(int* punteo, int* aciertos, int* errores) {
	char tecla = _getch(); // captura sin esperar enter
	int encontrado = 0;
	
	for (int i = 0; i < MAX_LETRAS; i++) {
		if (letras[i].activa && letras[i].letra == tecla) {
			gotoxy(letras[i].x, letras[i].y); printf(" ");
			letras[i].activa = 0;
			*punteo += 10;
			(*aciertos)++;
			encontrado = 1;
			break;
		}
	}
	
	if (!encontrado) {
		*punteo -= 5;
		(*errores)++;
	}
}

void mostrarResumenFinal(int punteo, int aciertos, int errores, int nivel)
{

	system("cls");
	dibujoRecuadro();
	
	int centroX=30;
	int inicioY=12;
	
	gotoxy(1, 1);   printf("               ");
	gotoxy(88, 1);  printf("               ");
	gotoxy(88, 2);  printf("               ");
	gotoxy(88, 3);  printf("               ");
	
	gotoxy(centroX,inicioY); printf("---------JUEGO TERMINADO---------");
	gotoxy(centroX,inicioY+2);printf("Nivel alcanzado: %d", nivel);
	gotoxy(centroX,inicioY+3);printf("Punteo final: %d", punteo);
	gotoxy(centroX,inicioY+4);printf("Total de aciertos: %d", aciertos);
	gotoxy(centroX,inicioY+5);printf("Total de errores: %d", errores);
	
	gotoxy(centroX, inicioY + 9); printf("Presiona cualquier tecla para salir...");
	printf("Presione s para continuar");
	_getch();

}

int gotoxy(int x, int y) {
	COORD coord;
	HANDLE h_stdout;
	coord.X = x;
	coord.Y = y;
	if ((h_stdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE)
		return 0;
	if (SetConsoleCursorPosition(h_stdout, coord) == 0)
		return 0;
	return 1;
}
