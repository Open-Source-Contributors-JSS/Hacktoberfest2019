#include <stdio.h>
#include <conio.h>
#define MAXSIZE 5

struct stack /* Structure definition for stack */
{
int stk[MAXSIZE];
int top;
};

typedef struct stack STACK;
STACK s;

/* Function declaration/Prototype*/

void push (void);
int pop(void);
void display (void);
int isEmpty(void);
int isFull(void);
int getSize(void);

int main ()
{
int choice;
int option = 1;



s.top = -1;

printf ("STACK OPERATION\n");
while (option)
{
printf ("------------------------------------------\n");
printf (" 1 --> PUSH \n");
printf (" 2 --> POP \n");
printf (" 3 --> DISPLAY \n");
printf (" 4 --> EMPTY \n");
printf (" 5 --> FULL \n");
printf (" 6 --> SIZE \n");
printf (" 7 --> EXIT \n");
printf ("------------------------------------------\n");

printf ("Enter your choice\n");
scanf ("%d", &choice);

switch (choice)
{
case 1: push();
break;
case 2: pop();
break;
case 3: display();
break;
case 4: isEmpty();
break;
case 5: isFull();
break;
case 6: getSize();
break;
case 7: return;
}

fflush (stdin);
printf ("Do you want to continue(Type 0 or 1)?\n");
scanf ("%d", &option);
}
return 0;
}

/*Function to add an element to the stack*/
void push ()
{
int num;
if (s.top == (MAXSIZE - 1))
{
printf ("Stack is Full\n");
return;
}
else
{
printf ("Enter the element to be pushed\n");
scanf ("%d", &num);
s.top = s.top + 1;
s.stk[s.top] = num;
}
return;
}

/*Function to delete an element from the stack*/
int pop ()
{
int num;
if (s.top == - 1)
{
printf ("Stack is Empty\n");
return (s.top);
}
else
{
num = s.stk[s.top];
printf ("poped element is = %d\n", s.stk[s.top]);
s.top = s.top - 1;
}
return(num);
}

/*Function to display the status of the stack*/
void display ()
{
int i;
if (s.top == -1)
{
printf ("Stack is empty\n");
return;
}
else
{
printf ("\nThe status of the stack is\n");
for (i = s.top; i >= 0; i--)
{
printf ("%d\n", s.stk[i]);
}
}
printf ("\n");
}
/*Function to check stack is empty or not*/
int isEmpty()
{
        if(s.top == -1)
                printf("Stack is Empty \n");
        else
                printf("Stack is not Empty \n");
}
/*Function to check stack is full or not*/
int isFull()
{
        if(s.top == MAXSIZE-1)
                printf("Stack is full \n");
        else
               printf("Stack is not full \n");
}
/*Function to check the size of the stack*/
int getSize()
{
	if(s.top == -1)
	  printf("Stack is Empty \n");
	else
	  printf("Stack size is: %d\n",s.top+1);
}
