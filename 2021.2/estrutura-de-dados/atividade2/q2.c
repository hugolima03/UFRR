#include <stdio.h>

int power(int b, int n)
{
  if (n != 0)
  {
    return (b * power(b, n - 1));
  }
  return 1;
}

int main()
{
  int n, m;
  printf("Insira b e n: ");
  scanf("%d %d", &n, &m);

  printf("%d\n", power(n, m));

  return 0;
}