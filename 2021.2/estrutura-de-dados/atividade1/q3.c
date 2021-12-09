// 3 - Faça um programa que leia 10 números inteiros e armazene em uma matriz. Depois,
// utilize a aritmética de ponteiros para imprimir todos os elementos da matriz.

#include <stdio.h>
#include <stdlib.h>
#define m 5
#define n 2

int main()
{
  int **a;
  a = (int **)malloc(m * sizeof(int *));
  for (int i = 0; i < m; i++)
  {
    a[i] = (int *)malloc(n * sizeof(int));
  }

  printf("Digite os elementos da matriz 5x2:\n ");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  printf("Os elementos são: \n");
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < m; i++)
  {
    free(a[i]);
  }
  free(a);
  return 0;
}
