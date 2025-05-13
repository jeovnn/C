#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int i,j,aux,vetor[10],fim;
	fim = 9;
	
	printf("insira os valores:\n");
	for (i = 0; i < 10; i++){
		printf("%d valor: ",i+1);
		scanf("%d", &vetor[i]);
	}
	
	for(i = fim; i >= 0; i--){
		for(j = 0; j < i; j++){
			if (vetor[j]>vetor[j+1]){
				aux = vetor[j];
				vetor[j]= vetor[j+1];
				vetor[j+1]=aux;
			}
		}
	}
	
	for(i = 0; i < 10; i++){
		printf("%d ", vetor[i]);
	}
	
	return 0;
}
