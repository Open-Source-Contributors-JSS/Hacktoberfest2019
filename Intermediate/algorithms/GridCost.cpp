// GridCost
#include <iostream>
using namespace std;

int topDown(int i,int j,int cost[][10],int dp[][10]){
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	if(i==0 && j==0){
		dp[i][j] = cost[0][0];
		return cost[0][0];
	}
	else if(i==0 && j>0){
		dp[i][j] = cost[i][j] + topDown(i,j-1,cost,dp);
		return dp[i][j];
	}
	else if(j==0 && i>0){
		dp[i][j]=cost[i][j] + topDown(i-1,j,cost,dp);
		return dp[i][j];
	}
	else{
		int op1 = cost[i][j] + topDown(i-1,j,cost,dp);
		int op2 = cost[i][j] + topDown(i,j-1,cost,dp);
		dp[i][j] = min(op1,op2);
		return dp[i][j];
	}
}

int BottomUp(int n,int m,int cost[][10]){
	int dp[10][10] = {0};
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = dp[i-1][0] + cost[i-1][0];
	}
	for(int j = 1;j<m;j++){
		dp[0][j] = dp[0][j-1] + cost[0][j-1];
	}
	for (int i = 1; i < n; ++i)
	{
		for(int j = 1; j< m;j++){
			int op1 = dp[i-1][j];
			int op2 = dp[i][j-1];
			dp[i][j] = cost[i][j] + min(op1,op2);
		}
	}
	return dp[n][m];
}

int main()
{
	int cost[10][10] = {
		{1,1,5,3},
		{6,1,1,2},
		{3,8,1,0},
		{1,1,1,0}
	};
	int dp[10][10];
	for (int i = 0; i < 10; ++i)
	{
		for(int j = 0; j<10;j++){
			dp[i][j] = -1;
		}
	}
	int i,j;
	cin>>i>>j;
	cout<<topDown(i,j,cost,dp)<<endl;
	cout<<BottomUp(i,j,cost)<<endl;
	return 0;
}