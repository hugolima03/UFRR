#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Assinaturas e definição de estruturas

typedef struct NodeTag {
  char *data;
  struct NodeTag *next;
} Node;

Node *Node_create();
void Node_destroy(Node *node);

typedef struct ListTag {
  struct NodeTag *first;
} List;

List *List_create();
void List_destroy(List *list);

void List_append(List *list, char *str);
void List_insert(List *list, int index, char *str);

int List_find(List *list, char *str);

int List_length(List *list);
void List_print(List *list);

// Testes
int main() {
  List *l = List_create(); // Criando lista encadeada simples

  // RECEBE LINHA 1
  char line1[100];
  fgets(line1, 100, stdin);
  line1[strcspn(line1, "\n")] = 0;  // Remove as quebras de linha do fgets

  char delim[] = " "; // Separador da função strtok
  char nao[] = "nao"; // Comparar com a linha 3

  char *ptr1 = strtok(line1, delim); // Realizar o split da linha 1
  while (ptr1 != NULL) {
    List_append(l, ptr1);
    ptr1 = strtok(NULL, delim);
  }

  // RECEBE LINHA 2
  char line2[100];
  fgets(line2, 100, stdin);
  line2[strcspn(line2, "\n")] = 0; // Remove as quebras de linha do fgets

  // RECEBE LINHA 3
  char line3[20];
  scanf("%s", line3);

  char *ptr2 = strtok(line2, delim); // Split da linha 2
  // se a linha3 é igual a "nao"
  if (!strcmp(line3, nao)) { // Caso a linha 3 seja "nao"
    while (ptr2 != NULL) {
      List_append(l, ptr2); // Adiciona todos os elementos no final
      ptr2 = strtok(NULL, delim);
    }
  } else { // Caso a linha 3 tenha um ponto de inserção
    while (ptr2 != NULL) {
      int i = List_find(l, line3); // Busca o índice da lista que é igual a linha 3
      List_insert(l, i, ptr2); // Insere na lista
      ptr2 = strtok(NULL, delim);
    }
  }

  List_print(l);

  List_destroy(l);

  return 0;
}

// Implementação das funções 

Node *Node_create() {
  Node *node = malloc(sizeof(Node));
  assert(node != NULL);

  node->data = "";
  node->next = NULL;

  return node;
}

void Node_destroy(Node *node) {
  assert(node != NULL);
  free(node);
}

List *List_create() {
  List *list = malloc(sizeof(List));
  assert(list != NULL);

  Node *node = Node_create();
  list->first = node;

  return list;
}

void List_destroy(List *list) {
  assert(list != NULL);

  Node *node = list->first;
  Node *next;
  while (node != NULL) {
    next = node->next;
    free(node);
    node = next;
  }

  free(list);
}

void List_append(List *list, char *str) {
  assert(list != NULL); // O método assert garante a condição, se for falsa ele encerra o programa
  assert(str != NULL);

  Node *node = list->first;
  while (node->next != NULL) {
    node = node->next;
  }

  node->data = str;
  node->next = Node_create();
}

void List_insert(List *list, int index, char *str) {
  // O método assert garante a condição, se for falsa ele encerra o programa
  // faz parte do #include <assert.h>
  assert(list != NULL);
  assert(str != NULL);
  // assert(0 <= index); Estava gerando erro no compilador do URI.
  assert(index <= List_length(list));

  if (index == 0) { // Caso seja para adicionar no inicio
    Node *after = list->first;
    list->first = Node_create();
    list->first->data = str;
    list->first->next = after;
  } else if (index == List_length(list)) { // Caso seja para adicionar no final
    List_append(list, str);
  } else { // Caso seja para adicionar no meio
    Node *before = list->first; // Ponteiro do primeiro
    Node *after = list->first->next; // Ponteiro do segundo
    while (index > 1) { // Percorre elementos até chegar no index 
      index--;
      before = before->next;
      after = after->next;
    }
    before->next = Node_create(); // Inserção do novo node na lista
    before->next->data = str; // Atualizando valor do novo node
    before->next->next = after; // O Next do novo node é o after
  }
}

int List_find(List *list, char *str) {
  assert(list != NULL);
  assert(str != NULL);

  int index = 0;
  Node *node = list->first;
  while (node->next != NULL) { // Percorre a lista
    if (strlen(str) == strlen(node->data)) { // Comparação do tamanho dos elementos
      int cmp = strcmp(str, node->data); // Comparação das strings

      if (cmp == 0) { // Caso sejam iguais
        return index; // Retorna a posição do elemento na lista
      }
    }
    node = node->next;
    index++;
  }
  return -1; // Retorna -1 caso não encontre
}

int List_length(List *list) {
  assert(list != NULL);

  Node *node = list->first;
  int length = 0;
  while (node->next != NULL) {
    length++;
    node = node->next;
  }

  return length;
}

void List_print(List *list) {
  assert(list != NULL);

  Node *node = list->first;
  while (node->next != NULL) {
    printf("%s", node->data);
    node = node->next;
    if (node->next != NULL) {
      printf(" ");
    }
  }
  printf("\n");
}