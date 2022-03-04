#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[30];
} string;

void ordena(string *, int tam);

void main() {
  int i;
  int nAlunos, alunoPremiado;

  scanf("%d %d", &nAlunos, &alunoPremiado);
  string alunos[nAlunos];

  for (i = 0; i < nAlunos; i++) scanf("%s", alunos[i].nome);

  ordena(alunos, nAlunos);

  printf("%s\n", alunos[alunoPremiado - 1].nome);
}

void ordena(string *alunos, int tam) {
  short i = 1, j;
  string chave;

  // Algoritmo de insertion sort
  while (i < tam) {
    j = i - 1;
    chave = alunos[i];

    while (j >= 0 && strcmp(alunos[j].nome, chave.nome) > 0) {
      alunos[j + 1] = alunos[j];
      j--;
    }

    alunos[j + 1] = chave;
    i++;
  }
}