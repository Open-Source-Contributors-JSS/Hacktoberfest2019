// LongestCommonSubsequence
#include <iostream>
#include <string.h>
using namespace std;

int LCS(char *a,char *b){
	int dp[10][10] = {0};

	int cols = strlen(a);
	int rows = strlen(b);
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			if(a[j-1] == b[i-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for (int i = 0; i <= rows; ++i)
	{
		for(int j = 0; j <= cols; j++){
			cout<<dp[i][j]<< " ";
		}
		cout<<endl;
	}
	return dp[rows][cols];
}

int main()
{
	char a[] = "abegh";
	char b[] = "beh";

	cout<<LCS(a,b)<<endl;

	return 0;
}