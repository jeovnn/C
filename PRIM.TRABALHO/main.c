#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
    char genero;
    double peso;
} Pessoa;

void lerDados(Pessoa* p) {
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]", p->nome);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    printf("Digite a altura: ");
    scanf("%f", &p->altura);

    getchar();

    printf("Digite o genero (M/F): ");
    scanf("%c", &p->genero);

    printf("Digite o peso: ");
    scanf("%lf", &p->peso);
}

void exibirDados(Pessoa p) {
    printf("\nDados cadastrados:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Altura: %.2f\n", p.altura);
    printf("Genero: %c\n", p.genero);
    printf("Peso: %.2lf\n", p.peso);
}

int main() {
    Pessoa pessoa1, pessoa2;

    printf("Cadastro da primeira pessoa:\n");
    lerDados(&pessoa1);

    printf("\nCadastro da segunda pessoa:\n");
    lerDados(&pessoa2);

    int escolha;
    
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Mostrar dados da primeira pessoa\n");
        printf("2 - Mostrar dados da segunda pessoa\n");
        printf("3 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                exibirDados(pessoa1);
                break;
            case 2:
                exibirDados(pessoa2);
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 3);  

    return 0;
}


