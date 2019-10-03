// Program for merge sort
//Ahmad Javed

#include<bits/stdc++.h>

using namespace std;

void mergeArray(int arr[], int low, int mid, int high)
{
    int m = mid - low + 1;
    int n = high - mid;
    int leftArr[m];
    int rightArr[n];

    for(int i = 0;i < m;i++)
    {
        leftArr[i] = arr[low + i];
    }

    for(int j = 0;j < n;j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while(i < m && j < n)
    {
        if(leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while(i < m)
    {
        arr[k++] = leftArr[i++];
    }

    while(j < n)
    {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = low + (high - low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        mergeArray(arr,low,mid,high);
    }
}

void printArray(int arr[], int len)
{
    for(int i = 0;i < len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int len;
    cout<<"Enter length of array: ";
    cin>>len;
    int arr[len];
    cout<<"Enter array elements:"<<endl;
    for(int i = 0;i<len;i++)
    {
        cin>>arr[i];
    }

    mergeSort(arr,0,len);
    cout<<"Merged array is:"<<endl;
    printArray(arr, len);
    return 0;
}
