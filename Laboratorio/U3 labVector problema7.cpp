/*Se requiere la gesti�n del parque veh�cular de la empresa Transportes Seguros S. A. cada veh�culo
se gestiona por medio de los siguientes datos:
? C�digo (valor autoincremental)
? Placas (cadena de 6 valores alfanum�ricos, generar los datos de forma aleatoria, los
primeros tres caracteres son d�gitos y los �ltimos tres caracteres son letras may�sculas)
? Marca (cadena de caracteres, el usuario ingresa la marca)
? Modelo (a�o del veh�culo, generar valores aleatorios entre 2010 y 2023)
? Fecha de adquisici�n (ingresar por el usuario en el formato dd/mm/aaaa, utilice una
estructura anidada)
El usuario debe ingresar la cantidad de veh�culos a gestionar, m�ximo 10*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#define MAX_VEHICULOS 10
char continuar = 'n';

//es como una caja, que tiene adentro las caracteristicas: dia, mes y a�o
typedef struct {
	int dia, mes, anio;
} Fecha;

typedef struct {
	int codigo;
	char placa[7];
	char marca[20];
	int modelo;
	Fecha fechaAdq;
} Vehiculo;

void generarPlaca(char placa[]) {
	// Generar placa: 3 d�gitos 
	for (int i = 0; i < 3; i++) placa[i] = rand() % 10 + '0'; 
	// 3 letras may�sculas
	for (int i = 3; i < 6; i++) placa[i] = rand() % 26 + 'A';
	placa[6] = '\0';
}

int fechaValida(int d, int m, int a) {
	if (a < 1900 || a > 2100 || m < 1 || m > 12 || d < 1) return 0;
	//dependiendo el mes son los dias que tiene
	int diasMes[] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) diasMes[1] = 29;
	return d <= diasMes[m - 1];
}


void ingresarVehiculos(Vehiculo v[], int n) {
	for (int i = 0; i < n; i++) {
		v[i].codigo = i + 1;
		generarPlaca(v[i].placa);
		
		printf("\nIngrese marca del veh�culo %d: ", i + 1);
		scanf("%s", v[i].marca);
		
		v[i].modelo = rand() % (2023 - 2010 + 1) + 2010;
		
		do {
			printf("Ingrese fecha de adquisici�n (dd mm aaaa): \n");
			scanf("%d %d %d", &v[i].fechaAdq.dia, &v[i].fechaAdq.mes, &v[i].fechaAdq.anio);
			if (!fechaValida(v[i].fechaAdq.dia, v[i].fechaAdq.mes, v[i].fechaAdq.anio))
				printf("Fecha inv�lida, ingreso de nuevo\n");
		} while (!fechaValida(v[i].fechaAdq.dia, v[i].fechaAdq.mes, v[i].fechaAdq.anio));
	}
}

// Mostrar todos los veh�culos
void mostrarVehiculos(Vehiculo v[], int n) {
	printf("\n DATOS DE LOS VEHICULOS\n");
	for (int i = 0; i < n; i++) {
		printf("\nVeh�culo %d\n", v[i].codigo);
		printf("  Placa:  %s\n", v[i].placa);
		printf("  Marca:  %s\n", v[i].marca);
		printf("  Modelo: %d\n", v[i].modelo);
		printf("  Fecha:  %02d/%02d/%d\n", v[i].fechaAdq.dia, v[i].fechaAdq.mes, v[i].fechaAdq.anio);
	}
}

int main() {
	do{
		Vehiculo lista[MAX_VEHICULOS];
		int cantidad;
	
		srand(time(NULL));
	
		printf("�Cu�ntos veh�culos desea gestionar (m�ximo %d)? ", MAX_VEHICULOS);
		scanf("%d", &cantidad);
	
		if (cantidad < 1 || cantidad > MAX_VEHICULOS) {
			printf("Cantidad inv�lida.\n");
			return 1;
		}
	
		ingresarVehiculos(lista, cantidad);
		mostrarVehiculos(lista, cantidad);
		//si desea volver a meter ecuacion cuadratica
		printf("\n\nDesea imprimir de nuevo s/n");
		continuar=getch();//Para asignar a una variable char
		printf("\n");
	} while(continuar == 's');
	
	return 0;
}
