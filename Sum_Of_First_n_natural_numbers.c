//This program will tell how to evaluate sum of n natural numbers in 0(1) time.

#include <stdio.h>

int main() 
{
int n, sum = 0;
printf ("Enter the number: ");
//Sum = 1+2+3.....n
scanf("%d", &n);
for (int i = 0; i<=n; i++)
{
    sum +=i;
}
printf ("Sum of first %d natural numbers is : %d\n", n, sum);
return 0;
}
