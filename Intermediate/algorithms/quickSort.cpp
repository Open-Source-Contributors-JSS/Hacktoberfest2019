#include<iostream>
#include<algorithm>
using namespace std;
int partitionMy(int a[],int p,int r)
{
   int x=a[r];
   int i=p-1;
   int j=0;
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
    cout<<"Enter the elements of an array"<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    quickSort(a,1,n);
    cout<<"The sorted array is: "<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
    cin.ignore();
}
