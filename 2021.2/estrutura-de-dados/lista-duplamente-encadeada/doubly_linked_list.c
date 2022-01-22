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
  printf("L-> ");
  while (p != NULL) {
    printf("%d-> ", p->val);
    p = p->next;
  }
  printf("NULL\n");
  if (L->end == NULL) {
    printf('L->end = NULL\n');
  } else {
    printf('L->begin = %d\n', L->end->val);
  }
}

// void List_print_inverse(List *L) {
//   Node *p = L->begin;
//   printf("L-> ");
//   while (p != NULL) {
//     printf("%d-> ", p->val);
//     p = p->next;
//   }
//   printf("NULL\n");
//   if (L->begin == NULL) {
//     printf('L->end = NULL\n');
//   } else {
//     printf('L->begin = %d\n', L->begin->val);
//   }
// }

// ----------- TESTE DO CÓDIGO ------------
int main() {
  List *L = create_list();
  List_add_first(L, 7);
  List_add_first(L, 4);
  List_add_first(L, 2);
  List_add_first(L, 10);

  List_print(L);

  destroy_list(&L);
  destroy_list_inverse(&L);

  return 0;
}