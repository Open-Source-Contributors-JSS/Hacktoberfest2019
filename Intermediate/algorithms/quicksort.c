// C program to implement QuickSort
#include<stdio.h> 

void swap(int* a, int* b) 
{  
	*a = *a + *b; 
	*b = *a - *b;
	*a = *a - *b;
} 

int partition (int array[], int low, int high) 
{ 
	int pivot = array[high]; 
	int i = (low - 1);  

	for (int j = low; j <= high- 1; j++) 
	{ 
		if (array[j] <= pivot) 
		{ 
			i++;  
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&array[i + 1], &array[high]); 
	return (i + 1); 
} 

void quickSort(int array[], int low, int high) 
{ 
	if (low < high) 
	{ 
		
		int pi = partition(array, low, high); 

		quickSort(array, low, pi - 1); 
		quickSort(array, pi + 1, high); 
	} 
} 

void printArray(int array[], int size) 
{ 
	for (int i=0; i<size; i++) 
	printf("%d ",&array[i]); 
	printf(n); 
} 


int main() 
{ 
	int array[10],n=10;
	printf("Enter elements: /n ");
	for( int i=0;i<10;i++)
	scanf("%d",&array[i]);
	quickSort(array, 0, n-1); 
	printf("Sorted array: n"); 
printArray(array, n); 
	return 0; 
} 
