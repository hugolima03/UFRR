#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define MAX 69

int main(int argc, char **argv)
{
  int indice;
  char **nomes;

  nomes = malloc(sizeof(char *) * TAM);

  for (indice = 0; indice < TAM; indice++)
  {
    nomes[indice] = malloc(sizeof(char) * 100);
  }

  for (int l = 0; l < TAM; l++)
  {
    printf("\nDigite o nome da posicao %d.\n", l);

    scanf("%s", nomes[l]);
  }

  for (int l = 0; l < TAM; l++)
  {
    printf("\nNome na posicao %d: %s\n", l, nomes[l]);
  }

  for (indice = 0; indice < TAM; indice++)
  {
    free(nomes[indice]); //Libera a String
  }

  free(nomes);
  return 0;
}
