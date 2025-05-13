#include <stdio.h>
#define MAXIMO 10

typedef struct {
    int itens[MAXIMO];
    int frente, tras;
} fila;

void inicializar(fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int estaCheia(fila *f) {
    return (f->tras + 1) % MAXIMO == f->frente;
}

int estaVazia(fila *f) {
    return f->frente == f->tras;
}

int inserir(fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return 0;
    }
    f->itens[f->tras] = valor;
    f->tras = (f->tras + 1) % MAXIMO;
    return 1;
}

int remover(fila *f, int *valorRemovido) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *valorRemovido = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAXIMO;
    return 1;
}

int proximo(fila *f, int *valor) {
    if (estaVazia(f)) {
        return 0;
    }
    *valor = f->itens[f->frente];
    return 1;
}

int tamanho(fila *f) {
    return (f->tras - f->frente + MAXIMO) % MAXIMO;
}

void imprimir(fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia\n");
        return;
    }

    printf("Fila: ");
    int i = f->frente;
    while (i != f->tras) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % MAXIMO;
    }
    printf("\n");
}

int menu() {
    int op;
    printf("\n--- MENU ---\n");
    printf("1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Proximo a sair\n");
    printf("4 - Tamanho atual\n");
    printf("5 - Sair\n");
    printf("Opcao: ");
    scanf("%d", &op);
    return op;
}

int main() {
    fila f;
    inicializar(&f);
    int op, valor;

    do {
        op = menu();
        switch(op) {
            case 1:
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                inserir(&f, valor);
                break;
            case 2:
                if (remover(&f, &valor))
                    printf("Valor removido: %d\n", valor);
                break;
            case 3:
                if (proximo(&f, &valor))
                    printf("Proximo a sair: %d\n", valor);
                else
                    printf("Fila vazia\n");
                break;
            case 4:
                printf("Tamanho atual da fila: %d\n", tamanho(&f));
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida.\n");
        }

        if (op != 5) {
            imprimir(&f);
        }

    } while (op != 5);

    return 0;
}

