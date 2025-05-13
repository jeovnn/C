#include <stdio.h>
#include <stdlib.h>
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

void imprimir_nome_ao_contrario(char nome[]) {
    struct pilha p;
    p.topo = -1;
    int i = 0;

    while (nome[i] != '\0') {
        push(&p, nome[i]);
        i++;
    }

    printf("Nome ao contrario: ");
    while (p.topo != -1) {
        printf("%c", pop(&p));
    }
    printf("\n");
}

int main() {
    char nome[100];

    printf("Digite um nome: ");
    scanf("%s", nome);

    imprimir_nome_ao_contrario(nome);

    return 0;
}
