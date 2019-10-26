/* --------------------------------CurrencyExchange-------------------------
You are given an amount and currency array of coins you find minimum coins to fill this amount*/

#include <iostream>
#include <climits>
using namespace std;

int topDown(int n,int *coins,int coins_size,int *arr){
	//Base case
	if(n == 0){
		arr[n] = 0;
	}
	if(arr[n]!= -1){
		return arr[n];
	}
	//Recursive case
	int ans = INT_MAX;
	for (int i = 0; i < coins_size; ++i)
	{
		if(n-coins[i]>=0){
			int smallerAns = topDown(n-coins[i],coins,coins_size,arr);
			if(smallerAns!=INT_MAX){
				ans = min(ans,smallerAns + 1);
			}
		}
	}
	arr[n] = ans;
	return ans;
}

int BottomUp(int n,int *coins,int coins_size){
	int* a = new int[n+1];
	a[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		a[i] = INT_MAX;
	}

	for(int rupay = 1;rupay <= n;rupay++){
		for (int i = 0; i < n; ++i)
		{
			if(rupay-coins[i] >= 0){
				a[rupay] = min(a[rupay],a[rupay-coins[i]]+1);
			}
		}
	}
	for (int i = 0; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return a[n];
}

int main()
{
	int n;
	cin>>n;
	int arr[100000],coins[] = {1,7,10};
	for (int i = 0; i < 100000; ++i)
	{
		arr[i] = -1;
	}
	int coins_size = sizeof(coins)/sizeof(int);
	cout<<topDown(n,coins,coins_size,arr)<<endl;
	cout<<BottomUp(n,coins,coins_size)<<endl;
	for (int i = 0; i <= n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}