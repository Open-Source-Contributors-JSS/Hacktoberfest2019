#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * printLinkedList(struct Node * head)
{
    struct Node * ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != NULL);
    return head;
}
struct Node * printReverseLinkedList(struct Node * head1)
{
    struct Node * ptr = head1;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr !=NULL);
    return head1;
}
int main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * secondNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * thirdNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourthNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * head1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * secondNode1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * thirdNode1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourthNode1 = (struct Node *)malloc(sizeof(struct Node));
    //Simple Linked List
    head->data = 5;
    head->next = secondNode;

    secondNode->data = 15;
    secondNode->next = thirdNode;

    thirdNode->data = 25;
    thirdNode->next = fourthNode;

    fourthNode->data = 50;
    fourthNode->next = NULL;

    head = printLinkedList(head);
    printf("\n");
    //Reversed Linked List
    head1->data = 5;
    head1->next = NULL;

    secondNode1->data = 15;
    secondNode1->next = head1;

    thirdNode1->data = 25;
    thirdNode1->next = secondNode1;

    fourthNode1->data = 50;
    fourthNode1->next = thirdNode1;

    head1 = printReverseLinkedList(fourthNode1);
    return 0;
}