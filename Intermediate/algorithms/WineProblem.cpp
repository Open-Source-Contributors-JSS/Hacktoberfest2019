// WineProblem
#include <iostream>
using namespace std;

int topDown(int *wine, int i,int j,int day,int a[][100]){
	if(i>j){
		a[i][j] = 0;
		return 0;
	}

	if(a[i][j] != -1){
		return a[i][j];
	}

	int op1 = wine[i]*day + topDown(wine,i+1,j,day+1,a);
	int op2 = wine[j]*day + topDown(wine,i,j-1,day+1,a);
	a[i][j]=max(op1,op2);
	return a[i][j];
}

int Bottomup(int *wine, int n){
	int dp[100][100] = {0};
	int day = n;
	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = day*wine[i];
	}
	day--;
	for(int len = 2;len<=n;len++){
		int starti = 0;
		int endi = n - len;
		int i = 0;
		while(i<=endi){
			int j = i+len-1;
			int op1 = wine[i]*day + dp[i+1][j];
			int op2 = wine[j]*day + dp[i][j-1];
			dp[i][j] = max(op1,op2);
			i++;
		}
		day--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[0][n-1];

}

int main()
{
	int arr[100][100];
	for (int i = 0; i < 100; ++i)
	{
		for(int j = 0; j < 100; ++j){
			arr[i][j] = -1;
		}
	}

	int wine[] = {2,3,5,1,4};
	int n = sizeof(wine)/sizeof(int);

	cout<<topDown(wine,0,n-1,1,arr)<<endl;
	cout<<Bottomup(wine,n)<<endl;
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	return 0;
}