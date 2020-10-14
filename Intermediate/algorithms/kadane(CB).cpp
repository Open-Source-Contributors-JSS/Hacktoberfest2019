#include<iostream>
using namespace std;
int main(){
int arr[100] = {-7,1,-4,5,1,-3,11};
int n = 7;
int max = INT_MIN;
int currMax = 0;
for(int i=0;i<n;i++){
    currMax+=arr[i];
    if(currMax<0){
        currMax = 0;
    }
    if(currMax>max){
        max = currMax;
    }
}
cout<<max<<endl;
}

