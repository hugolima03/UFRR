#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int lista[], int n) {
  for (int j = 0; j < n - 1; j++) {
    int minimoIndex = j;
    // Pega menor int
    for (int i = j; i < n; i++) {
      if (lista[minimoIndex] > lista[i]) {
        minimoIndex = i;
      }
    }
    // Trocar
    int aux = lista[j];
    lista[j] = lista[minimoIndex];
    lista[minimoIndex] = aux;
  }
}

int main() {
  int lista[] = {7, 5, 1, 8, 3};
  int n = sizeof(lista) / sizeof(lista[0]);

  selectionSort(lista, n);

  for (int i = 0; i < n; i++) {
    printf("%d, ", lista[i]);
    if (i == n - 1) printf("\n");
  }

  return 0;
}