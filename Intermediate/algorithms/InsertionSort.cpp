## Hackerrank Insertion sort Problem1

## Problem Statement:
Given a sorted list with an unsorted number  in the rightmost cell, can you write some simple code to insert  into the array so that it remains sorted?

Since this is a learning exercise, it won't be the most efficient way of performing the insertion. It will instead demonstrate the brute-force method in detail.

Assume you are given the array  indexed . Store the value of . Now test lower index values successively from  to  until you reach a value that is lower than ,  in this case. Each time your test fails, copy the value at the lower index to the current index and print your array. When the next lower indexed value is smaller than , insert the stored value at the current index and print the entire array.

The results of operations on the example array is:

Starting array:  
Store the value of  Do the tests and print interim results:

1 2 4 5 5
1 2 4 4 5
1 2 3 4 5

## Input Format

There will be two lines of input:

The first line contains the integer , the size of the array 
The next line contains  space-separated integers 

## Constraints

 

## Output Format:

Print the array as a row of space-separated integers each time there is a shift or insertion.

## Sample Input:

5
2 4 6 8 3

## Sample Output:

2 4 6 8 8 
2 4 6 6 8 
2 4 4 6 8 
2 3 4 6 8 

## Explanation:

It is removed from the end of the array.
In the st line , so  is shifted one cell to the right. 
In the nd line , so  is shifted one cell to the right. 
In the rd line , so  is shifted one cell to the right. 
In the th line , so  is placed at position .


## Solution:

#include<iostream>
using namespace std;
void insertionSort(int n, int *a) {
 int temp,i,j,k;
    for(j=1;j<n;j++)
        {
        temp=a[j];
        i=j-1;
        while(i>=0&&a[i]>temp)
            {
            a[i+1]=a[i];
            i--;
              for(k=0;k<n;k++)
                  cout<<a[k]<<" ";
             cout<<endl;
        }
        a[i+1]=temp;
       
    }
      for(k=0;k<n;k++)
                  cout<<a[k]<<" ";
}
int main(void) {
    int n;
    cin>>n;
    int a[n], i;
    for(i = 0; i < n; i++) { 
        cin>>a[i]; 
    }

    insertionSort(n,a);
    return 0;
}
