// 2 - Elabore um programa que declare 4 variáveis do tipo inteiro e 4 do tipo ponteiro para
// inteiro, e faça com que as variáveis ponteiro apontem para as variáveis inteiro. Coloque
// comandos que permitam modificar os valores das variáveis inteiras através das variáveis
// ponteiro. Faça a simulação passo-a-passo para visualizar o que está acontecendo em cada
// linha do programa.
#include <stdio.h>

int swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int add(int *x)
{
  *x = *x + 1;
}

int sub(int *x)
{
  *x = *x - 1;
}

int main()
{
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;

  int *ap;
  int *bp;
  int *cp;
  int *dp;

  swap(&a, &b);
  printf("After swap a: %d, b: %d\n", a, b);

  add(&a);
  printf("After add a: %d\n", a);

  sub(&c);
  printf("After sub c: %d\n", c);

  swap(&a, &d);
  printf("After swap a: %d, d: %d\n", a, d);

  printf("Final values: a: %d b: %d c: %d d: %d", a, b, c, d);
}