#define NUM 10
#include <stdio.h>

int main(){
	//tipo int
	int nums[NUM];
	
	int i;
	int total = 0;
	
	//apertura de datos
	//varibale de control, condicion, operacion
	printf("\nIngrese los numeros para el arrglo \n");
	for(i=0;i<NUM; i++){
		printf("\n %1s %2d %3s \t","{",i,"} ?");
		scanf("%d",&nums[i]);
		total = total + nums[i];
	}
	
	//muestra mi promedio
	float promedio = (float)total /NUM;
	printf("\nPromedio : %.2f\n", promedio);
	
	//muestra los datos
	printf("\nLista de numeros: ");
	for(i=0;i<NUM; i++){
		printf("\n%d", nums[i]);
	
	}
	
}
	
