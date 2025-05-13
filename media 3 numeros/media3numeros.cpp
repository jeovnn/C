#include <stdio.h>

int main() {
    float num1, num2, num3, media;
    
    printf("Digite tres numeros: ");
    scanf("%f %f %f", &num1, &num2, &num3);
    
    media = (num1 + num2 + num3) / 3;
    
    printf("A media e: %.2f\n", media);
    
    return 0;
}
