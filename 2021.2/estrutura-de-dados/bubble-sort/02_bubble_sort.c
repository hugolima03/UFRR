#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int lista[], int n) {
  for (int j = 0; j < n - 1; j++) {
    for (int i = 0; i < n - j - 1; i++) {
      if (lista[i] > lista[i + 1]) {
        int aux = lista[i];
        lista[i] = lista[i + 1];
        lista[i + 1] = aux;
      }
    }
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
  int lista[] = {4, 9, 2, 1, 7, 8};
  int n = sizeof(lista) / sizeof(lista[0]);

  printArray(lista, n);
  bubble_sort(lista, n);
  printArray(lista, n);

  return 0;
}