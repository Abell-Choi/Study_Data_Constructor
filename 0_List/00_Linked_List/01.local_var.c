#include <stdio.h>
#include <stdlib.h>

// making struct
typedef struct Node {
  int data;
  struct Node *next; // pointing next node
} node;
void createNode(node *head, int data); // making node in last pos
void insertNode(node *head, int index, int data);
void deleteNode(node *head, int index);
void pushNode(node *head, int data);
void popNode(node *head);
void reverseNode(node *head);


void printingNode(node *head); // printing all list data
int getLastIndexNum(node *head);
int posSetter(int index, node *head);

int main() {
  node *head = malloc(sizeof(node));
  head->data = 0;
  head->next = NULL;
  for (int i = 1; i < 10; i++) {
    createNode(head, i);
  }
  reverseNode(head);
  printingNode(head);
}

void createNode(node *head, int data) {
  node *pos = head;
  while (pos->next != NULL) {
    pos = pos->next;
  }
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  tmp->next = NULL;
  pos->next = tmp;
}

void insertNode(node *head, int index, int data){
  index = posSetter(index, head);
  if (index == getLastIndexNum(head)){ 
    printf("last");
    return createNode(head, data); 
  }
  node *pos = head;
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  for (int i = index ; i > 0 ; i--){
    pos = pos -> next;
  }
  tmp->next = pos->next;
  pos->next = tmp;
  return;
}

void deleteNode(node *head, int index) {
  int lastIndexNum = posSetter(index, head);
  node *prev = NULL;
  node *pos = head;

  if (index == 0) {
    *head = *pos->next;
    return;
  }

  for (int i = index; i > 0; i--) {
    prev = pos;
    pos = pos->next;
  }

  prev->next = pos->next;
  return;
}

void pushNode(node *head, int data) { return createNode(head, data); }
void popNode(node *head) { return deleteNode(head, getLastIndexNum(head)); }

// WIP
void reverseNode(node *head){
  node *prev = NULL;
  node *next = head->next;

  while (head != NULL){
    head->next = prev;
    prev = head;
    head = next;
    next = next->next;
  }

  printingNode(head);
}


void printingNode(node *head) {
  printf("--[Printing Node]--\n");
  node *pos = head;
  for (int posNum = 0; pos != NULL; posNum++) {
    printf("loc [%d] -> %d \n", posNum, pos->data);
    pos = pos->next;
    if (posNum > 100) { break; }
  }
  printf("\n");
  return;
}

int getLastIndexNum(node *head) {
  node *pos = head;
  int position = -1;
  for (int i = 0; pos->next != NULL; i++) {
    pos = pos->next;
    position = i;
  }
  return position;
}

int posSetter(int index, node *head) {
  if (index < 0) {
    return 0;
  }
  if (index > getLastIndexNum(head)) {
    return getLastIndexNum(head);
  }
  return index;
}