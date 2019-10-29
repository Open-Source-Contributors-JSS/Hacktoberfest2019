#include<bits/stdc++.h>

using namespace std;

int heapsize = 0;

void max_heapify(int arr[],int i)
{
	int largest;
	if((2*i)+1 < heapsize && arr[(2*i)+1] > arr[i])
		largest = (2*i) + 1;
	else
		largest = i;
	if((2*i)+2 < heapsize && arr[(2*i)+2] > arr[largest])
		largest = (2*i) + 2;
	if(largest != i)
	{
		swap(arr[largest],arr[i]);
		max_heapify(arr,largest);
	}
}

void build_max_heap(int arr[])
{
	int n = heapsize;
	for(int i=(n-2)/2;i>=0;i--)
	{
		max_heapify(arr,i);
	}
}

void heapsort(int arr[])
{
	build_max_heap(arr);
	for(int i=heapsize-1;i>=1;i--)
	{
		swap(arr[i],arr[0]);
		heapsize--;
		max_heapify(arr,0);
	}
}
int main()
{
	int arr[] = {45,89,34,12,78,4,90,1,27,16};
	heapsize = 10;
	for(auto x : arr)
		cout<<x<<" ";
	cout<<endl;
	heapsort(arr);
	for(auto x : arr)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}