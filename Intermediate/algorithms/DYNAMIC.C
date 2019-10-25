#include<stdio.h>
#include<stdlib.h>

int main()
{
int *ptr;
int limit;
int i;
int sum;
clrscr();
printf("Enter limit of the array:");
scanf("%d",&limit);

//declare memory dynamically
ptr=(int*)malloc(limit*sizeof(int));

//read array elements
for(i=0;i<limit;i++)
{
printf("Enter element %02d:",i+1);
scanf("%d",(ptr+i));
}
//calculate sum of all elements
sum=0;
for(i=0;i<limit;i++)
{
sum+=*(ptr+i);
}
printf("Sum of array elements is %d\n",sum);
free(ptr);
getch();
return 0;
}
