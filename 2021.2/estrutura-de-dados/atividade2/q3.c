#include <stdio.h>

int main()
{
  int loop = 1;

  while (loop == 1)
  {
    int temp;
    printf("Digite um número\n");
    scanf("%d", &temp);

    if (temp == 0)
    {
      loop = 0;
    }
    else
    {
      printf("%d\n", temp);
    }
  }

  return 0;
}