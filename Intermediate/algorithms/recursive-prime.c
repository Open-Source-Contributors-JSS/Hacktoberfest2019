#include <stdio.h>
int isprime(int i)
{
    if(i==1 || i==0)
    return 0;
    int c=0;
    for(int j=2;j<=i/2;j++)
    {
        if(i%j==0)
        c++;
    }
    if(c==0)
    return 1;
    else
    return 0;
}
void prime(int n,int i)
{
    if(i>n)
    return 0;
    if(n%i==0 && isprime(i))
    printf("%d ",i);
    prime(n,i+1);
}

int main()
{
    int n,i=2,k=2;scanf("%d",&n);
    prime(n,i);
}
