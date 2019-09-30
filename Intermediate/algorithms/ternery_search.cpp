#include<bits/stdc++.h>

using namespace std;

int ternery_search(int arr[],int f,int l,int key)
{
	
	while(f<=l)
	{
		int mid1 = f + (l - f)/3;
		int mid2 = l - (l - f)/3;
		
		if(key == arr[mid1])
			return mid1;
		if(key == arr[mid2])
			return mid2;
		if(key < arr[mid1])
			l = mid1 - 1;
		else if(key > arr[mid2])
			f = mid2 + 1;
		else
		{
			f = mid1 + 1;
			l = mid2 - 1;  
		}
	}
	return -1;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int pos = ternery_search(arr,0,9,11);
	if(pos != -1)
		cout<<"Found at position = "<<pos<<endl;
	else
		cout<<"Not found"<<endl;
	return 0;
}