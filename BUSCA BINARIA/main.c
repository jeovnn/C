#include <stdio.h>
#define MAX 10

void ordenar(int vetor[], int tamanho) {
    int i, j;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) return meio;
        else if (vetor[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

void inserir(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX) {
        printf("Vetor cheio.\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && vetor[i] > valor) {
        vetor[i + 1] = vetor[i];
        i--;
    }

    vetor[i + 1] = valor;
    (*tamanho)++;

    ordenar(vetor, *tamanho);

    printf("Valor %d inserido.\n", valor);
}

void remover(int vetor[], int *tamanho, int valor) {
    if (*tamanho == 0) {
        printf("Vetor vazio\n");
        return;
    }

    int i, j;
    for (i = 0; i < *tamanho; i++) {
        if (vetor[i] == valor) {
            for (j = i; j < *tamanho - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            (*tamanho)--;
            printf("Valor %d removido.\n", valor);
            return;
        }
    }
    printf("Valor %d nao encontrado.\n", valor);
}

void mostrar(int vetor[], int tamanho) {
    if (tamanho == 0) {
        printf("Vetor vazio\n");
    } else {
        int i;
        printf("Vetor: ");
        for (i = 0; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");
    }
}

int main() {
    int vetor[MAX];
    int tamanho = 0;
    int opcao, valor, pos;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Inserir valor\n");
        printf("2. Remover valor\n");
        printf("3. Buscar valor (pesquisa binaria)\n");
        printf("4. Mostrar vetor\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                inserir(vetor, &tamanho, valor);
                break;

            case 2:
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);
                remover(vetor, &tamanho, valor);
                break;

            case 3:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                pos = buscaBinaria(vetor, tamanho, valor);
                if (pos != -1)
                    printf("Valor encontrado na posicao %d.\n", pos);
                else
                    printf("Valor nao encontrado.\n");
                break;

            case 4:
                mostrar(vetor, tamanho);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

