/*
*   @author      : SRvSaha
*   Filename     : binary_search_recursive.cpp
*   Description  : Recursive Implementation of Binary Search
*
*/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int binary_search_recursive(int A[], int l, int r, int x)
{
    if(r >= l){
        int mid = l + (r-l)/2;
        if(A[mid] == x)
            return mid;
        else if(A[mid] < x){
            return binary_search_recursive(A,mid+1,r,x);
        }
        else{
            return binary_search_recursive(A,l,mid-1,x);
        }
    }
    return -1;
}
int main(){
    int A[MAX];
    int n, x;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for(int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    sort(A, A+n);
    printf("Sorted Array is : ");
    for(int i = 0; i < n; i++)
        printf("%d ",A[i]);
    printf("\n");
    printf("Enter the element to search : ");
    scanf("%d",&x);
    if(binary_search_recursive(A, 0, n-1, x) == -1){
        printf("Element not found\n");
    }
    else
        printf("Element found at index %d\n",binary_search_recursive(A,0,n-1,x));
    return 0;
}
