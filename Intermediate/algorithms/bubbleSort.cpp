#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int arr[], int n)
{
    for(int i=1;i<n;i++)         // n-1 number of external passes
    {
        bool flag = false;
        for(int j=0;j<(n-i);j++)
         {
            if(arr[j]>arr[j+1])
            {
              swap(&arr[j],&arr[j+1]);
              flag = true;
            }
        }
        if(!flag)
            break;
    }
}
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
    int *arr = new int[n];
    cout << "Enter the size of array: ";
    cin >> n;
    cout<<"\n Enter the "<<n<<" elements of the array \n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << " Input array is: ";
    display(arr,n);
    sort(arr,n);
    cout << "\n The sorted array is : ";
    display(arr,n); 
    return 0;
}