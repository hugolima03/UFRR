#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_queue {
  int *data;
  long capacity;
  long size;
  long begin;
  long end;
} QueueStatic;

// Construtores

QueueStatic *create(long capacity) {
  QueueStatic *Q = (QueueStatic *)malloc(sizeof(QueueStatic));
  Q->capacity = capacity;
  Q->data = (int *)malloc(capacity * sizeof(int));
  Q->size = 0;
  Q->begin = 0;
  Q->end = 0;
  return Q;
}

void destroy(QueueStatic **Q_ref) {
  QueueStatic *Q = *Q_ref;
  free(Q->data);
  free(Q);
  *Q_ref = NULL;
}

// Funções

bool isEmpty(QueueStatic *Q) { return Q->size == 0; }

bool isFull(QueueStatic *Q) { return Q->size == Q->capacity; }

long size(QueueStatic *Q) { return Q->size; }

void enqueue(QueueStatic *Q, int val) {
  if (isFull(Q)) {
    printf("Queue is full!\n");
  } else {
    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity;
    Q->size++;
  }
}

int peek(QueueStatic *Q) {
  if (isEmpty(Q)) {
    printf("Queue is empty!\n");
  } else {
    return Q->data[Q->begin];
  }
}

int denqueue(QueueStatic *Q) {
  if (isEmpty(Q)) {
    printf("Queue is empty!\n");
  } else {
    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity;
    Q->size--;
    return val;
  }
}

void printQueue(QueueStatic *Q) {
  printf("Capacity: %ld\n", Q->capacity);
  printf("Size: %ld\n", Q->size);
  printf("Begin: %ld\n", Q->begin);
  printf("End: %ld\n", Q->end);

  long s, i;

  for (s = 0, i = Q->begin; s < Q->size; s++, i = (i + 1) % Q->capacity) {
    printf("%d, ", Q->data[i]);
  }

  puts("");
}

// Teste

int main() {
  QueueStatic *Q = create(5);
  int val;

  printQueue(Q);
  puts("Enqueue: 10, 20, 30");
  enqueue(Q, 10);
  enqueue(Q, 20);
  enqueue(Q, 30);
  printQueue(Q);

  puts("\nPeek");
  val = peek(Q);
  printf("val = %d\n", val);
  printQueue(Q);

  puts("\nDequeue");
  val = denqueue(Q);
  printf("val = %d\n", val);
  printQueue(Q);

  puts("Enqueue: 40, 50");
  enqueue(Q, 40);
  enqueue(Q, 50);
  printQueue(Q);

  puts("\nDequeue");
  val = denqueue(Q);
  printf("val = %d\n", val);
  printQueue(Q);

  puts("Enqueue: 100, 200");
  enqueue(Q, 100);
  enqueue(Q, 200);
  printQueue(Q);

  puts("Enqueue: 99");
  enqueue(Q, 99);
  printQueue(Q);

  return 0;
}