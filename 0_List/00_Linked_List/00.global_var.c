#include <stdio.h>
#include <stdlib.h>

//making struct
typedef struct Node {
  int data;
  struct Node *next;  // pointing next node
}node;
node *head;          // making head in globla

void createNode( int data );
void printNode();

int main() {
  if (head == NULL) { printf("asdf"); }
  // making first data
  int i = 0;
  while(i<10){
    createNode(i);
    i++;
  }
  printNode();
}

void printNode(){
  node *temp = head;
  printf("List : ");
  while (temp != NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void createNode( int data ){
  node *tmp = malloc(sizeof(node));
  tmp->data = data;
  tmp->next = head;
  head = tmp;
}