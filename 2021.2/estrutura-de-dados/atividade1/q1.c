// 1 - Faça um programa que leia uma string e a inverta, imprimindo na tela a string invertida.
#include <stdio.h>
#include <string.h>

void revstr(char *str1)
{
  int i, len, temp;
  len = strlen(str1);

  for (i = 0; i < len / 2; i++)
  {
    temp = str1[i];
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
  }
}

int main()
{
  char str[50];
  printf(" Digite qualquer texto: ");
  scanf("%s", str);
  printf(" \n Antes de inverter: %s \n", str);

  revstr(str);
  printf(" Depois de inverter: %s", str);
}