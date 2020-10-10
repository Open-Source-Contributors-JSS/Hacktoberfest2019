#include<stdio.h>
int main()
{
    int n,k;
    printf("ENTER THE NUMBER OF NUMBERS WHICH U WANT TO SORT : ");
    scanf("%d",&n);
    printf("ENTER THE NUMBER OF DIGITS OF THE NUMBER : ");
    scanf("%d",&k);
    int arr[n];
    int B[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int b=1;
    while(k--)
    {
        int count[10];
        for(int i=0;i<10;i++)
            count[i]=0;
        for(int i=0;i<n;i++)
            count[ (arr[i]/b) %10 ]++;
        for(int i=1;i<10;i++)
            count[i] += count[i-1];
        for(int i=n-1;i>=0;i--)
            B[--count[ (arr[i]/b) %10 ]]=arr[i];
        for(int i=0;i<n;i++)
            arr[i]=B[i];
        b=10;
    }
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}