#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char nomes[5][25];
  int l;

  for (l = 0; l < 5; l++)
  {
    printf("\nDigite o nome da posicao %d.\n", l);

    scanf("%s", nomes[l]);
  }

  for (l = 0; l < 5; l++)
  {
    printf("\nNome na posicao %d: %s", l, nomes[l], '\n');
  }

  return 0;
}