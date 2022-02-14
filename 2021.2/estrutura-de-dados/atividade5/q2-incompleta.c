// Implementação de uma lista circular duplamente encadeada

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----------- DEFINIÇÃO DAS ESTRUTURAS ------------
typedef struct _circ_node {
  int val;
  struct _circ_node *prev;
  struct _circ_node *next;
} CircNode;

typedef struct _circ_list {
  CircNode *begin;
  CircNode *end;
  size_t size;
} CircList;

// ----------- CONSTRUTORES E DESTRUTORES ------------

CircNode *create_node(int val) {
  CircNode *cnode = (CircNode *)malloc(sizeof(CircNode));
  cnode->val = val;
  cnode->next = cnode;
  cnode->prev = cnode;
  return cnode;
}

CircList *create_list() {
  CircList *L = (CircList *)malloc(sizeof(CircList));
  L->begin = NULL;
  L->end = NULL;
  L->size = 0;
  return L;
}

void destroy_list(CircList **L_ref) {
  CircList *L = *L_ref;
  CircNode *p = L->begin;
  CircNode *aux = NULL;
  for (size_t i = 0; i < L->size; i++) {
    aux = p;
    p = p->next;
    free(aux);
  }
  // while (p != L->end) {
  //   aux = p;
  //   p = p->next;
  //   free(aux);
  // }
  // free(p);
  free(L);
  *L_ref = NULL;
}

// ----------- FUNÇÕES --------------------

bool CircList_is_empty(CircList *L) { return L->size == 0; }

void CircList_add_first(CircList *L, int val) {
  CircNode *p = create_node(val);
  // Caso 1: A lista está vazia
  if (CircList_is_empty(L)) {
    L->begin = p;
    L->end = p;
  } else {  // Caso 2: A lista não está vazia
    p->next = L->begin;
    L->begin->prev = p;
    L->begin = p;
    p->prev = L->end;
    L->end->next = p;
  }
  L->size++;
}

void CircList_print(CircList *L) {
  if (CircList_is_empty(L)) {
    printf("L -> NULL\n");
    printf("L -> begin -> NULL\n");
  } else {
    CircNode *p = L->begin;
    printf("L -> ");
    do {
      printf("%d -> ", p->val);
      p = p->next;
    } while (p != L->begin);
    // printf("\nL-> end -> %d \n", L->end->val);
  }
  printf("\nsize: %lu\n\n", L->size);
}

void removeChar(char *s, char c) {
  int j, n = strlen(s);
  for (int i = j = 0; i < n; i++)
    if (s[i] != c) s[j++] = s[i];

  s[j] = '\0';
}

void sumArrays(CircList *L1, CircList *L2) {
  char destination1[] = "";
  CircList_print(L1);

  CircNode *p = L1->begin;

  for (int i = 0; i < L1->size; i++) {
    char str[42];
    sprintf(str, "%d", p->val);
    strcat(destination1, str);
    p = p->next;
  }

  printf("%s\n", destination1);
}

// ----------- TESTE DO CÓDIGO ------------
int main() {
  CircList *L1 = create_list();
  CircList *L2 = create_list();
  CircList *LSum = create_list();

  char line1[] = "(3 -> 1 -> 5), (5 -> 9 -> 2)";

  removeChar(line1, '(');
  removeChar(line1, ')');
  removeChar(line1, ' ');
  removeChar(line1, '-');
  removeChar(line1, '>');

  char delim1[] = ",";

  char *ptr1 = strtok(line1, delim1);

  int c = 0;
  while (ptr1 != NULL) {
    // printf("%s\n", ptr1);

    if (c == 0) {
      for (int j = 0; j < strlen(ptr1); j++) {
        CircList_add_first(L1, ptr1[j] - '0');
      }
      c++;
    } else {
      for (int j = 0; j < strlen(ptr1); j++) {
        CircList_add_first(L2, ptr1[j] - '0');
      }
    }

    ptr1 = strtok(NULL, delim1);
  }

  // CircList_print(L1);
  // CircList_print(L2);
  sumArrays(L1, L2);

  // destroy_list(&L);
  return 0;
}