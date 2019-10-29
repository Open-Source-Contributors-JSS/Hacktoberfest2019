#include<stdio.h>

int partition(int a[],int p,int r)
{
	int x=a[r];
	int i=p-1;
	int j,temp;
	for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return (i+1);
}


void quicksort(int a[],int p,int r)
{
	if(p<r)
	{
		int q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

//Initial call is quicksort(a,0,n-1)
