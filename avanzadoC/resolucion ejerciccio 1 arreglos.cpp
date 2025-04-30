#include <stdio.h>
int vector[10];

int main (){
	//para ver los numero mayor y menor
	int max = vector[0], indice_max = 0;
	int min = 100000, indice_min = 0;
	
	printf("Ingrese los valores\t");
	for(int i = 0; i < 10; i++){
		printf("\t %1s %d %1s ","{", i, "}" );
		scanf("%d", &vector[i]);
		if(max<vector[i]){
			max = vector[i];
			indice_max = i;
		}
		if(min>vector[i]){
			min = vector[i];
			indice_min = i;
		}
	}
	
	printf("\nValor maximo \t%d", max);
	printf("\tubicado en maximo \t%d", indice_max);
	printf("\nValor minimo\t%d", min);
	printf("\tubicado en minimo \t%d", indice_min);
}
