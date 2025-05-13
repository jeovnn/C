#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	 
  //declaro um ponteiro
  int *ptr;
  
  //declaro um variavel inteira
  int a = 2;
  
  //mostrando o valor de a
  printf("valor de a: %d\n", a);
  
  //ponteiro agora recebe endere�o de a
  ptr = &a;
  
  //mostrando o valor do ponteiro que tem o valor do a
  printf("valor do ponteiro: %d\n",*ptr);
  
  //mudando o valor do ponteiro (para isso � preciso usar * antes de ptr = *ptr), a agora tem valor 3 pois o ponteiro aponta para o endereco de a
  *ptr = 3;
  
  //mostrando que a agora vale 3
  printf("mudando valor do ponteiro a variavel a muda o valor: %d\n", a);
  
  // agora exibindo os endere�os
  
  printf("endereco de a: %p\n", &a);
  printf("endereco do ponteiro %p\n", &ptr);
  // o endereco de ambos � diferente no disco 
  
  printf("endereco apontado por ptr: %p\n", ptr);
  // ptr esta recebendo o endereco de a entao ir� exibir o endereco de a
  
  return 0;
}

