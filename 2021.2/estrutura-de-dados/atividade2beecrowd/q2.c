#include <stdio.h>
#include <stdlib.h>

void insertion_sort_ascending(int lista[], int n) {
  int i;
  for (i = 1; i < n; i++) {
    int chave = lista[i];
    int j = i - 1;

    while (j >= 0 && lista[j] > chave) {
      lista[j + 1] = lista[j];
      j--;
    }
    lista[j + 1] = chave;
  }
}

void insertion_sort_descending(int lista[], int n) {
  int i;
  for (i = 1; i < n; i++) {
    int chave = lista[i];
    int j = i - 1;

    while (chave > lista[j] && j >= 0) {
      lista[j + 1] = lista[j];
      j--;
    }
    lista[j + 1] = chave;
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  int n, i, num, par, impar;

  scanf("%d", &n);
  par = 0;
  impar = 0;
  int np[n];
  int ni[n];

  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    if (num % 2 == 0) {
      np[par] = num;
      par++;
    } else {
      ni[impar] = num;
      impar++;
    }
  }

  insertion_sort_ascending(np, par);
  insertion_sort_descending(ni, impar);
  printArray(np, par);
  printArray(ni, impar);

  return 0;
}
