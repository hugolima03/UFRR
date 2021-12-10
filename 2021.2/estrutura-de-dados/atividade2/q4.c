#include <stdio.h>
#include <stdlib.h>

// int main()
// {
//   char **nomes;
//   nomes = malloc(sizeof(char *) * 10);

//   int *vetor = NULL;
//   int num_elementos = 0;

//   do
//   {
//     printf("\nDigite uma palavra: \n ");
//     scanf("%d", &num);

//     if (num)
//     {
//     }
//   } while (num);

//   free(vetor);
// }

int main() {
  int **mat, i , j;

  mat = malloc(4 * sizeof(int*));

  for (i = 0; i < 4; i++) {
    mat[i] = malloc(3 * sizeof(int));
  }

  return 0;
}