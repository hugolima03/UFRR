//  Calcular a soma entre dois números n1 e n2 incluindo os limites Soma(3,7) = 3+4+5+6+7 = 25
#include <stdio.h>

int sum(int n, int m)
{
  if (n >= m)
  {
    return n;
  }
  else
  {
    return n + sum(n + 1, m);
  }
}

int main()
{
  int n, m, ret;

  printf("Insira n e m: ");
  scanf("%d %d", &n, &m);

  if (n < m)
    ret = sum(n, m);
  else
    ret = sum(m, n);

  printf("A soma do intervalo é %d\n", ret);

  return 0;
}