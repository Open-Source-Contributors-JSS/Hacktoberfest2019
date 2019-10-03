#include<iostream>
#include<algorithm>
using namespace std;

/* this function returns the partition index to the quicksort function*/
int partitionMy(int a[],int p,int r)
{
   int x=a[r]; /* this is the pivot element,in this case it is the last one */
   int i=p-1;
   int j=0;

   /* this brings all smaller elements to the left of the pivot
      and larger elements to the right of the pivot*/

   for(j=p;j<=r-1;j++)
   {
       if(a[j]<=x)
       {
           i++;
           swap(a[j],a[i]);

       }

   }
   swap(a[i+1],a[r]);
   return i+1;

}
void quickSort(int a[],int p,int r)
{
    /* we recursively call quicksort on the two parts of the array
       after receiving the partition from partitionMy function*/

    if(p<r){
        int q=partitionMy(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }

}
int main()
{
    int *a=NULL;
    int n=0,i,j=0;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    a=new int[n];
    /* taking input of the array */

    cout<<"Enter the elements of an array"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    /* quicksort function for sorting the array*/

    quickSort(a,1,n);
    cout<<"The sorted array is: "<<endl;

    /*printing the array after sorting */

    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
    cin.ignore();
}
