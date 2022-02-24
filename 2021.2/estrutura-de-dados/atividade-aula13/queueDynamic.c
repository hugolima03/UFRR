#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// ----------- DEFINIÇÃO DAS ESTRUTURAS ------------
typedef struct _doubly_node {
  int val;
  struct _doubly_node *prev;
  struct _doubly_node *next;
} Doubly_node, Node;

typedef struct DynamicQueue {
  Node *begin;
  Node *end;
  size_t size;
} DynamicQueue;

// ----------- CONSTRUTORES E DESTRUTORES ------------

Node *create_node(int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->val = val;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

DynamicQueue *create_queue() {
  DynamicQueue *Q = (DynamicQueue *)malloc(sizeof(DynamicQueue));
  Q->begin = NULL;
  Q->end = NULL;
  Q->size = 0;
  return Q;
}

void destroy_queue(DynamicQueue **Q_ref) {
  DynamicQueue *Q = *Q_ref;
  Node *p = Q->begin;
  Node *aux = NULL;
  while (p != NULL) {
    aux = p;
    p = p->next;
    free(aux);
  }
  free(Q);
  *Q_ref = NULL;
}

// ----------- FUNÇÕES --------------------

bool Queue_is_empty(DynamicQueue *Q) { return Q->size == 0; }

void enqueue(DynamicQueue *Q, int val) {
  Node *p = create_node(val);
  p->prev = Q->end;
  // Caso 1: A fila está vazia
  if (Queue_is_empty(Q)) {
    Q->begin = p;
  } else {  // Caso 2: A fila não está vazia
    Q->end->next = p;
  }
  Q->end = p;
  Q->size++;
}

void Queue_print(DynamicQueue *Q) {
  Node *p = Q->begin;
  printf("L -> ");
  while (p != NULL) {
    printf("%d-> ", p->val);
    p = p->next;
  }
  printf("NULL\n");
}

void dequeue(DynamicQueue *Q) {
  if (!Queue_is_empty(Q)) {
    Node *p = Q->begin;

    if (p->next == NULL && p->prev == NULL) {
      Q->begin = NULL;
      Q->end = NULL;
    } else {
      Q->begin = p->next;
      p->next->prev = NULL;
    }
    free(p);
    Q->size--;
  }
}

// ----------- TESTE DO CÓDIGO ------------
int main() {
  DynamicQueue *Q = create_queue();
  enqueue(Q, 7);
  enqueue(Q, 4);
  enqueue(Q, 2);
  enqueue(Q, 10);

  dequeue(Q);
  dequeue(Q);

  Queue_print(Q);

  destroy_queue(&Q);
  return 0;
}