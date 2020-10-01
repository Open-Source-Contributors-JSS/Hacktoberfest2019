#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

struct node
{
    int data;
    struct node* next;
};
int h[TABLE_SIZE]={NULL};

void insert()
{
    int key,hkey,index,i;
    printf("\nEnter the value to insert:");
    scanf("%d",&key);
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE;i++)
    {
        index=(hkey+i*i)%TABLE_SIZE;
        if(h[index]==NULL)
        {
            h[index]=key;
            break;
        }
    }
    if(i==TABLE_SIZE)
        printf("\nNo value can be inserted");
}

void search()
{
    int hkey,index,key,i;
    printf("\nEnter the value to search:");
    scanf("%d",&key);
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE;i++)
    {
        index=(hkey+i*i)%TABLE_SIZE;
        if(h[index]==key)
        {
            printf("\nSearched Found!");
            break;
        }
    }
    if(i==TABLE_SIZE)
        printf("\nValue is not Found!");
}


void display()
{
    int i;
    printf("\nElement in the Hash Table:");

    for(i=0;i<TABLE_SIZE;i++)
    {
        printf("\nAt index %d \t Value:%d",i,h[i]);
    }
}


int main()
{

    int choice;
    while(1)
    {
    printf("\n\tMENU DRIVEN");
    printf("\n1.Insertion");
    printf("\n2.Searching");
    printf("\n3.Display");
    printf("\n4.EXIT");

    printf("\n\nEnter the value:");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        insert();
        break;
    case 2:
        search();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\nINVALID CHOICE!");
    }

    }
    return 0;
}
