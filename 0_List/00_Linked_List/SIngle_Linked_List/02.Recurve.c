#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *ptr;
} typedef node;

node *insert(node *p, int data) {
  if (p == NULL) {
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->ptr = NULL;

    return newNode;
  }

  p->ptr = insert(p->ptr, data);
  return p;
}

void print(node *p) {
  if (p == NULL) {
    return;
  }
  printf("%d ", p->data);
  print(p->ptr);
}

void reversePrint(node *p) {
  if (p == NULL) {
    return;
  }
  reversePrint(p->ptr);
  printf("%d ", p->data);
  return;
}

node* reverse(node *p) {
  if (p->ptr == NULL) {
    return p;
  }
  node *r = reverse(p->ptr);
  node *q = p->ptr;
  q->ptr = p;
  p->ptr = NULL;
  return r;
}

int main() {
  node *head = NULL;
  for (int i = 0; i < 10; i++) {
    head = insert(head, i);
  }
  head = reverse(head);

  print(head);
}
