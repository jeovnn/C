#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_PILHA 100

struct pilha {
    int topo;
    char itens[TAMANHO_PILHA];
};

void push(struct pilha *p, char e) {
    p->itens[++(p->topo)] = e;
}

char pop(struct pilha *p) {
    return p->itens[p->topo--];
}

void verificar_palindromo(char nome[]) {
    struct pilha p;
    p.topo = -1;
    int i = 0;
    int palindromo = 1;

    while (nome[i] != '\0') {
        push(&p, nome[i]);
        i++;
    }

    i = 0;
    while (nome[i] != '\0') {
        if (nome[i] != pop(&p)) {
            palindromo = 0;
            break;
        }
        i++;
    }

    if (palindromo) {
        printf("\nO nome \"%s\" e um palindromo!\n", nome);
    } else {
        printf("\nO nome \"%s\" NAO e um palindromo!\n", nome);
    }
}

int main() {
    char nome[100];

    printf("Digite um nome: ");
    scanf("%s", nome);

    verificar_palindromo(nome);

    return 0;
}
