#include<iostream>
using nasmespace std;

void main()
{   clrscr();
	int n, temp, ar[10];
	cout<<"Enter the number of elements : ";
	cin>>n;

	cout<<"\nEnter the elements : \n";

	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}

	cout<<"\nUnsorted Array : \n";

	for(int a=0;a<n;a++)
	{
		cout<<ar[a]<<" ";
	}


	for(int j=1;j<=n-1;j++)
	{
	       int var=ar[j];
	       int k=j-1;

		while((var<ar[k])&&(k>=0))
		{
			ar[k+1]=ar[k];
			k--;
		}
		ar[k+1]=var;
	}

	cout<<"\nSorted Array : \n";

	for(int p=0;p<n;p++)
	{
		cout<<ar[p]<<" ";
	}
	  getch();
}