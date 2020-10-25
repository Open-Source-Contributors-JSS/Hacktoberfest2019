#include<stdio.h>
int toBin(int);
int main()
{
    int dno;
    printf(" Input any decimal number : ");
    scanf("%d",&dno);
    toBin(dno);
    return 0;
}
int toBin(int dno)
{
    int i=0,j,bno[32];
    while(dno>0)
    {
	    bno[i]=dno%2;
	    dno=dno/2;
	    i++;
    }
    printf("\n The Binary value is ");
    for(j=i-1;j>0;j--)
    {
         printf("d",bno[j]);
    }
}
