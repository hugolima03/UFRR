// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Criando estrutura
struct Queue {
  int front, back, size;
  unsigned capacity;
  int* array;
};

// construtores e destrutores
struct Queue* createQueue(unsigned capacity) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;

  queue->back = capacity - 1;
  queue->array = (int*)malloc(queue->capacity * sizeof(int));
  return queue;
}

void destroy(struct Queue** queue) {
  struct Queue* Q = *queue;
  free(Q->array);
  free(Q);
  *queue = NULL;
}

// Funções

int isFull(struct Queue* queue) { return (queue->size == queue->capacity); }

int isEmpty(struct Queue* queue) { return (queue->size == 0); }

void enqueue(struct Queue* queue, int item) {
  if (isFull(queue)) return;
  queue->back = (queue->back + 1) % queue->capacity;
  queue->array[queue->back] = item;
  queue->size = queue->size + 1;
  printf("%d Entrou na fila\n", item);
}

int dequeue(struct Queue* queue) {
  if (isEmpty(queue)) return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;
  return item;
}

int peek(struct Queue* queue) {
  if (isEmpty(queue)) return INT_MIN;
  return queue->array[queue->front];
}

int peekBack(struct Queue* queue) {
  if (isEmpty(queue)) return INT_MIN;
  return queue->array[queue->back];
}

void printQueue(struct Queue* queue) {
  printf("Capacity: %d\n", queue->capacity);
  printf("Size: %d\n", queue->size);
  printf("Front Element: %d\n", queue->array[queue->front]);
  printf("Back Element: %d\n", queue->array[queue->back]);
  printf("Front Index: %d\n", queue->front);
  printf("Back Index: %d\n", queue->back);

  long s, i;

  puts("");

  for (s = 0, i = queue->front; s < queue->size; s++, i = (i + 1) % queue->capacity) {
    printf("%d, ", queue->array[i]);
  }

  puts("");
}

// TESTES

int main() {
  struct Queue* queue = createQueue(1000);

  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);

  printf("%d Saiu da fila\n\n", dequeue(queue));

  printf("Peek: %d\n", peek(queue));
  printf("back: %d\n\n", peekBack(queue));

  printQueue(queue);

  destroy(&queue);

  return 0;
}
