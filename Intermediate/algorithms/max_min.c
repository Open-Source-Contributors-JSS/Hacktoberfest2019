#include <stdio.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int min(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int maximum(int arr[], int lb, int ub)
{
	if(lb==ub)
		return arr[lb];
	else{
		int mid = (lb+ub)/2;
		return (max(maximum(arr, lb, mid), maximum(arr,mid+1, ub)));
	}
}

int minimum(int arr[], int lb, int ub)
{
	if(lb==ub)
		return arr[lb];
	int mid = (lb+ub)/2;
	return min(minimum(arr, lb, mid), minimum(arr,mid+1, ub));
}

int main()
{
	int n = 6;
	int arr[] = {10,200,100,-50,0,550};
	printf("The maximum element in the array is %d\n", maximum(arr, 0, n-1));
	printf("The minimum element in the array is %d\n", minimum(arr, 0, n-1));	
	return 0;
}
