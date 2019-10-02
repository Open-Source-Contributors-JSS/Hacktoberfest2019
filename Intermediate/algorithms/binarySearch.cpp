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
    int arr_length,num_to_search;
    cout<<"enter the number of elements"<<endl;
    cin>>arr_length;
    int arr[arr_length];
    cout<<"enter the elements in ascending order"<<endl;
    for(int i=0;i<arr_length;i++){
        cin>>arr[i];
    }
    cout<<"enter the number to search"<<endl;
    cin>>num_to_search;
    int result = binary_search(arr,arr_length,num_to_search);
    if(result==-1){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"key found at index: "<<result<<endl;
    }
}