#include <stdio.h>
#define MAXIMO 10

typedef struct {
    int itens[MAXIMO];
    int frente, tras;
} fila;

int inserir(fila* p, int x) {
    if (p->tras >= MAXIMO) {
        printf("\nEstouro da capacidade da fila\n");
        return 0;
    }
    p->itens[p->tras++] = x;
    return 1;
}

int remover(fila* p, int* valorRemovido) {
    if (p->frente == p->tras) {
        printf("\nFila vazia\n");
        return 0;
    }
    *valorRemovido = p->itens[p->frente++];
    return 1;
}

int estaCheia(fila* p) {
    return p->tras >= MAXIMO;
}

int estaVazia(fila* p) {
    return p->frente == p->tras;
}

int proximoElemento(fila* p, int* valor) {
    if (estaVazia(p)) {
        return 0;
    }
    *valor = p->itens[p->frente];
    return 1;
}

void imprimirFila(fila* p) {
    int i;
    if (estaVazia(p)) {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    for (i = p->frente; i < p->tras; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int menu() {
    int op;
    printf("\n\nEscolha a opcao:\n");
    printf("1 - Inserir elemento na fila\n");
    printf("2 - Remover elemento da fila\n");
    printf("3 - Verificar se a fila esta cheia\n");
    printf("4 - Verificar se a fila esta vazia\n");
    printf("5 - Verificar o proximo elemento da fila a sair\n");
    printf("6 - Imprimir a fila\n");
    printf("7 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

int main() {
    fila fila1;
    int op, valor, removido;
    
    fila1.frente = 0;
    fila1.tras = 0;

    do {
        op = menu();
        switch(op) {
            case 1:
                printf("Digite um valor para inserir: ");
                scanf("%d", &valor);
                if (inserir(&fila1, valor)) {
                    printf("Valor %d inserido com sucesso!\n", valor);
                }
                break;

            case 2:
                if (remover(&fila1, &removido)) {
                    printf("Valor %d removido com sucesso!\n", removido);
                }
                break;

            case 3:
                if (estaCheia(&fila1)) {
                    printf("Fila esta cheia.\n");
                } else {
                    printf("Fila nao esta cheia.\n");
                }
                break;

            case 4:
                if (estaVazia(&fila1)) {
                    printf("Fila esta vazia.\n");
                } else {
                    printf("Fila nao esta vazia.\n");
                }
                break;

            case 5:
                if (proximoElemento(&fila1, &valor)) {
                    printf("Proximo elemento da fila a sair: %d\n", valor);
                } else {
                    printf("Fila esta vazia.\n");
                }
                break;

            case 6:
                imprimirFila(&fila1);
                break;

            case 7:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while(op != 7);

    return 0;
}
