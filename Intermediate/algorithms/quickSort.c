void swap(int * x, int * y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int * arr, int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;

    for(int i=start; i<end; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(&arr[i], &arr[pIndex]);
            pIndex++;
        }
    }
    swap(&arr[end], &arr[pIndex]);
    return pIndex;
}

void quickSort(int * arr, int start, int end)
{
    if(start < end)
    {
        int pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}
