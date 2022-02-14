// Implementação de uma lista circular duplamente encadeada

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

// void List_remove_by_index(CircList *L, int index) {
//   CircNode *p = L->begin;
//   for (int i = 0; i < L->size; i++) {
//     if (i == index) {
//       if (L->begin->val == p->val) {
//         L->begin = p->next;
//         p->next->prev = L->end;
//         L->end->next = L->begin;
//       } else {
//         p->prev->next = p->next;
//       }

//       free(p);
//       L->size--;
//     }
//     p = p->next;
//   }
// }

void removeDuplicate(CircList *L) {
  CircNode *current = L->begin, *index = NULL, *temp = NULL;
  if (L->begin == NULL) {
    printf("Lista vazia");
  } else {
    do {
      temp = current;
      // index sempre armazenará o proximo node da variavel temp
      index = current->next;
      while (index != L->begin) {
        if (current->val == index->val) {
          // index aponta para o node duplicata de current
          // pulamos então a duplicata
          temp->next = index->next;
          L->size--;
        } else {
          // temp aponta para o node anterior de index.
          temp = index;
        }
        index = index->next;
      }
      current = current->next;
    } while (current->next != L->begin);
  }
}

// ----------- TESTE DO CÓDIGO ------------
int main() {
  CircList *L = create_list();
  CircList_add_first(L, 7);
  CircList_add_first(L, 5);
  CircList_add_first(L, 4);
  CircList_add_first(L, 2);
  CircList_add_first(L, 10);
  CircList_add_first(L, 2);
  CircList_add_first(L, 10);
  CircList_add_first(L, 2);
  CircList_add_first(L, 10);

  removeDuplicate(L);

  CircList_print(L);

  // destroy_list(&L);
  return 0;
}