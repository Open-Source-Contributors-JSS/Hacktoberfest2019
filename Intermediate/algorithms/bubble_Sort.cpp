#include<iostream>
using namespace std;
int main()
{
	int arr[5] = {7,4,6,2,10};
	int temp;
	for(int i=0;i<5;i++)
	{
		if(arr[i+1] > arr[i])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
    }
    for(int i=0;i<5;i++)
	{
		cout<<arr[i] << " ";
    }
}
