#include <stdio.h>
#define MAX 5

int busca(int vetor[], int tam, int n) {
    int inicio = 0;
    int fim = tam - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == n) {
            return meio;
        } else if (vetor[meio] < n) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main() {
    int vetor[MAX] = {1, 2, 8, 78, 99}; 
    int tamanho = MAX;
    int ValorBusca = 8;
    
    int resultado = busca(vetor, tamanho, ValorBusca);
    
    if (resultado != -1) {
        printf("Valor encontrado no índice %d\n", resultado);
    } else {
        printf("Valor não encontrado\n");
    }

    return 0;
}

