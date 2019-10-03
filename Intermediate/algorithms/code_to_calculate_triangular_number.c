#include<stdio.h>

int main(){
	int n,i;
	int tri=0;
	printf("Enter the number : ");
	scanf("%d",&n);
    for(i=1;i<=n;i++){
	tri+=i;
}
printf(" %d",tri);
return 0;
}
