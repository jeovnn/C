#include <stdio.h>
#include <stdlib.h>

#define MAX1 5
#define MAX2 10

void selectionSort() {
    int lista[MAX1] = {21, 3, 9, 1, 54};
    int i, j, min, aux;

    for(i = 0; i < MAX1 - 1; i++) {
        min = i;
        for(j = i + 1; j < MAX1; j++) {
            if(lista[j] < lista[min]) {
                min = j;
            }
        }
        aux = lista[i];
        lista[i] = lista[min];
        lista[min] = aux;
    }

    printf("Vetor ordenado com Selection Sort:\n");
    for(i = 0; i < MAX1; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void bubbleSort() {
    int i, j, aux, vetor[MAX2];

    printf("Insira 10 valores:\n");
    for (i = 0; i < MAX2; i++) {
        printf("%dº valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(i = MAX2 - 1; i >= 0; i--) {
        for(j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

    printf("Vetor ordenado com Bubble Sort:\n");
    for(i = 0; i < MAX2; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int opcao;

    do {
        printf("\n       MENU DE ORDENACAO    \n");
        printf("1. Ordenar com Selection Sort (valores fixos)\n");
        printf("2. Ordenar com Bubble Sort (valores digitados)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                selectionSort();
                break;
            case 2:
                bubbleSort();
                break;
            case 0:
                break;
            default:
                printf("Opção invalida\n");
        }

    } while(opcao != 0);

    return 0;
}

