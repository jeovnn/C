#include <stdio.h>
#include <stdlib.h>

int main() {
    int numeros[10];
    int i;
    float soma = 0, media;
    
    printf("Digite 10 numeros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }
    
    media = soma / 10;
    
    printf("Numeros digitados: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", numeros[i],",");
    }
    
    printf("\nMedia: %.2f\n", media);
    
    return 0;
}
