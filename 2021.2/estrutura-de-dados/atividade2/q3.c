#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vetor = NULL, num_elementos = 0, num;
  do
  {
    printf("\nDigite um numero(digite 0 para sair): ");
    scanf("%d", &num);

    if (num)
    {
      num_elementos++;
      vetor = (int *)realloc(vetor, num_elementos * sizeof(int));

      printf("%d", num);
      if (!vetor)
      {
        printf("\nERROR!\n");
        exit(1);
      }
      vetor[num_elementos - 1] = num;
    }
  } while (num);

  for (; num < num_elementos; num++)
    printf("\nO elemento %d do vetor eh %d\n", num + 1, *(vetor + num));
  free(vetor);
}