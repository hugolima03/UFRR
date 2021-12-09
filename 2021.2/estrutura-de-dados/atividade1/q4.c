// 4 - Elabore um programa que armazene valores aleatórios em um vetor de inteiros de 10
// posições e depois, em outro vetor de ponteiros de inteiros de tamanho 10, coloque os
// endereços dos valores do vetor de inteiros de forma ordenada crescente, ficando a primeira
// posição do vetor de ponteiros com o endereço do menor valor até a última posição
// que conterá o endereço do maior valor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  srand(time(NULL));
  int myInts[10];
  int *myIntsAddresses[10];

  int temp = 0;
  int i;
  int size = sizeof(myInts) / sizeof(myInts[0]);

  // Criando array com valores randomicos
  for (i = 0; i < size; i++)
  {
    myInts[i] = rand() % 100 + 1;
  }

  for (i = 0; i < size; i++)
  {
    printf("Element #%d: %d\n", i, myInts[i]);
  }

  // Ordenando array de valores randomicos
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (myInts[i] > myInts[j])
      {
        temp = myInts[i];
        myInts[i] = myInts[j];
        myInts[j] = temp;
      }
    }
  }

  printf("--------------\n");

  // Criando array com valores randomicos
  for (i = 0; i < size; i++)
  {
    myIntsAddresses[i] = &myInts[i];
  }

  for (i = 0; i < size; i++)
  {
    printf("Element #%d: , %d\n", i, *myIntsAddresses[i]);
  }

  return 0;
}