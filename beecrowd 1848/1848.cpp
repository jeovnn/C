#include <stdio.h>
#include <string.h>

int main() {
    char entrada[10];
    int total = 0;
    
    for (int i = 0; i < 3; i++) {
        while (1) {
            scanf(" %[^\n]", entrada);
            
            if (strcmp(entrada, "caw caw") == 0) {
                printf("%d\n", total);
                total = 0;
                break;
            } else {
                int valor = 0;
                if (entrada[0] == '*') valor += 4;
                if (entrada[1] == '*') valor += 2;
                if (entrada[2] == '*') valor += 1;
                total += valor;
            }
        }
    }
    
    return 0;
}
