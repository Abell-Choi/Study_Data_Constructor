#include <stdio.h>
#include <stdlib.h>

// making struct
typedef struct Node {
  int data;
  struct Node *next; // pointing next node
} node;
node *head; // making head in globla

void createNode(int data); // add node (= <python> list.add)
void unshiftNode();
void shiftNode(int data);
void insertNode(int index, int data);
void deleteNode(int index);
void reverseNode();
void printingNode();
int getLength();
int getLastIndexNum();

void createSeq(int value) {
  for (int i = 0; i < value; i++) {
    createNode(i);
  }
  return;
}

int main() {
  head = NULL;
  createSeq(10);
  unshiftNode();
  printingNode();
  printf("\n%d", getLength());
}

// making node in last position
void createNode(int data) {
  // making node data
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  tmp->next = NULL;

  // no head data
  if (head == NULL) {
    head = tmp;
    return;
  }

  // head exists
  node *pos = head;
  while (pos->next != NULL) { // move last position
    pos = pos->next;
  }

  pos->next = tmp; // lastPosition -> Next = tmp;
  return;
}

void unshiftNode() {
  node *pos = head->next;
  free(head);
  head = pos;
}

void shiftNode(int data) { // insert node in first node
  node *tmp = malloc(sizeof(node));
  // no list data
  if (head == NULL) {
    return createNode(data);
  }

  tmp->data = data;
  tmp->next = head;
  head = tmp;
}

void insertNode(int index, int data) { // insert data next of index
  node *pos = head;
  while (pos->next != NULL && index > 0) {
    index--;
    pos = pos->next;
  }

  // last position
  if (pos->next == NULL) {
    return createNode(data);
  }

  // insert node
  node *tmp = malloc(sizeof(node));
  tmp->next = pos->next;
  tmp->data = data;
  pos->next = tmp;
  return;
}

void deleteNode(int index) {
  node *pos = head;
  if (index == 0) {
    return unshiftNode();
  }
  if (getLastIndexNum() < index) {
    index = getLastIndexNum();
  }

  while (index > 1) {
    pos = pos->next;
    index--;
  }
  node *target = pos->next;
  pos->next = target->next;
  free(target);
  return;
}

void reverseNode() {
  // making position grid (prev, pos, next)
  node *prev = NULL;
  node *pos = head;
  node *next = head->next;

  // pos == null -> last data;
  while (pos != NULL) {
    pos->next = prev;
    prev = pos;
    pos = next;
    next = next->next;
  }

  // null data is not node type,
  // but prev is node type;
  head = prev;
  return;
}

void printingNode() { // printing all node data
  node *pos = head;
  printf("Printing all nodes ->");
  while (pos != NULL) {
    printf("%d ", pos->data);
    pos = pos->next;
  }
  printf("\n");
  return;
}

int getLength() { // get lists node count
  node *pos = head;
  int stack = 0;
  while (pos != NULL) {
    pos = pos->next;
    stack++;
  }

  return stack;
}

int getLastIndexNum() // get lists index range
{
  return getLength() - 1;
}