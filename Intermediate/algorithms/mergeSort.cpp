#include<iostream>
#include<algorithm>
using namespace std;
void myMerge(int a[],int p, int q, int r)
{
    int i=0,j=0,k=0;
    int n1=q-p+1;
    int n2=r-q;
    int *l=NULL;
    l=new int[n1];
    int *R=NULL;
    R=new int[n2];
    int z=1;

    /*copying first half of the array into a new one*/
    for(i=p;i<=q;i++)
    {
        l[z]=a[i];
        z++;
    }
    z=1;

    /*copying second half of the array into another array*/
    for(i=q+1;i<=r;i++)
    {
        R[z]=a[i];
        z++;
    }
    i=1;j=1;
    k=p;

    /*comparing the two new array halves and storing the result back into original one*/
    while(i!=n1+1 && j!=n2+1)
    {
        if(l[i]<=R[j])
        {
            a[k]=l[i];
            i++;
            k++;
        }
        else{
            a[k]=R[j];
            j++;
            k++;
            }
    }

    /*used in case one array half is larger than the other*/

    /*used if l array finishes but R remains*/
     if(i>=n1+1)
      {
        for(int x=k;x<=n1+n2;x++)
        {
          a[x]=R[j];
          j++;
        }
      }
      else if(j>=n2+1)  /* used if R finishes and l remains, so simply copying elements of l into original array*/
      {
        for(int x=k;x<=n1+n2;x++)
        {
        a[x]=l[i];
        i++;
        }
      }

}
void mergeSort(int a[],int p, int r)
{
    if(p>=r)
        return;
    int q=0;

    /* finding the center of the array*/
    if(p<r)
        q=(p+r)/2;

    /*calling mergesort on two halves of the array and then merging them back into one sorted array*/
    mergeSort(a,p,q);
    mergeSort(a,q+1,r);
    myMerge(a,p,q,r);

}
int main()
{
    int *a=NULL;
    int n=0;
    cout<<"Enter the number of elements MS"<<endl;
    cin>>n;
    a=new int[n];
    /* taking input of the array */
    cout<<"Enter the elements of the array"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    /*calling mergesort function on the array*/
    mergeSort(a,1,n);

    /*printing the sorted array*/
    cout<<"The sorted array is"<<endl;
    for(int j=1;j<=n;j++)
    {
        cout<<a[j]<<" ";
    }
    return 0;
}
