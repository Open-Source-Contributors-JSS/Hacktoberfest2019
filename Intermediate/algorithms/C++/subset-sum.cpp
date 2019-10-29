#include <bits/stdc++.h>
using namespace std;
bool subset_sum(int arr[], int n, int sum){
    bool dp[n+1][sum+1];
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int j=1; j<=sum; j++){
        dp[0][j] = false;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(dp[i-1][j]==true){
                dp[i][j] = true;
            }
            else{
                if(j-arr[i] < 0){
                    dp[i][j] = false;
                }
                else{
                    dp[i][j] = dp[i-1][j-arr[i]];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    return dp[n][sum];
}

int main(){
    cout<<"Enter the no of elements in the array: ";
    int n;  cin>>n;
    cout<<"\nEnter the array: ";
    int arr[n+1];  
    arr[0] = INT_MIN;  
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    cout<<"\nEnter th sum you want to check for: ";
    int sum;    cin>>sum;
    sort(arr, arr+n);
    bool result = subset_sum(arr, n, sum);
    cout<<"\nPossible : "<<result<<endl;
    return 0;
}
