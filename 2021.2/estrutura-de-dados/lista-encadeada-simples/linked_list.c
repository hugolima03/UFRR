#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int val;
  struct _node* next;
} Node;

typedef struct _linked_list {
  Node* begin;
  Node* end;
} LinkedList;

Node* Node_create(int val) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

LinkedList* LinkedList_create() {
  LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
  L->begin = NULL;
  L->end = NULL;
  return L;
}

// void LinkedList_add_first(LinkedList* L, int val) {
//   if (L->begin == NULL) {
//     Node* p = Node_create(val);
//     L->begin = p;
//   } else {
//     Node* p = Node_create(val);
//     p->next = L->begin;
//     L->begin = p;
//   }
// }
void LinkedList_add_first(LinkedList* L, int val) {
  Node* p = Node_create(val);
  p->next = L->begin;
  L->begin = p;
}

void LinkedList_add_last_slow(LinkedList* L, int val) {
  Node* q = Node_create(val);
  if (L->begin == NULL) {
    L->begin = q;
  } else {
    Node* p = L->begin;
    // Enquanto o p não é o último nó, ou seja
    // Enquanto houver um próximo nó
    while (p->next != NULL) {
      p = p->next;
    }
    // Neste momento o ponteiro p aponta para
    // o nó final da lista
    p->next = q;
  }
}

void LinkedList_add_last(LinkedList* L, int val) {
  Node* q = Node_create(val);
  if (L->begin == NULL) {
    L->begin = q;
    L->end = q;
  } else {
    L->end->next = q;
    L->end = q;
  }
}

void LinkedList_print(LinkedList* L) {
  if (L->begin == NULL) {
    printf("Lista vazia");
  } else {
    Node* p = L->begin;

    while (p != NULL) {
      printf("%d-> ", p->val);
      p = p->next;
    }
  }
}