#include <stdio.h>
int M[5][4];
//5 filas y 4 columnas

int main(){
	
	/*//imprimo columna en posicion 0
	for(int i = 0; i<=4; i++)
	printf("%5d", M[i][0]);
	
	//imprimo otra columna en posicion 2 (3)
	for(int i = 0;i<=4; i++)
	printf("%5d", M[i][2]);
	
	//imprimo columna
	for(int i = 0;i<=3; i++ )
	printf("%5d", M[2][i]);*/
	
	//imprimo un lugar en especifico
	for(int i = 0;i<=3; i++){
		for(int j = 0;j<=4; j++ )
			printf("%5d", M[j][i]);
	printf("\n");	
	}	
	
}
