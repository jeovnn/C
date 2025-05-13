#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef struct {
    int id;
    time_t entrada;
    time_t saida;
    double tempoFila;
} Elemento;

typedef struct {
    Elemento elementos[MAX];
    int frente;
    int tras;
    int tamanho;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

int filaCheia(Fila *fila) {
    return fila->tamanho == MAX;
}

int filaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

void enfileirar(Fila *fila, int id) {
    if (filaCheia(fila)) {
        printf("Fila cheia!\n");
        return;
    }
    fila->tras = (fila->tras + 1) % MAX;
    fila->elementos[fila->tras].id = id;
    fila->elementos[fila->tras].entrada = time(NULL);
    fila->tamanho++;
}

Elemento desenfileirar(Fila *fila) {
    Elemento elem;
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        elem.id = -1;
        return elem;
    }
    elem = fila->elementos[fila->frente];
    elem.saida = time(NULL);
    elem.tempoFila = difftime(elem.saida, elem.entrada);
    fila->frente = (fila->frente + 1) % MAX;
    fila->tamanho--;
    return elem;
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao, id = 1;
    int totalAtendidos = 0;
    int totalEntraram = 0;
    double somaTempos = 0.0;

    do {
        printf("\n1 - Entrar na fila\n2 - Sair da fila\n3 - Sair do programa\nOpcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            enfileirar(&fila, id++);
            totalEntraram++;
            printf("Elemento entrou na fila!\n");
        } else if (opcao == 2) {
            Elemento atendido = desenfileirar(&fila);
            if (atendido.id != -1) {
                printf("Elemento %d saiu da fila.\n", atendido.id);
                printf("Tempo que ficou na fila: %.2f segundos.\n", atendido.tempoFila);
                totalAtendidos++;
                somaTempos += atendido.tempoFila;
            }
        }
    } while (opcao != 3);

    printf("\n=== Relatório Final ===\n");
    printf("Total de elementos que ENTRARAM na fila: %d\n", totalEntraram);
    printf("Total de elementos que FORAM ATENDIDOS: %d\n", totalAtendidos);

    if (totalAtendidos > 0) {
        printf("Tempo médio de espera dos atendidos: %.2f segundos\n", somaTempos / totalAtendidos);
    } else {
        printf("Nenhum elemento foi atendido.\n");
    }

    return 0;
}



