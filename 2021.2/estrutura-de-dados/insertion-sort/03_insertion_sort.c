#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int lista[], int n) {
  for (int i = 1; i < n; i++) {
    int chave = lista[i];
    int j = i - 1;

    while (j >= 0 && lista[j] > chave) {
      lista[j + 1] = lista[j];
      j--;
    }
    lista[j + 1] = chave;
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int lista[] = {4, 7, 2, 5, 4, 0};

  int n = sizeof(lista) / sizeof(lista[0]);
  printArray(lista, n);

  insertion_sort(lista, n);

  printArray(lista, n);
  return 0;
}