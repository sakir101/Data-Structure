#include <stdio.h>
#include <stdlib.h>
// Creating a node
struct node {
  int value;
  struct node *next;
};
// print the linked list value
void printLinkedlist(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}
void printLinkedlistinsert(struct node *p) {
     printf("\n");
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}
void printLinkedlistdelet(struct node *p) {
    printf("\n");
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
}
int main() {
  // Initialize nodes
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;
  // Allocate memory
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;
  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;
  head=one;
printLinkedlist(head);
  // Connect 1st
struct node *newNode;
newNode = malloc(sizeof(struct node));
newNode->value = 4;
newNode->next = one;
head = newNode;
// Connect middle
struct node *newNode2;
newNode2 = malloc(sizeof(struct node));
int val = 5;
//printf("enter value");
//scanf("%d",&val);
newNode2->value = val;
struct node *temp = head;
int pos=3;
//printf("enter position");
//scanf("%d",&pos);
for(int i=1; i < pos-1; i++) {
    if(temp->next != NULL) {
        temp = temp->next;
    }
}
newNode2->next = temp->next;
temp->next = newNode2;


// Connect last
struct node *newNode1;
newNode1 = malloc(sizeof(struct node));
newNode1->value = 6;
newNode1->next = NULL;
struct node *temp3 = head;
while(temp3->next != NULL){
  temp3 = temp3->next;
}
temp3->next = newNode1;

 printLinkedlistinsert(head);
//dld last
struct node* temp4 = head;
while(temp4->next->next!=NULL){
  temp4 = temp4->next;
}
temp4->next = NULL;
//dld middle
struct node* temp5 = head;
int posi=3;
for(int i=2; i< posi; i++) {
    if(temp5->next!=NULL) {
        temp5 = temp5->next;
    }
}
temp5->next = temp5->next->next;
//dld last
head = head->next;
// printing node-value
printLinkedlistdelet(head);
}



