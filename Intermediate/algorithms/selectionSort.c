void selectionSort(int arr[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        int minI = i;
        for (int j=i+1; j<size; j++)
        {
            if (arr[j] < arr[minI])
            {
                minI = j;
            }
        }
        int swap = arr[minI];
        arr[minI] = arr[i];
        arr[i] = swap;
    }
}
