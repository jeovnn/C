#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	int lista[10] = {89,8,7,6,5,4,32,1,11,9};
	int aux,i,flag;
	flag = 1;
	
	while(flag){
		flag = 0;
		
		for(i = 0; i < 9; i++){
			if(lista[i]>lista[i+1]){
				aux = lista[i];
				lista[i] = lista[i+1];
				lista[i+1] = aux;
				flag = 1;
			}
		}
		
	}
	
	for(i = 0; i <= 9; i++){
		printf("%d ",lista[i]);
	}
	
	return 0;
}
