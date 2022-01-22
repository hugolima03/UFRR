#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _node Node;
typedef struct _linked_list LinkedList;
Node *Node_create(int val);
LinkedList *LinkedList_create();
void LinkedList_add_first(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_print(LinkedList *L);

#endif