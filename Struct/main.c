#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
    char genero;
    double peso;
} Pessoa;

void mostrarPessoaPorValor(Pessoa p) {
    printf("\n[Por Valor] Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f\n", p.altura);
    printf("Gênero: %c\n", p.genero);
    printf("Peso: %.2lf\n", p.peso);
}

void atualizarIdadePorReferencia(Pessoa *p) {
    p->idade += 1;
}

int main() {
    Pessoa pessoa1;

    strcpy(pessoa1.nome, "Carlos");
    pessoa1.idade = 25;
    pessoa1.altura = 1.75;
    pessoa1.genero = 'M';
    pessoa1.peso = 70.5;

    mostrarPessoaPorValor(pessoa1);
    atualizarIdadePorReferencia(&pessoa1);

    printf("\nApos alteracao por referencia:\n");
    mostrarPessoaPorValor(pessoa1);

    return 0;
}




