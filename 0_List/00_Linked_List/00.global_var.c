#include <stdio.h>
#include <stdlib.h>

// making struct
typedef struct Node {
  int data;
  struct Node *next; // pointing next node
} node;
node *head; // making head in globla

void createNode(int data);
void printNode();
void insertNode(int location, int data);
int getNodeLength();

int main() {
  // if (head == NULL) { printf("asdf"); }
  // making default data
  for (int i = 0; i < 10; i++) {
    createNode(i);
  }

  // printing node
  printNode();
  int length = getNodeLength();
  printf("length : %d", length);
  // insertNode(1, 100);
}

// printing node function
void printNode() {
  node *temp = head;
  printf("List : ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// creating node function
void createNode(int data) {
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  tmp->next = head;
  head = tmp;
}

// 재사용성
int getNodeLength() {
  node *temp = head;
  int i = -1;
  while (temp != NULL) {
    i++;
    temp = temp->next;
    printf("console i check -> %d\n", i);
  }

  return i + 1;
}
