#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_PILHA 100

struct pilha {
    int topo;
    int itens[TAMANHO_PILHA];
};

int empty(struct pilha *p) {
    return (p->topo == -1);
}

int pop(struct pilha *p) {
    if (empty(p)) {
        printf("\nPilha vazia");
        return -9999;
    }
    return (p->itens[p->topo--]);
}

void push(struct pilha *p, int e) {
    if (p->topo == (TAMANHO_PILHA - 1)) {
        printf("\nEstouro da pilha");
        return;
    }
    p->itens[++(p->topo)] = e;
}

int size(struct pilha *p) {
    return p->topo + 1;
}

int stackpop(struct pilha *p) {
    if (empty(p)) {
        printf("\nPilha vazia");
        return -9999;
    }
    return p->itens[p->topo];
}

void reset(struct pilha *p) {
    p->topo = -1;
    printf("\nPilha reiniciada.");
}

void print_pilha(struct pilha *p) {
    if (empty(p)) {
        printf("\nPilha vazia.");
        return;
    }
    printf("\nElementos da pilha: ");
    int i;
    for (i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
}

int menu() {
    int op;
    puts("\n\nEscolha a opcao\n");
    puts("1 - Inserir elemento na pilha (push)");
    puts("2 - Retirar elemento da pilha (pop)");
    puts("3 - Verificar se a pilha esta vazia");
    puts("4 - Verificar tamanho da pilha");
    puts("5 - Verificar ultimo elemento da pilha (stackpop)");
    puts("6 - Recriar pilha");
    puts("7 - Imprimir pilha");
    puts("9 - Sair");
    scanf("%d", &op);
    return op;
}

int main() {
    struct pilha x;
    x.topo = -1;
    int op, valor;

    do {
        op = menu();
        switch (op) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                push(&x, valor);
                break;
                
            case 2:
                valor = pop(&x);
                if (valor > -9999) {
                    printf("\nRetirado elemento: %d", valor);
                }
                break;

            case 3:
                printf("\nA pilha %s esta vazia.", empty(&x) ? "" : "NAO");
                break;

            case 4:
                printf("\nTamanho da pilha: %d", size(&x));
                break;

            case 5:
                valor = stackpop(&x);
                if (valor > -9999) {
                    printf("\nUltimo elemento da pilha: %d", valor);
                }
                break;

            case 6:
                reset(&x);
                break;

            case 7:
                print_pilha(&x);
                break;
        }
    } while (op != 9);

    return 0;
}

