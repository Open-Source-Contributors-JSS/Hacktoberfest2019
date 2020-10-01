//This program will tell how to evaluate sum of n natural numbers in 0(1) time.

#include <stdio.h>

int main() {
int num, sum = 0;
printf ("Enter the last natural number you want the sum of: ");
//Sum = 1+2+3.....n
scanf("%d", &num);
for (int i = 0; i<=num; i++)
{
    sum +=i;
}
printf ("Sum of first %d natural numbers is : %d\n", num, sum);
return 0;
}
