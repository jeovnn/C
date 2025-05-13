#include <stdio.h>

int vetor[10], tamanho = 0;

int main() {
    int opcao, valor, i;
    
    do {
        printf("\n1 - Buscar\n2 - Remover\n3 - Inserir\n4 - Ver vetor\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Valor a buscar: ");
                scanf("%d", &valor);
                for (i = 0; i < tamanho; i++)
                    if (vetor[i] == valor) { printf("Encontrado!\n"); break; }
                if (i == tamanho) printf("Nao encontrado.\n");
                break;
            case 2:
                printf("Valor a remover: ");
                scanf("%d", &valor);
                for (i = 0; i < tamanho; i++)
                    if (vetor[i] == valor) {
                        vetor[i] = vetor[--tamanho];
                        printf("Removido!\n");
                        break;
                    }
                if (i == tamanho) printf("Nao encontrado.\n");
                break;
            case 3:
                if (tamanho < 10) {
                    printf("Valor a inserir: ");
                    scanf("%d", &vetor[tamanho++]);
                } else printf("Vetor cheio!\n");
                break;
            case 4:
                if (tamanho == 0) {
                    printf("Vetor vazio!\n");
                } else {
                    printf("Vetor: ");
                    for (i = 0; i < tamanho; i++)
                        printf("%d ", vetor[i]);
                    printf("\n");
                }
                break;
        }
    } while(opcao);
    
    return 0;
}

