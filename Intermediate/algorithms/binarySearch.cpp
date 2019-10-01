#include<iostream>
using namespace std;

int binary_search(int arr[],int arr_length,int key){
  int l=0,r=arr_length-1;
  while(l<=r){
      int mid = (l+r)/2;
      if(arr[mid]==key){
          return mid;
      }
      else if(arr[mid]>key){
          r=mid-1;
      }
      else{
          l=mid+1;
      }
  }
  return -1;
}

int main(){
    //requires arr to be sorted
    int arr[] = {1,2,3,4,6};
    int arr_length = 5;
    int num_to_search = 2;
    int result = binary_search(arr,arr_length,num_to_search);
    if(result==-1){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"key found at index: "<<result<<endl;
    }
}