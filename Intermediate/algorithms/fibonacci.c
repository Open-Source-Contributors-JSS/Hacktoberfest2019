#include <stdio.h>

int main () {
    int i,N,anterior=0,sucessor=1,presente;

    scanf("%d",&N);
    
    for (i=0; i<N; i++)
	{
	if(i<2)
		{
		
        printf("%d",i);

        if(i==0)
        printf(" ");

		else if (i==1)
		printf("");  
		}
	else
		{
		presente=anterior+sucessor;
		printf(" %d",presente);
		anterior=sucessor;
		sucessor=presente;
		
		
		
		}
	
	
	}
printf("\n");
        
return(0);	

}
