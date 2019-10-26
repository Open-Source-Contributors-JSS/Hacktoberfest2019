//Fibonnaci
#include <iostream>
using namespace std;

int Fibonnaci(int n){
	if(n==0||n==1){
		return n;
	}
	return Fibonnaci(n-1)+Fibonnaci(n-2);
}

int FibonnaciFast(int n, int *arr){
	if(n==0||n==1){
		arr[n] = n;
		return n;
	}
	if(arr[n]!=-1){
		return arr[n];
	}
	int ans = FibonnaciFast(n-1,arr)+FibonnaciFast(n-2,arr);
	arr[n] = ans;
	return ans;
}

int BottomUp(int n){
	int *arr = new int[n+1];
	//Initialization
	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		arr[i] = arr[i-1] + arr[i-2];
	}

	for (int i = 2; i <= n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return arr[n];
}

int main()
{
	int n;
	cin>>n;
	int arr[100000];
	for (int i = 0; i < 100000; ++i)
	{
		arr[i] = -1;
	}
	cout<<FibonnaciFast(n,arr)<<endl;
	cout<<BottomUp(n)<<endl;
	cout<<Fibonnaci(n)<<endl;

	return 0;
}