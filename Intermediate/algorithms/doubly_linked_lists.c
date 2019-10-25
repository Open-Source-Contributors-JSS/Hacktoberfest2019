#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node *next;
  struct node *prev;
};
struct node *start;

void createHead(int n){

  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = n;
  temp->next = NULL;
  temp->prev = NULL;
  start = temp;
}

void addAtBegin(int n){
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = n;
  temp->prev = NULL;
  temp->next = start;
  start->prev = temp;
  start = temp;
}

void addFromEnd(int n){

  struct node *temp, *x;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->prev = start;
  temp->next  = NULL;
  temp->data = n;;
  x = start;
  while(x->next != NULL){
    x = x->next;
  }
  x->next = temp;
}

void displayList(){
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp = start;
  while(temp != NULL){
    printf("%d  ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void main(){

  int i,head,val,noHead,noEnd,headVal,endVal;
  printf("Enter a head value: ");
  scanf("%d",&head);
  createHead(head);
  printf("\nEnter number of values you want to add at begin: ");
  scanf("%d",&noHead);

  for(i=0;i<noHead;i++){
    printf("\nEnter head val %d: ",i+1);
    scanf("%d",&headVal);
    addAtBegin(headVal);
  }

  printf("\nHead Values Entered!");
  printf("\n\nEnter number of values you want to add at end: ");
  scanf("%d",&noEnd);

  for(i=0;i<noEnd;i++){
    printf("\nEnter end val %d: ",i+1);
    scanf("%d",&endVal);
    addFromEnd(endVal);
  }
  printf("\nEnd Values Entered!");
  printf("\n\nThe populated list is: ");
  displayList();
}
