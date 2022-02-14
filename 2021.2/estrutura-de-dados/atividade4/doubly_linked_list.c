#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ----------- DEFINIÇÃO DAS ESTRUTURAS ------------
typedef struct _doubly_node {
  int val;
  struct _doubly_node *prev;
  struct _doubly_node *next;
} Doubly_node, Node;

typedef struct _doubly_linked_list {
  Node *begin;
  Node *end;
  size_t size;
} Doubly_linked_list, List;

// ----------- CONSTRUTORES E DESTRUTORES ------------

Node *create_node(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

List *create_list() {
  List *L = (List *)malloc(sizeof(List));
  L->begin = NULL;
  L->end = NULL;
  L->size = 0;
  return L;
}

void destroy_list(List **L_ref) {
  List *L = *L_ref;
  Node *p = L->begin;
  Node *aux = NULL;
  while (p != NULL) {
    aux = p;
    p = p->next;
    free(aux);
  }
  free(L);
  *L_ref = NULL;
}

// ----------- FUNÇÕES --------------------

bool List_is_empty(List *L) { return L->size == 0; }

void List_add_first(List *L, int val) {
  Node *p = create_node(val);
  p->next = L->begin;
  // Caso 1: A lista está vazia
  if (List_is_empty(L)) {
    L->end = p;
  } else {  // Caso 2: A lista não está vazia
    L->begin->prev = p;
  }
  L->begin = p;
  L->size++;
}

void List_print(List *L) {
  Node *p = L->begin;
  printf("L -> ");
  while (p != NULL) {
    printf("%d-> ", p->val);
    p = p->next;
  }
  printf("NULL\n");
}

void List_add_last(List *L, int val) {
  Node *p = create_node(val);
  if (List_is_empty(L)) {
    L->end = p;
    L->begin = p;
  } else {
    p->prev = L->end;
    L->end->next = p;
  }
  L->end = p;
  L->size++;
}

void List_remove(List *L, int val) {
  Node *p = L->begin;
  while (p != NULL) {
    if (p->val == val) {
      if (L->begin->val == val) {
        L->begin = p->next;
        p->next->prev = NULL;
      } else {
        p->prev->next = p->next;
      }

      free(p);
      L->size--;
    }
    p = p->next;
  }
}

// ----------- TESTE DO CÓDIGO ------------
int main() {
  List *L = create_list();
  // List_add_first(L, 7);
  // List_add_first(L, 4);
  // List_add_first(L, 2);
  // List_add_first(L, 10);

  List_add_last(L, 7);
  List_add_last(L, 4);
  List_add_last(L, 2);
  List_add_last(L, 10);

  List_remove(L, 10);

  List_print(L);

  destroy_list(&L);

  return 0;
}