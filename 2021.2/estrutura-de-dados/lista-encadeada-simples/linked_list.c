#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int val;
  struct _node *next;
} Node;

typedef struct _linked_list {
  Node *begin;
} LinkedList;

Node* Node_create(int val) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;
  return newNode;
}

LinkedList* LinkedList_create() {
  LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
  L->begin = NULL;
  
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

void LinkedList_print(LinkedList* L) {
  if (L->begin == NULL) {
    printf("Lista vazia");
  } else {
    Node* p = L->begin;
    while(p != NULL) {
      printf("%d-> ", p->val);
      p = p->next;
    }
  }
}