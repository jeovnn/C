#include <stdio.h>
#define MAX 5

void pesquisar(int *lista){
    int valor, i;
    printf("\nPesquisar: ");
    scanf("%d", &valor);

    for(i = 0; i < MAX; i++){
        if(lista[i] == valor){
            printf("Tem na lista.\n");
            return;
        }
    }
    printf("Nao tem na lista.\n");
}

int main() {
    int lista[MAX] = {21, 3, 9, 1, 54};
    int i, j, min, aux, qtde;
    qtde = MAX;

    for(i = 0; i < qtde - 1; i++) {
        min = i;
        for(j = i + 1; j < qtde; j++) {
            if(lista[j] < lista[min]) {
                min = j;
            }
        }
        aux = lista[i];
        lista[i] = lista[min];
        lista[min] = aux;
    }

    printf("Lista ordenada: ");
    for(i = 0; i < qtde; i++) {
        printf("%d ", lista[i]);
    }

    pesquisar(lista);

    return 0;
}

