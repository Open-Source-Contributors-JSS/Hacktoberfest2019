#include<stdio.h>

#define SIZE 10

int front = -1,rear = -1;
int queue[SIZE];

void initiateQ(){

  for(int i = 0;i<SIZE;i++){
    queue[i] = 0;
  }
}

void insertIntoQ(int val){

  if(rear == SIZE-1){
    printf("\nQueue is FULL!");
    return;
  }
  if(front == -1){
    front = 0;
  }
  rear++;
  queue[rear] = val;
}
void deleteQ(){
  if(front == -1){
    printf("\nQueue is empty");
    return;
  }
  queue[front] = 0;
  if(front == rear){
    front = -1;
    rear = -1;
    return;
  }
}

void displayQ(){

  for(int i = front; i<=rear;i++){
    printf("%d  ",queue[i]);
  }
}

void main(){

  initiateQ();
  insertIntoQ(21);
  insertIntoQ(54);
  displayQ();
  
}
