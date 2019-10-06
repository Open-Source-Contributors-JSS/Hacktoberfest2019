#include<bits/stdc++.h>

using namespace std;

void merge(int arr[],int p,int q,int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1+1],R[n2+1];
	for(int i=0;i<n1;i++)
	{
		L[i] = arr[p+i];
	}
	for(int i=0;i<n2;i++)
	{
		R[i] = arr[q+i+1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;

	int i=0,j=0;
	for(int k=p;k<=r;k++)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
}
void merge_sort(int arr[],int p,int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
int main()
{
	int arr[] = {56,9,45,38,97,13,4,67,109,22};
	for(auto x : arr)
		cout<<x<<" ";
	cout<<endl;
	merge_sort(arr,0,9);
	for(auto x : arr)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}