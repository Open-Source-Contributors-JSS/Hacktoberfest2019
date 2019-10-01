#include<stdio.h>
#include<stdlib.h>
int main()
{   
    /*Creating Node*/
    struct Node
    {
        int data;
        struct Node *next;
    };
    /*Function to traverse the Linked List */
    void Traverse(struct Node *n)
    {
        while (n!=NULL)
        {
            printf("%d ",n->data);
            n = n->next;

        }
    }
    /*created three nodes and stored data in it*/

    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = NULL;
    /*running the traverse function */
    Traverse(head);

    return 0;
}
