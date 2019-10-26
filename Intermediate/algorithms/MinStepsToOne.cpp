/* -----------------------MinStepsToOne-------------------------------
In this problem we are given a number n and then perform these three operations to make it one in minimum steps : 
1. Divide by 3 if it is.
2. Divide by 2 if it is.
3. Subtract one */
#include <iostream>
#include <climits>
using namespace std;

int topDown(int n,int *arr){
	if(n==1){
		arr[n] = 0;
		return 0;
	}

	if (arr[n]!=-1)
	{
		return arr[n];
	}

	int op1=INT_MAX,op2=INT_MAX,op3=INT_MAX;
	op1 = 1 + topDown(n-1,arr);
	if(n%2 == 0){
		op2 = 1 + topDown(n/2,arr);
	}
	if(n%3==0){
		op3 = 1 + topDown(n/3,arr);
	}

	arr[n] = min(op1,min(op2,op3));
	return arr[n];
}

int BottomUp(int n){
	int* a = new int[n+1];

	a[1] = 0;

	int op1,op2,op3;
	for (int i = 2; i <= n; ++i)
	{
		op1 = op2 = op3 = INT_MAX;
		if(i%3 == 0){
			op1 = a[i/3] + 1;
		}
		if(i%2==0){
			op2 = a[i/2] + 1;
		}
		op3 = a[i-1] + 1;

		a[i] = min(op1,min(op2,op3));

	}

	// for (int i = 0; i <= n; ++i)
	// {
	// 	cout<<a[i]<< " ";
	// }
	// cout<<endl;
	return a[n];
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
	cout<<topDown(n,arr)<<endl;
	cout<<BottomUp(n)<<endl;

	return 0;
}