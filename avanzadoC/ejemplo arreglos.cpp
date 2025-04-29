#define NUM 8
#include <stdio.h>

int main(){
	//tipo int
	int nums [NUM];
	
	int i;
	int total = 0;
	
	//apertura de datos
	//varibale de control, condicion, operacion
	printf("Ingrese los numeros para el arrglo \n");
	for(i=0;i<NUM; i++){
		printf("\n %1s %2d %3s \t","{",i,"} ?");
		scanf("%d",&nums[i]);
	}
	
	/*Otra forma/alternativa
	int i = 0;
	while(i<NUM){
	printf("Ingrese numero");
	scanf(""d",&nums[i]);
	i++;
	}
	*/
	
	//muestra los datos
	printf("\nLista de numeros: ");
	i = 0;
	while(i<NUM){
		printf("%5d", nums[i]);
		total += nums[i];
		i++;
	}
	
	printf("\nSumatoria : %5d",total);
}
