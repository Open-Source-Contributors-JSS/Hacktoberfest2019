#include<iostream>
#include<climits>
using namespace std;
int kadane(int a[],int n){
	int curr=0;
	int global=LONG_MIN;
	for(int i=0;i<n;i++){
		curr+=a[i];
//		for(int j=0;j<=i;j++){
//			if(a[j]>curr){
//				sum+=a[j];
//			}
//		}
		if(curr>global){
			global=curr;
		}
		if(curr<0){
			curr=0;
		}
	}
	return global;
}
int main(){
	cout<<"Enter the size of the array: ";
	int n=0;
	cin>>n;
	int a[100]={};
	cout<<"Enter the array Elements: ";
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"The maximum subarray sum of the array is "<<kadane(a,n);
}
