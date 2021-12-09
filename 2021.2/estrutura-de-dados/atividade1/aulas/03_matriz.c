#include <stdio.h>
#define LINHAS 5
#define COLUNAS 2

void printMatriz(int m[][COLUNAS]) {
  int i, j;
  for (i = 0; i < LINHAS; i++) {
    for (j = 0; j < COLUNAS; j++) {
      printf("%d ", m[i][j]);
    }
    printf("\n ");
  }
}

int main() {
  int i,j;
  int mat[LINHAS][COLUNAS] = {{10, 20}, {30, 30}, {50, 60}, {70, 80}, {30, 40}};

  printMatriz(mat);

  return 0;
}