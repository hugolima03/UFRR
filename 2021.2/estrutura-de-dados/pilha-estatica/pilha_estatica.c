/*
  -- Implementação de uma pilha estática (Static Stack)
  -- Autor: Hugo Lima
  -- Data: 22/02/2022
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Estrutura

typedef struct _stack {
  long capacity;
  long top;
  int *data;
} Stack;

// Construtor e destrutor

Stack *Stack_create(long capacity) {
  Stack *S = (Stack *)malloc(sizeof(Stack));
  S->capacity = capacity;
  S->top = -1;
  S->data = malloc(capacity * sizeof(int));
  return S;
}

void Stack_destroy(Stack **S_ref) {
  Stack *S = *S_ref;
  free(S->data);
  free(S);
  *S_ref = NULL;
}

// Funções

bool Stack_is_empty(Stack *S) { return S->top == -1; }

bool Stack_is_full(Stack *S) { return S->top == S->capacity - 1; }

void Stack_push(Stack *S, int val) {
  if (Stack_is_full(S)) {
    printf("Stack is full\n");
  } else {
    S->top++;
    S->data[S->top] = val;
  }
}

int Stack_peek(Stack *S) {
  if (Stack_is_empty(S)) {
    printf("Stack is empty\n");
  } else {
    return S->data[S->top];
  }
}

int Stack_pop(Stack *S) {
  if (Stack_is_empty(S)) {
    printf("Stack is empty\n");
  } else {
    int val = S->data[S->top];
    S->top--;
    return val;
  }
}

void Stack_print(Stack *S) {
  printf("Capacity: %ld\n", S->capacity);
  printf("Top: %ld\n", S->top);
  printf("Size: %ld\n", S->top + 1);

  for (long i = 0; i <= S->top; i++) {
    printf("%d, ", S->data[i]);
  }

  puts("");
}

// Testes
int main() {
  Stack *S = Stack_create(5);
  int top_val = 0;

  Stack_print(S);

  // puts("\nPeeking");
  // top_val = Stack_peek(S);
  // printf("top_val = %d\n", top_val);

  // puts("\nPopping");
  // top_val = Stack_pop(S);
  // printf("top_val = %d\n", top_val);

  puts("\nPushing: 0, 10, 20");
  Stack_push(S, 0);
  Stack_push(S, 10);
  Stack_push(S, 20);
  Stack_print(S);

  puts("\nPeeking");
  top_val = Stack_peek(S);
  printf("top_val = %d\n", top_val);

  puts("\nPopping");
  top_val = Stack_pop(S);
  printf("top_val = %d\n", top_val);

  puts("\nPushing: 30, 40, 500");
  Stack_push(S, 30);
  Stack_push(S, 40);
  Stack_push(S, 50);
  Stack_print(S);

  puts("\nPushing: 60");
  Stack_push(S, 60);
  Stack_print(S);

  return 0;
}