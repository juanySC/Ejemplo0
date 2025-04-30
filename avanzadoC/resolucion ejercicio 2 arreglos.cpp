#include <stdio.h>
#include <windows.h>
#include <time.h>
int vector[10];

int main (){
	//para ver los numero mayor y menor
	int max = vector[0], indice_max = 0;
	int min = 100000, indice_min = 0;
	
	printf("Ingrese los valores\t");
	srand(unsigned(time(NULL)));
	for(int i = 0; i < 10; i++){
		printf("\t %1s %d %1s ","{", i, "}" );
		vector[i] = rand()%10000;
		printf("%10d\n", vector[i]);
		if(max<vector[i]){
			max = vector[i];
			indice_max = i;
		}
		if(min>vector[i]){
			min = vector[i];
			indice_min = i;
		}
		Sleep(300);
	}
	
	printf("\nValor maximo \t%10d", max);
	printf("\tubicado en maximo \t%10d", indice_max);
	printf("\nValor minimo\t%10d", min);
	printf("\tubicado en minimo \t%10d", indice_min);
}
