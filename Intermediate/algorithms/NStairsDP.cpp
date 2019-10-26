// N_StairsDP
#include <iostream>
using namespace std;
int NStairs(int n,int k,int *a){
	if(n==0){
		a[n] = 1;
		return 1;
	}

	if(n<0){
		return 0;
	}

	if(a[n] != -1){
		return a[n];
	}
	
	int sum = 0;
	for(int i=1;i<=k;i++){
		sum += NStairs(n-i,k,a);
	}

	a[n] = sum;

	return sum;
}

int BottomUp(int n,int k){
	int dp[1000] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		// int sum = 0;
		for (int j = 1; j <= k; ++j)
		{
			if(i-j>=0)
			dp[i] += dp[i-j];
		}
		// dp[i] = sum;
	}
	
	return dp[n];
}
int BottomUpFast(int n,int k){ //Sliding Window 
	int dp[100000] = {0};
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if(i-k-1 >= 0){
			dp[i] = dp[i-1]*2 - dp[i-k-1];
		}
		else{
			dp[i] = dp[i-1]*2;
		}
	}
	return dp[n];
}
int main(int argc, char const *argv[])
{
	/* code */
	int n,k;
	cin>>n>>k;
	int a[100000];
	for (int i = 0; i < 100000; ++i)
	{
		a[i] = -1;
	}
	cout<<NStairs(n,k,a)<<endl;
	cout<<BottomUp(n,k)<<endl;
	cout<<BottomUpFast(n,k)<<endl;
	for (int i = 0; i <= n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}