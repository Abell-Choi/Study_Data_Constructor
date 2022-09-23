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
void deleteNode(int index);
int getNodeLength();                     // get list nodes length
node getNodeIndexData(int index);
void printNode(); // printing all nodes data

int main() {
}

// creating node function <in python List.add()>
void createNode(int data) {
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  tmp->next = head;
  head = tmp;
}

void insertNode(int index, int data){
  //making head pos
  node *tmp = head;
  printf("head - %d\n" , head->data);    // Debug
  node *nodeData = malloc(sizeof(node)); // making new node 
  if (index == 0){                       // 0 = prev
    nodeData -> data = data;             // insert front data
    nodeData -> next = head;
    head = nodeData;                     // head = nodeData
  }

  for (int i = 0 ; i < index-1 ; i++){   // move to target prev
    tmp = tmp->next;
  }
  nodeData -> data = data;               // make node 
  nodeData -> next = tmp->next;          // next = target
  tmp->next = nodeData;                  // target -1 = nodeData
  return;
}

//delete node
void deleteNode(int index){
  node *tmp = head;  // making head pos
  if (index == 0){   // delete prev
    head = tmp -> next;
    free(tmp);
    return;
  }

  // move to target prev point
  for (int i = 0 ; i < index-1 ; i++){
    tmp = tmp -> next;
  }

  // tmp1 = target-1 -> next = target pos
  // tmp->next = target +2 pos
  node* tmp1 = tmp->next;
  tmp->next = tmp1->next;

  // 대상 포인터 메모리 프리
  free(tmp1);
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
  // printf("Data -> %d", moveTemp->data);
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