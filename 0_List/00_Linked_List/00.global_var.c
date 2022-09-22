#include <stdio.h>
#include <stdlib.h>

// making struct
typedef struct Node {
  int data;
  struct Node *next; // pointing next node
} node;
node *head; // making head in globla

void createNode(int data);               // add node (= <python> list.add)
void insertNode(int location, int data); // insert node in next input location
int getNodeLength();                     // get list nodes length
node getNodeIndexData(int index);
void printNode(); // printing all nodes data

int main() {
  // if (head == NULL) { printf("asdf"); }
  // making default data
  for (int i = 0; i < 10; i++) {
    createNode(i);
  }

  // printing node
  printNode();
  int length = getNodeLength();
  getNodeIndexData(0);
  // insertNode(1, 100);
}

// creating node function <in python List.add()>
void createNode(int data) {
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  tmp->next = head;
  head = tmp;
}

// (wip) insert node in next input location
void insertNode(int location, int data) {
  node *moveTemp = malloc(sizeof(node));
  moveTemp->data = data;
  moveTemp->next = NULL;
}

// custom utility functions

int getNodeLength() { // return global linked list length
  node *temp = head;
  int i = 0;
  while (temp != NULL) {
    i++;
    temp = temp->next;
    // printf("console i check -> %d\n", i);
  }
  printf("max length -> %d \n", i);
  return i;
}

node getNodeIndexData(int index) {
  // 최대 길이 확인
  int max_length = getNodeLength();
  // max_length <= index) 이면 최대 길이로 지정
  if (max_length <= index) {
    index = max_length - 1;
  }
  if (index < 0) {
    index = 0;
  }

  node *moveTemp = head;
  while (index > 0) {
    index--;
    moveTemp = moveTemp->next;
  }
  printf("Data -> %d", moveTemp->data);
  return *moveTemp;
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